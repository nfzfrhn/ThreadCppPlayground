#include <thread>
#include <iostream>

// Callable object- thread entry point
void hello(){
    std::cout<<"Hello Thread"<<std::endl;
}

int main(){
    // Create an std::thread object
    // Pass the entry point function to the constructor
    std::thread thr(hello);

    // wait for the thread to complete
    thr.join();
}