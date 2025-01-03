// Use std::unique_lock to avoid scrambled output
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

std::mutex print_mutex;

void task(std::string str){
    for(int i=0;i<5;i++){
        //Create an std::unique_lock object
        // This calls print_mutex.lock()
        std::unique_lock<std::mutex> uniq_lock(print_mutex);

        // Start of critical section
        std::cout<<str[0]<<str[1]<<str[2]<<str[3]<<std::endl;

        // Unlock the mutex
        //uniq_lock.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(50));

    }// Calls ~std::unique_lock() 
}

int main(){
    std::thread t1(task, "abc");
    std::thread t2(task, "def");
    std::thread t3(task, "xyz");

    t1.join();
    t2.join();
    t3.join();

    return 0;
}