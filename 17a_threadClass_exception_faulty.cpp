// Example of a thread which throws an exception
// Now if we try to catch the exception in main but the exception is thrown
// in thread hello() but were not handled there.
// The program will crash
#include <thread>
#include <iostream>

// Task function
void hello(){
    // Throw an exception
    throw std::exception();
    std::cout<<"Hello Thread" <<std::endl;
}

int main(){
    // Create an std::thread object
    try{
        std::thread thr(hello);
        thr.join();        
    }
    catch (std::exception& e){
        std::cout<<"Exception caught: " <<e.what() <<std::endl;
    }

    // Check that the program is still running
    std::cout<< "Finish"<<std::endl;
}