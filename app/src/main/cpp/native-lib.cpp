#include <jni.h>
#include <string>
#include <omp.h>
#include <sys/times.h>
#include "f2c.h"


static double firstcall = 0.0;

void Genera_Mat(double *Mat, int filas, int columnas, int seed) {
        int
                i=0;

        long int
                distribucion_tipo=2,
                distribucion_elem=0,
                iseed[4];

        distribucion_elem=seed % 4095;

        if ((distribucion_elem % 2) == 0) distribucion_elem++;

        iseed[0]=iseed[1]=iseed[2]=iseed[3]=distribucion_elem;

        distribucion_elem=columnas;

        for (i=0; i<filas; i++)
                Dlarnv(&distribucion_tipo, iseed, &distribucion_elem, &Mat[i*columnas]);
}

int Ctimer(double *elapsed, double *ucpu, double *scpu, int reset)
{
        struct timeval tm;
        struct timezone tz;
        struct tms sistema;
        double usegs;

        gettimeofday(&tm, &tz);
        times(&sistema);

        usegs = tm.tv_usec+tm.tv_sec*1E6;

        if (reset == 0) firstcall=0.0;

        if (firstcall>0.0)
                *elapsed = usegs - firstcall;
        else
        {
                *elapsed = 0;
                firstcall = usegs;
        }

        *elapsed = *elapsed/1E6;
        *ucpu = (double)sistema.tms_utime/(double)CLOCKS_PER_SEC*1E4;
        *scpu = (double)sistema.tms_stime/(double)CLOCKS_PER_SEC*1E4;

        return 0;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_uniovi_es_computacionparalela_MainActivity_multiplicacionSecuencial(JNIEnv *env,
                                                                         jobject instance,
                                                                         jint dimA, jint dimB,
                                                                         jint dimC) {

        int
                Fil_A, Fil_B, Fil_C,
                Col_A, Col_B, Col_C, i, j, r;

        double
                *MatA = NULL,
                *MatB = NULL,
                *MatC = NULL,
                elapsed, ucpu, scpu;

        Fil_C = Fil_A = dimA;
        Col_C = Col_B = dimB;
        Fil_B = Col_A = dimC;

        /* Comprobando que ninguna dimension es nula */
        if ((Fil_A == 0) || (Col_A == 0) || (Col_B == 0)) {
                //return env->NewStringUTF("Error 1: Alguna dimension es nula.\n");
                return 0;
        }

        /* Comprobando que las dimensiones de A y B son compatibles */
        if (Col_A != Fil_B) {
                //return env->NewStringUTF("Error 2: El numero de Columnas de A y el numero de Filas de B no coinciden.\n");
                return 0;
        }

        MatA = (double *) malloc(Fil_A * Col_A * sizeof(double));
        if (MatA == NULL) {
                //return env->NewStringUTF("Error 3: Problemas reservando memoria para la Matriz A.\n");
                return 0;
        }

        MatB = (double *) malloc(Fil_B * Col_B * sizeof(double));
        if (MatB == NULL) {
                free(MatA);
                MatA = NULL;
                return 0;
                //return env->NewStringUTF("Error 4: Problemas reservando memoria para la Matriz B.\n");
        }

        MatC = (double *) calloc(Fil_C * Col_C, sizeof(double));
        if (MatC == NULL) {
                free(MatA);
                MatA = NULL;
                free(MatB);
                MatB = NULL;
                return 0;
                //return env->NewStringUTF("Error 6: Problemas reservando memoria para la Matriz C de Naive.\n");
        }

        Genera_Mat(MatA, Fil_A, Col_A, 2121);
        Genera_Mat(MatB, Fil_B, Col_B, 2032);


        Ctimer(&elapsed, &ucpu, &scpu, 0);

        for (i = 0; i < Fil_A; i++)
                for (j = 0; j < Col_B; j++)
                        for (r = 0; r < Fil_B; r++)
                                MatC[i * Col_B + j] = MatC[i * Col_B + j] +
                                                      MatA[i * Col_A + r] * MatB[j * Col_B + r];

        Ctimer(&elapsed, &ucpu, &scpu, 1);


        free(MatA);
        MatA = NULL;
        free(MatB);
        MatB = NULL;
        free(MatC);
        MatC = NULL;

        return elapsed;

}

extern "C"
JNIEXPORT jdouble JNICALL
Java_uniovi_es_computacionparalela_MainActivity_multiplicacionOpenMP(JNIEnv *env, jobject instance,
                                                                     jint dimA, jint dimB,
                                                                     jint dimC) {

        int
                Fil_A, Fil_B, Fil_C,
                Col_A, Col_B, Col_C, i, j, r;

        double
                *MatA = NULL,
                *MatB = NULL,
                *MatC = NULL,
                elapsed, ucpu, scpu;


        Fil_C = Fil_A = dimA;
        Col_C = Col_B = dimB;
        Fil_B = Col_A = dimC;

        /* Comprobando que ninguna dimension es nula */
        if ((Fil_A == 0) || (Col_A == 0) || (Col_B == 0)) {
                //return env->NewStringUTF("Error 1: Alguna dimension es nula.\n");
                return 0;
        }

        /* Comprobando que las dimensiones de A y B son compatibles */
        if (Col_A != Fil_B) {
                //return env->NewStringUTF("Error 2: El numero de Columnas de A y el numero de Filas de B no coinciden.\n");
                return 0;
        }

        MatA = (double *) malloc(Fil_A * Col_A * sizeof(double));
        if (MatA == NULL) {
                //return env->NewStringUTF("Error 3: Problemas reservando memoria para la Matriz A.\n");
                return 0;
        }

        MatB = (double *) malloc(Fil_B * Col_B * sizeof(double));
        if (MatB == NULL) {
                free(MatA);
                MatA = NULL;
                return 0;
                //return env->NewStringUTF("Error 4: Problemas reservando memoria para la Matriz B.\n");
        }

        MatC = (double *) calloc(Fil_C * Col_C, sizeof(double));
        if (MatC == NULL) {
                free(MatA);
                MatA = NULL;
                free(MatB);
                MatB = NULL;
                return 0;
                //return env->NewStringUTF("Error 6: Problemas reservando memoria para la Matriz C de Naive.\n");
        }

        Genera_Mat(MatA, Fil_A, Col_A, 2121);
        Genera_Mat(MatB, Fil_B, Col_B, 2032);

        omp_set_dynamic(1);
        omp_set_nested(1);

        Ctimer(&elapsed, &ucpu, &scpu, 0);

        #pragma omp parallel for
        for (i = 0; i < Fil_A; i++)
                for (j = 0; j < Col_B; j++)
                        for (r = 0; r < Fil_B; r++)
                                MatC[i * Col_B + j] = MatC[i * Col_B + j] +
                                                      MatA[i * Col_A + r] * MatB[j * Col_B + r];

        Ctimer(&elapsed, &ucpu, &scpu, 1);


        free(MatA);
        MatA = NULL;
        free(MatB);
        MatB = NULL;
        free(MatC);
        MatC = NULL;

        return (jdouble)elapsed ;

}



