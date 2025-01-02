// Example of using a lambda expression as a thread's entry point
// The lambda takes arguments
#include <thread>
#include <iostream>

int main(){
    // Use a lambda expression as the thread's entry point
    std::thread thr(
        // The first argument is the lambda expression
        [](int i1, int i2){
            std::cout<<"The sum of "<< i1 <<" and "<< i2 <<" is "<< i1+i2 <<std::endl;
        },
        // The remaining arguments are passed to the lambda expression
        // These 2 arguments will be passed in to i1 and i2
        2,3
    );
    thr.join();
}