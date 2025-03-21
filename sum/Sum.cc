#include "Sum.h"

JNIEXPORT jint JNICALL
Java_Sum_sum(JNIEnv* env, jobject obj, jintArray arr)
{
    int i, sum = 0;
    jsize len = env->GetArrayLength(arr);
    jint* body = env->GetIntArrayElements(arr, 0);
    for (i = 0; i < len; i++)
        sum += body[i];
    env->ReleaseIntArrayElements(arr, body, 0);
    return sum;
}
