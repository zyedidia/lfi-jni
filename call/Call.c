#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include "Call.h"

static void callback(JNIEnv* env, jobject obj, jmethodID mid) {
    (*env)->CallVoidMethod(env, obj, mid, 42);
}

static void callbackA(JNIEnv* env, jobject obj, jmethodID mid) {
    jvalue* args = malloc(sizeof(jvalue));
    args[0].i = 42;
    (*env)->CallVoidMethodA(env, obj, mid, args);
    free(args);
}

static void callbackV(JNIEnv* env, jobject obj, jmethodID mid, ...) {
    va_list args;
    va_start(args, mid);
    (*env)->CallVoidMethodV(env, obj, mid, args);
    va_end(args);
}

JNIEXPORT void JNICALL Java_Call_nativeMethod(JNIEnv *env, jobject obj) {
    // Get the class reference
    jclass cls = (*env)->GetObjectClass(env, obj);
    
    // Get the method ID for "javaMethod"
    jmethodID mid = (*env)->GetMethodID(env, cls, "javaMethod", "(I)V");
    
    if (mid == NULL) {
        printf("Method not found!\n");
        return;
    }

    callback(env, obj, mid);
    callbackA(env, obj, mid);
    callbackV(env, obj, mid, 42);
}

JNIEXPORT void JNICALL Java_Call_hello(JNIEnv *env, jobject obj) {
    printf("Hello!\n");
}
