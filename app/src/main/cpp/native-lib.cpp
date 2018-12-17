#include <jni.h>
#include <string>
#include <android/log.h>


#define TAG "rexih"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型

extern "C"
JNIEXPORT jint JNICALL
Java_cn_rexih_android_testnativeinterface_MainActivity_testNativeApi(JNIEnv *env, jobject instance, jobject entity) {

    if (NULL == entity) {
//        jclass      (*FindClass)(JNIEnv*, const char*);
        jclass clazz = env->FindClass("java/lang/NullPointerException");
        env->ThrowNew(clazz, "entity 为空");
        return -1;
    }

//    jclass      (*GetObjectClass)(JNIEnv*, jobject);
    jclass pDetailProductClass = env->GetObjectClass(entity);
    if (NULL == pDetailProductClass) {
        return -1;
    }
//    jclass      (*GetSuperclass)(JNIEnv*, jclass);
    jclass pProductClass = env->GetSuperclass(pDetailProductClass);
    if (NULL == pProductClass) {
        return -1;
    }
    jclass pObjectClass = env->GetSuperclass(pProductClass);
    if (NULL == pObjectClass) {
        return -1;
    }
    jclass pJclass = env->GetSuperclass(pObjectClass);
    LOGI("Object's super class have jclass value? %s", NULL == pJclass ? "false" : "true");

    jclass pDetailProductClassByFind = env->FindClass("cn/rexih/android/testnativeinterface/entity/DetailProduct");
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    if (NULL == pDetailProductClassByFind) {
        return -1;
    }
    jclass pProductClassByFind = env->FindClass("cn/rexih/android/testnativeinterface/entity/Product");
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    if (NULL == pProductClassByFind) {
        return -1;
    }
//    jboolean    (*IsInstanceOf)(JNIEnv*, jobject, jclass);
    if (env->IsInstanceOf(entity, pDetailProductClassByFind)) {
        LOGI("entity [IsInstanceOf] DetailProduct: true");
    } else {
        LOGI("entity [IsInstanceOf] DetailProduct: false");
    }

    if (env->IsInstanceOf(entity, pProductClassByFind)) {
        LOGI("entity [IsInstanceOf] Product: true");
    } else {
        LOGI("entity [IsInstanceOf] Product: false");
    }

//    jboolean    (*IsAssignableFrom)(JNIEnv*, jclass, jclass);
    if (env->IsAssignableFrom(pProductClass, pDetailProductClass)) {
        LOGI("Product [IsAssignableFrom] DetailProduct: true");
    } else {
        LOGI("Product [IsAssignableFrom] DetailProduct: false");
    }
    if (env->IsAssignableFrom(pDetailProductClass, pProductClass)) {
        LOGI("DetailProduct [IsAssignableFrom] Product: true");
    } else {
        LOGI("DetailProduct [IsAssignableFrom] Product: false");
    }


    return 0;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_cn_rexih_android_testnativeinterface_MainActivity_testAllocObjectHasDefaultCtor(JNIEnv *env, jobject instance) {

    jclass pDetailProductClassByFind = env->FindClass("cn/rexih/android/testnativeinterface/entity/DetailProduct");
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    if (NULL == pDetailProductClassByFind) {
        return NULL;
    }

//    jobject pJobject = env->AllocObject(NULL);
//    if (env->ExceptionCheck()){
//        env->ExceptionDescribe();
//        env->ExceptionClear();
//    }

//    jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject object = env->AllocObject(pDetailProductClassByFind);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    return object;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_cn_rexih_android_testnativeinterface_MainActivity_testAllocObjectNoDefaultCtor(JNIEnv *env, jobject instance) {

    jclass pProductClassByFind = env->FindClass("cn/rexih/android/testnativeinterface/entity/Product");
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    if (NULL == pProductClassByFind) {
        return NULL;
    }
    jobject object = env->AllocObject(pProductClassByFind);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    return object;

}

extern "C"
JNIEXPORT jobject JNICALL
Java_cn_rexih_android_testnativeinterface_MainActivity_testNewObjectHasDefaultCtor(JNIEnv *env, jobject instance) {

    jclass pDetailProductClassByFind = env->FindClass("cn/rexih/android/testnativeinterface/entity/DetailProduct");
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    if (NULL == pDetailProductClassByFind) {
        return NULL;
    }

//    jmethodID GetMethodID(jclass clazz, const char* name, const char* sig)
    jmethodID pID = env->GetMethodID(pDetailProductClassByFind, "<init>", "()V");
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    if (NULL == pID) {
        return NULL;
    }

//    jobject     (*NewObject)(JNIEnv*, jclass, jmethodID, ...);
    jobject object = env->NewObject(pDetailProductClassByFind, pID);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    return object;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_cn_rexih_android_testnativeinterface_MainActivity_testNewObjectNoDefaultCtor(JNIEnv *env, jobject instance, jboolean supressCtorSignatureError, jboolean
rightParam, jboolean testWrongStringCtor) {

    jclass pProductClassByFind = env->FindClass("cn/rexih/android/testnativeinterface/entity/Product");
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    if (NULL == pProductClassByFind) {
        return NULL;
    }
    jmethodID rightStringCtorMethodID = env->GetMethodID(pProductClassByFind, "<init>", "(Ljava/lang/String;)V");
    jmethodID rightCtorMethodID = env->GetMethodID(pProductClassByFind, "<init>", "(I)V");
    jmethodID wrongCtorMethodID = env->GetMethodID(pProductClassByFind, "<init>", "()V");
    if (supressCtorSignatureError) {
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
    }

    jobject object;
    //只要构造函数签名正确即可，不会产生异常,能正常返回，但是java层在使用此对象时会产生不可预料的问题
    if (testWrongStringCtor) {
        // 应该传string，但是没有传或者传递错误的类型，虽然能够正常返回，但是当java层需要使用String时，会报stale reference
        //E/dalvikvm: JNI ERROR (app bug): accessed stale weak global reference 0x7b (index 30 in a table of size 0)
        //A/libc: Fatal signal 11 (SIGSEGV) at 0xdead4335 (code=1), thread 23145 (nativeinterface)
        object = env->NewObject(pProductClassByFind, rightStringCtorMethodID, 123);
//        object = env->NewObject(pProductClassByFind, rightStringCtorMethodID);
        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }
    } else {
        if (rightParam) {
            object = env->NewObject(pProductClassByFind, rightCtorMethodID, 123);
        } else {
            // 入参不传或者传递错误的参数都可以
//        jobject pJobject = env->AllocObject(env->FindClass("cn/rexih/android/testnativeinterface/entity/Review"));
//        object = env->NewObject(pProductClassByFind, rightCtorMethodID, pJobject);
//        object = env->NewObject(pProductClassByFind, rightCtorMethodID, true);
//        object = env->NewObject(pProductClassByFind, rightCtorMethodID, "hdfs");
            object = env->NewObject(pProductClassByFind, rightCtorMethodID);
//        if (env->ExceptionCheck()) {
//            env->ExceptionDescribe();
//            env->ExceptionClear();
//        }
        }
    }
    return object;


}

extern "C"
JNIEXPORT void JNICALL
testMethods(JNIEnv *env, jobject instance, jobject entity) {

    if (NULL == entity) {
//        jclass      (*FindClass)(JNIEnv*, const char*);
        jclass clazz = env->FindClass("java/lang/NullPointerException");
        env->ThrowNew(clazz, "entity 为空");
        return;
    }

//    jclass      (*GetObjectClass)(JNIEnv*, jobject);
    jclass pDetailProductClass = env->GetObjectClass(entity);
    if (NULL == pDetailProductClass) {
        return;
    }
//    jclass      (*GetSuperclass)(JNIEnv*, jclass);
    jclass pProductClass = env->GetSuperclass(pDetailProductClass);
    if (NULL == pProductClass) {
        return;
    }

    jmethodID pChildDescMID = env->GetMethodID(pDetailProductClass, "getDesc", "()Ljava/lang/String;");
    jmethodID pParentDescMID = env->GetMethodID(pProductClass, "getDesc", "()Ljava/lang/String;");


//    jobject     (*CallObjectMethod)(JNIEnv*, jobject, jmethodID, ...);
    jstring pChildDesc = static_cast<jstring>(env->CallObjectMethod(entity, pChildDescMID));
    const char *cChildDesc = env->GetStringUTFChars(pChildDesc, NULL);
    jstring pTestParentDesc = static_cast<jstring>(env->CallObjectMethod(entity, pParentDescMID));
    const char *cTestParentDesc = env->GetStringUTFChars(pTestParentDesc, NULL);
//    jobject     (*CallNonvirtualObjectMethod)(JNIEnv*, jobject, jclass, jmethodID, ...);
    //CallNonvirtualObjectMethod使用子类的methodID也可以与父类class实现调用父类方法
    jstring pParentDesc = static_cast<jstring>(env->CallNonvirtualObjectMethod(entity, pProductClass, pParentDescMID));
    const char *cParentDesc = env->GetStringUTFChars(pParentDesc, NULL);
    LOGI("pChildDesc:%s\npTestParentDesc:%s\npParentDesc:%s\n", cChildDesc, cTestParentDesc, cParentDesc);
    env->ReleaseStringUTFChars(pChildDesc, cChildDesc);
    env->ReleaseStringUTFChars(pParentDesc, cParentDesc);
    env->ReleaseStringUTFChars(pTestParentDesc, cTestParentDesc);

//    jmethodID   (*GetStaticMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID pChildSMID = env->GetStaticMethodID(pDetailProductClass, "getTotalCount", "()I");
    jmethodID pParentSMID = env->GetStaticMethodID(pProductClass, "getTheName", "()Ljava/lang/String;");
//    jobject     (*CallStaticObjectMethod)(JNIEnv*, jclass, jmethodID, ...);
    jint i = env->CallStaticIntMethod(pDetailProductClass, pChildSMID);
    jstring pTheName = static_cast<jstring>(env->CallStaticObjectMethod(pProductClass, pParentSMID));
    const char *cTheName = env->GetStringUTFChars(pTheName, NULL);
    LOGI("Parent class static method call result:%s\nChild class static method call result:%d\n", cTheName, i);
    env->ReleaseStringUTFChars(pTheName, cTheName);

    // call必须匹配，否则崩溃且无法捕获异常
//    env->CallStaticIntMethod(pDetailProductClass, pParentSMID);
//    if (env->ExceptionCheck()) {
//        env->ExceptionDescribe();
//        env->ExceptionClear();
//    }

}


extern "C"
JNIEXPORT void JNICALL
testFields(JNIEnv *env, jobject instance, jobject entity) {

    if (NULL == entity) {
//        jclass      (*FindClass)(JNIEnv*, const char*);
        jclass clazz = env->FindClass("java/lang/NullPointerException");
        env->ThrowNew(clazz, "entity 为空");
        return;
    }

//    jclass      (*GetObjectClass)(JNIEnv*, jobject);
    jclass pDetailProductClass = env->GetObjectClass(entity);
    if (NULL == pDetailProductClass) {
        return;
    }
//    jclass      (*GetSuperclass)(JNIEnv*, jclass);
    jclass pProductClass = env->GetSuperclass(pDetailProductClass);
    if (NULL == pProductClass) {
        return;
    }

//    jfieldID    (*GetFieldID)(JNIEnv*, jclass, const char*, const char*);
    jfieldID pNameID = env->GetFieldID(pProductClass, "name", "Ljava/lang/String;");
//    jobject     (*GetObjectField)(JNIEnv*, jobject, jfieldID);
    jstring pName = static_cast<jstring>(env->GetObjectField(entity, pNameID));
    const char *cName = env->GetStringUTFChars(pName, NULL);
    LOGI("name=%s", cName);
    env->ReleaseStringUTFChars(pName, cName);
    jstring pNewName = env->NewStringUTF("old driver");
//    void        (*SetObjectField)(JNIEnv*, jobject, jfieldID, jobject);
    env->SetObjectField(entity, pNameID, pNewName);

//    jfieldID    (*GetStaticFieldID)(JNIEnv*, jclass, const char*, const char*);
    jfieldID pTotolCountID = env->GetStaticFieldID(pDetailProductClass, "totalCount", "I");
//    jobject     (*GetStaticObjectField)(JNIEnv*, jclass, jfieldID);
    jint totalCount = env->GetStaticIntField(pDetailProductClass, pTotolCountID);
    LOGI("totalCount:%d", totalCount);
//    void        (*SetStaticObjectField)(JNIEnv*, jclass, jfieldID, jobject);
    env->SetStaticIntField(pDetailProductClass, pTotolCountID, 10086);
}


extern "C"
JNIEXPORT jobject JNICALL
testReflection(JNIEnv *env, jclass clazz, jobject entity, jobject idField, jobject setQuantityMethod) {



//    jfieldID    (*FromReflectedField)(JNIEnv*, jobject);
    jfieldID pFID = env->FromReflectedField(idField);
//    jmethodID   (*FromReflectedMethod)(JNIEnv*, jobject);
    jmethodID pMID = env->FromReflectedMethod(setQuantityMethod);
    env->CallVoidMethod(entity, pMID, 666);
    env->SetLongField(entity, pFID, 13718231203123123L);

//    jobject     (*ToReflectedMethod)(JNIEnv*, jclass, jmethodID, jboolean);
//    jobject     (*ToReflectedField)(JNIEnv*, jclass, jfieldID, jboolean);
    jclass pJclass = env->GetObjectClass(entity);
    jfieldID pID = env->GetFieldID(pJclass, "desc", "Ljava/lang/String;");
    return env->ToReflectedField(pJclass, pID, false);
}

static JNINativeMethod gMethods[] = {
        {"testReflection", "(Lcn/rexih/android/testnativeinterface/entity/Product;Ljava/lang/reflect/Field;Ljava/lang/reflect/Method;)Ljava/lang/reflect/Field;", (void *) testReflection},
        {"testFields","(Lcn/rexih/android/testnativeinterface/entity/DetailProduct;)V",(void*)testFields},
        {"testMethods","(Lcn/rexih/android/testnativeinterface/entity/DetailProduct;)V",(void*)testMethods}
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved) {
    JNIEnv *env = NULL;

    if (jvm->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_FALSE;
    }
    if (env == NULL) {
        return JNI_FALSE;
    }

    jclass clazz = env->FindClass("cn/rexih/android/testnativeinterface/MainActivity");
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    //注册方法
//    jint        (*RegisterNatives)(JNIEnv*, jclass, const JNINativeMethod*, jint);
    if (env->RegisterNatives(clazz, gMethods, sizeof(gMethods) / sizeof(gMethods[0])) < 0) {
        return JNI_FALSE;
    }
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNI_OnUnload(JavaVM* jvm, void* reserved){
    JNIEnv *env = NULL;
    if (jvm->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK) {
        return;
    }
    if (env == NULL) {
        return;
    }
    jclass clazz = env->FindClass("cn/rexih/android/testnativeinterface/MainActivity");
    if (clazz == NULL) {
        return;
    }
//    jint        (*UnregisterNatives)(JNIEnv*, jclass);
    env->UnregisterNatives(clazz);
    return;
}
