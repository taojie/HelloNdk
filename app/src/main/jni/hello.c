#include <stdio.h>
#include <jni.h>
#include <string.h>

JNIEXPORT jstring JNICALL Java_koala_hellondk_MainActivity_getStringFromNative
  (JNIEnv *env, jclass thiz){

  return (*env)->NewStringUTF(env, "Hello from JNI !!!!!");
  }