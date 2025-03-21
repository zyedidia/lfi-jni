#include "Hello.h"
#include <stdio.h>

JNIEXPORT void JNICALL
Java_Hello_sayHello(JNIEnv* env, jobject thisObject)
{
    jint version = (*env)->GetVersion(env);
    printf("version: %d\n", version);
}
