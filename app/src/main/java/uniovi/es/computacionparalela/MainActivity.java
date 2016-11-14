package uniovi.es.computacionparalela;

import android.app.ProgressDialog;
import android.content.Context;
import android.os.AsyncTask;
import android.os.PowerManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    ProgressDialog dialog;
    TextView tvTiempos;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Numero de procesadores
        int numCores=Runtime.getRuntime().availableProcessors();

        TextView tvCores= (TextView) findViewById(R.id.tvCores);
        tvCores.setText("El dispositivo dispone de "+numCores+" núcleos.");
        final CheckBox cbSecuencial= (CheckBox) findViewById(R.id.cbSecuencial);
        final EditText etDimension= (EditText) findViewById(R.id.etDimension);

        Button realizarOperacion = (Button) findViewById(R.id.btWork);
        realizarOperacion.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(!etDimension.getText().toString().isEmpty()){
                    int dimension=Integer.parseInt(etDimension.getText().toString());

                    //Secuencial
                    if(cbSecuencial.isChecked()) {
                        dialog.setMessage("Calculando secuencial");
                        dialog.show();
                        new CalculaTiemposSecuencial().execute(dimension);
                    }
                    //OpenMP
                    else{
                        dialog.setMessage("Calculando con OpenMP");
                        dialog.show();
                        new CalculaTiemposOpenMp().execute(dimension);
                    }
                }
            }
        });

        dialog=new ProgressDialog(this);
        dialog.setCancelable(false);
        dialog.setInverseBackgroundForced(false);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        tvTiempos=(TextView) findViewById(R.id.sample_text);

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native double multiplicacionOpenMP(int dimA,int dimB, int dimC);
    public native double multiplicacionSecuencial(int dimA,int dimB, int dimC);

    private class CalculaTiemposOpenMp extends AsyncTask<Integer, Void, Double> {

        @Override
        protected Double doInBackground(Integer... integers) {
                return multiplicacionOpenMP(integers[0],integers[0],integers[0]);
        }

        @Override
        protected void onPostExecute(Double aDouble) {
            dialog.hide();
            if (aDouble == -4 || aDouble == -3 || aDouble == -5)
                tvTiempos.setText("No se ha podido reservar la memoria necesaria");
            else
                tvTiempos.setText("Tiempo OpenMP: "+aDouble+" segundos.");
            super.onPostExecute(aDouble);

        }
    }

    private class CalculaTiemposSecuencial extends AsyncTask<Integer, Void, Double> {

        @Override
        protected Double doInBackground(Integer... integers) {
            return multiplicacionSecuencial(integers[0],integers[0],integers[0]);
        }

        @Override
        protected void onPostExecute(Double aDouble) {
            dialog.hide();
            if (aDouble == -4 || aDouble == -3 || aDouble == -5)
                tvTiempos.setText("No se ha podido reservar la memoria necesaria");
            else
                tvTiempos.setText("Tiempo Secuencial: "+aDouble+" segundos.");
            super.onPostExecute(aDouble);

        }
    }
}
