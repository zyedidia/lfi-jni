#include <jni.h>
#include <lz4.h>
#include <stdlib.h>
#include <string.h>

JNIEXPORT jbyteArray JNICALL Java_LZ4Compressor_compress(JNIEnv *env, jobject obj, jbyteArray input) {
    jsize inputLength = (*env)->GetArrayLength(env, input);
    jbyte *inputBytes = (*env)->GetByteArrayElements(env, input, NULL);

    int maxCompressedSize = LZ4_compressBound(inputLength);
    jbyte *compressedBytes = (jbyte *)malloc(maxCompressedSize);

    int compressedSize = LZ4_compress_default((char *)inputBytes, (char *)compressedBytes, inputLength, maxCompressedSize);
    
    if (compressedSize <= 0) {
        free(compressedBytes);
        return NULL; // Compression failed
    }

    jbyteArray output = (*env)->NewByteArray(env, compressedSize);
    (*env)->SetByteArrayRegion(env, output, 0, compressedSize, compressedBytes);
    
    free(compressedBytes);
    (*env)->ReleaseByteArrayElements(env, input, inputBytes, JNI_ABORT);
    
    return output;
}

JNIEXPORT jbyteArray JNICALL Java_LZ4Compressor_decompress(JNIEnv *env, jobject obj, jbyteArray compressed, jint originalSize) {
    jsize compressedLength = (*env)->GetArrayLength(env, compressed);
    jbyte *compressedBytes = (*env)->GetByteArrayElements(env, compressed, NULL);

    jbyte *decompressedBytes = (jbyte *)malloc(originalSize);

    int decompressedSize = LZ4_decompress_safe((char *)compressedBytes, (char *)decompressedBytes, compressedLength, originalSize);

    if (decompressedSize < 0) {
        free(decompressedBytes);
        return NULL; // Decompression failed
    }

    jbyteArray output = (*env)->NewByteArray(env, decompressedSize);
    (*env)->SetByteArrayRegion(env, output, 0, decompressedSize, decompressedBytes);
    
    free(decompressedBytes);
    (*env)->ReleaseByteArrayElements(env, compressed, compressedBytes, JNI_ABORT);
    
    return output;
}
