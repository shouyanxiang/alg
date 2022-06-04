
// android_model_downloader.h
namespace model_downloader {
class AndroidModelDownloader : ModelDownloader {
public:
    AndroidModelDownloader();
    virtual ~AndroidModelDownloader();

    void init() override;
    bool get_model() override;
    void call_back() override;

private:
    void set_cpp_pointer_in_java();
    void destroy_cpp_pointer_in_java();

private:
    volatile bool exist_flag_;
    volatile bool is_model_download_successful_;
    bool is_call_back_;
    bool is_time_out_;
    int time_counter_;
    int time_out_threshold_;

    ScopedJavaLocalRef<jobject> java_model_downloader_;
};
} // namespace model_downloader