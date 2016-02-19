#include <stdio.h>
#include <jni.h>
#include <string.h>
#include <android/log.h>
#include <stdlib.h>
#define TAG "HelloNdk"
#define LOGV(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

JNIEXPORT jstring JNICALL Java_koala_hellondk_MainActivity_getStringFromNative
  (JNIEnv *env, jclass thiz){
  LOGV("my log");
  return (*env)->NewStringUTF(env, "Hello from JNI !!!!! ddd");
  }

  JNIEXPORT void JNICALL Java_koala_hellondk_MainActivity_updateFile
    (JNIEnv *env, jclass jclass, jstring path){
         const char* file_path = (*env)->GetStringUTFChars(env,path,NULL);
         if(file_path != NULL){
           LOGV("file path is %s",file_path);
         }
         FILE* file = fopen(file_path,"a+");
         if(file != NULL){
         LOGV("open file success");
         }
         char data[] = "I am a girl";
          fwrite(data,strlen(data),1,file);
            LOGV("write file success");
            if(file != NULL){
            fclose(file);
            }

         (*env)->ReleaseStringUTFChars(env,path,file_path);
    }

    JNIEXPORT jintArray JNICALL Java_koala_hellondk_MainActivity_updateIntArray
      (JNIEnv *env, jclass thiz, jintArray array){

       /*  jint nativeArray[5];
         (*env)->GetIntArrayRegion(env,array,0,5,nativeArray);
         int j;
         for(j=0;j<5;j++){
            nativeArray[j] += 5;
            LOGV("i = %d", nativeArray[j]);
         }
         (*env)->SetIntArrayRegion(env,array,0,5,nativeArray); */

         jint* data = (*env)->GetIntArrayElements(env,array,NULL);
         jsize len = (*env)->GetArrayLength(env,array);

         int j;
         for(j=0;j<len;j++){
             data[j] += 3;
             LOGV("j = %d", data[j]);
         }

         //ÊÍ·ÅÖ¸Õë
         (*env)->ReleaseIntArrayElements(env,array,data,0);
         return array;
      }