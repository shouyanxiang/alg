class modelDownloader {
    private long cppPointerValue;
    Object mutex = new object();

    @CalledByNative
    public modelDownloader() {

    }

    @CalledByNative
    public void setCppPointer(long cppPointer){
        cppPointerValue=cppPointer;
    }

    @CalledByNative
    public void destroyCppPointer() {
        synchronized (mutex){
            cppPointerValue=0; 
        }
    }

    @CalledByNative
    public void init(){
        // effect platform configure initialization
    }

    @CalledByNative
    public void download(){
        // luanch a Asynchronous thread to download model
    }

    @CalledByNative
    public void callBack(){
        // called after download thread finished
        synchronized (mutex){
            if(cppPointerValue){
                call_back_cpp(cpp_pointer,is_model_download_success,model_name)
            }
        }
    }

    public native void call_back_cpp(long cpp_pointer, boolean is_model_download_success, String model_name);

}