package uniovi.es.computacionparalela;

import android.app.ProgressDialog;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AutoCompleteTextView;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Numero de procesadores
        int numCores=Runtime.getRuntime().availableProcessors();

        TextView tvCores= (TextView) findViewById(R.id.tvCores);
        tvCores.setText("Hay "+numCores+" núcleos.");

        final CheckBox cbAsync= (CheckBox) findViewById(R.id.cbAsynctask);
        final EditText etDimension= (EditText) findViewById(R.id.etDimension);

        Button realizarOperacion = (Button) findViewById(R.id.btWork);
        realizarOperacion.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(!etDimension.getText().toString().isEmpty()){
                    int dimension=Integer.parseInt(etDimension.getText().toString());
                    if(!cbAsync.isChecked())
                        operar(dimension);
                }
            }
        });

    }

    private void operar(int dimension){
        TextView tv = (TextView) findViewById(R.id.sample_text);
//        ProgressDialog dialog=new ProgressDialog(this);
//        dialog.setMessage("Calculando con OpenMP");
//        dialog.setCancelable(false);
//        dialog.setInverseBackgroundForced(false);
//        dialog.show();

        double tiempoOpenMP=multiplicacionOpenMP(dimension,dimension,dimension);
        //dialog.setMessage("Calculando de forma secuencial");
        double tiempoSecuencial=multiplicacionSecuencial(dimension,dimension,dimension);

        //dialog.hide();

        tv.setText("Tiempo OpenMP: "+tiempoOpenMP+" Tiempo secuencial: "+tiempoSecuencial);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native double multiplicacionOpenMP(int dimA,int dimB, int dimC);
    public native double multiplicacionSecuencial(int dimA,int dimB, int dimC);

    private class CalculaTiemposOpenMp extends AsyncTask<Integer,Void,Long>{

        @Override
        protected Long doInBackground(Integer... integers) {
            if(integers.length==0) {
                multiplicacionOpenMP(integers[0],integers[0],integers[0]);
            }
            return null;
        }

        @Override
        protected void onPostExecute(Long aLong) {
            super.onPostExecute(aLong);
        }
    }
}
