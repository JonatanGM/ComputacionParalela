package uniovi.es.computacionparalela;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
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

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        double tiempoOpenMP=multiplicacionOpenMP(1000,1000,1000);
        double tiempoSecuencial=multiplicacionSecuencial(1000,1000,1000);

        tv.setText("Tiempo OpenMP: "+tiempoOpenMP+" Tiempo secuencial: "+tiempoSecuencial);

        //Numero de procesadores
        int numCores=Runtime.getRuntime().availableProcessors();

        TextView tvCores= (TextView) findViewById(R.id.tvCores);
        tvCores.setText("Hay "+numCores+" núcleos.");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native double multiplicacionOpenMP(int dimA,int dimB, int dimC);
    public native double multiplicacionSecuencial(int dimA,int dimB, int dimC);
}
