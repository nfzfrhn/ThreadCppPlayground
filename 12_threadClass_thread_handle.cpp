// Example with thread handle
#include <thread>
#include <iostream>

// Task function
void hello(){
    std::cout<<"Hello Thread"<<std::endl;
}

int main(){
    // Create an std::thread object
    std::thread thr(hello);

    // Display the child thread's native handle
    std::cout<<"Hello thread has native handle " << thr.native_handle() << std::endl;

    // Wait for the thread to complete
    thr.join();

    // Displaythe child thread's native handle again
    std::cout<<"Hello thread now has native handle "<<thr.native_handle()<<std::endl;
}