#include <jni.h>
#include <string>
#include "helper.h"

using namespace Helper;

extern "C"
JNIEXPORT jstring JNICALL Java_com_ericcode_jnidemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++.";
    std::string helperHello = Helper::hello(env);
    hello = hello + helperHello;
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_ericcode_jnidemo_MainActivity_helloJNI(JNIEnv *env, jobject instance) {

    std::string hello = "Hello JNI";
    const char *classname = "com/ericcode/jnidemo/MainActivity";
    jclass dpclazz = (env)->FindClass(classname);

    jmethodID jmethodID1 = env->GetStaticMethodID(dpclazz, "calledByC", "(I)Ljava/lang/String;");
    jint jint1 = 1;
    jstring jstring1 = static_cast<jstring>(env->CallStaticObjectMethod(dpclazz, jmethodID1,
                                                                        jint1));

    jmethodID jmethodID2 = env->GetMethodID(dpclazz, "called2ByC", "(I)Ljava/lang/String;");
    jstring jstring2 = static_cast<jstring>(env->CallObjectMethod(instance, jmethodID2, jint1));

    return jstring2;
}
