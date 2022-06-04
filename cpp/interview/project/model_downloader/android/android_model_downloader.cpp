#include "android_model_downloader.h"
#include "modelDownloader_jni.h"


// android_model_downloader.cpp
namespace {
static std::mutex mtx;
static std::set<model_downloader::AndroidModelDownloader *> android_model_downloader_pointer_set;
} // namespace

void JAVA_Native_call_back_cpp(JNIEnv *env, jobject obj, jlong cpp_pointer, jboolean is_model_download_success, jstring model_name) {
    // ......
    // convert model_name from jstring in JAVA to string in C++ [此处省略过程] model_name --> c_model_name

    // convert cpp_pointer from jlong in JAVA to long in C++ [此处省略过程] cpp_pointer --> c_cpp_pointer

    // convert is_model_download_success from jboolean to bool in C++ [此处省略过程] is_model_download_success --> c_is_model_download_success

    model_downloader::AndroidModelDownloader *cpp_model_downloader_poiner =
        reinterpret_cast<model_downloader::AndroidModelDownloader *>(cpp_pointer);
    cpp_model_downloader_poiner->call_back(c_cpp_pointer, c_is_model_download_success, c_model_name);
    // ......
}

namespace model_downloader {
// this function is called by JAVA class

AndroidModelDownloader::AndroidModelDownloader() {
    android_model_downloader_pointer_set.insert(this);

    // 初始化JAVA层class
    // new 一个 JNIEnv* 类型实例 jni_env
    Java_modelDownloader_modelDownloader(jni_env, java_model_downloader_);
    // ......
}

AndroidModelDownloader::~AndroidModelDownloader() {
    android_model_downloader_pointer_set.erase(this);
    destroy_cpp_pointer_in_java();
    exist_flag_ = true;
    mtx.lock();
    //  通知JAVA层，C++层的AndroidModelDownloader class已发生析构，并对JAVA层相应标志位进行置位
    mtx.unlock();
}

void AndroidModelDownloader::set_cpp_pointer_in_java() {
    // 将this指针，以long型变量 传递给JAVA层
    Java_modelDownloader_setCppPointer();
}

void AndroidModelDownloader::destroy_cpp_pointer_in_java() {
    // 将JAVA层对应指针置零
    Java_modelDownloader_destroyCppPointer();
}

void AndroidModelDownloader::init() {
    mtx.lock();
    // 将this指针传递给JAVA层
    set_cpp_pointer_in_java();
    Java_modelDownloader_init();
    mtx.unlock();
}

bool AndroidModelDownloader::get_model() {
    mtx.lock();
    Java_modelDownloader_download();

    while (!exist_flag_ && ${other_conditions} || ${other_conditions}) {
        sleep(30);
        if (time_counter_ > time_out_threshold_) {
            mtx.unlock();
            return false;
        }
        if (is_call_back_) {
            // get model information
            mtx.unlock();
            return is_model_download_successful_;
        }
    }

    if (exist_flag_) {
        mtx.unlock();
        return is_model_download_successful_;
    }
}

void AndroidModelDownloader::call_back(long cpp_pointer, bool is_model_download_success, const std::string &model_name) {
    mtx.lock();

    AndroidModelDownloader *cpp_model_downloader_poiner =
        reinterpret_cast<AndroidModelDownloader *>(cpp_pointer);

    if (!android_model_downloader_pointer_set.count(cpp_model_downloader_poiner)) {
        mtx.unlock();
        return;
    }

    // transport model information from

    mtx.unlock();
}
} // namespace model_downloader