// Example of passing an argument to a thread function
#include <thread>
#include <iostream>

// Thread entry point
void hello(std::string str, int i ){
    std::cout<<str<<" "<< i<<std::endl;
}

int main(){
    // hello() takes a string argument
    std::thread thr(hello, "Hello Thread",10);
    thr.join();
}