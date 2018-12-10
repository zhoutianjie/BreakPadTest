#include <jni.h>
#include <string>
#include <android/log.h>

#include "../include/client/linux/handler/exception_handler.h"
#include "../include/client/linux/handler/minidump_descriptor.h"

#define LOG_TAG "ztj_crash"

#define ALOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define ALOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define ALOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define ALOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define ALOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

bool DumpCallback(const google_breakpad::MinidumpDescriptor &descriptor,
                  void *context,
                  bool succeeded) {
    ALOGD("===============crrrrash================");
    ALOGD("Dump path: %s\n", descriptor.path());
    return succeeded;
}

extern "C"
JNIEXPORT void

JNICALL
Java_com_ztj_breakpad_BreakPad_BreakPadInit(
        JNIEnv *env,
        jclass type,
        jstring path_/* this */) {
    const char *path = env->GetStringUTFChars(path_, 0);

    google_breakpad::MinidumpDescriptor descriptor(path);
    static google_breakpad::ExceptionHandler eh(descriptor, NULL, DumpCallback, NULL, true, -1);

    env->ReleaseStringUTFChars(path_, path);
}

extern "C"
JNIEXPORT void

JNICALL
Java_com_ztj_breakpad_BreakPad_BreakPadTest(
        JNIEnv *env,
        jclass type) {
    volatile int *a=(int*)(NULL);
    *a=1;
}


