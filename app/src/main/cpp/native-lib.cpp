#include <jni.h>
#include <string>
#include <omp.h>

extern "C"
jstring
Java_uniovi_es_computacionparalela_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

        std::string hello = "Hola mundo "+om();
        return env->NewStringUTF(hello.c_str());
}


