// Example of a thread which throws an exception
#include <thread>
#include <iostream>

// Task function
void hello(){
    try{
        // Throw an exception
        throw std::exception();
    }
    catch (std::exception& e){
        std::cout<<"Exception caught: " <<e.what() <<std::endl;
    }
    std::cout<<"Hello Thread" <<std::endl;
}

int main(){
    // Create an std::thread object
    std::thread thr(hello);
    thr.join();

    // Check that the program is still running
    std::cout<< "Finish"<<std::endl;

}