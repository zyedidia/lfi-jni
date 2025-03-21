#include "Hello.h"
#include <iostream>
#include <stdio.h>

JNIEXPORT void JNICALL
Java_Hello_sayHello(JNIEnv* env, jobject thisObject)
{
    std::cout << "Hello from C++ !!" << std::endl;
}
