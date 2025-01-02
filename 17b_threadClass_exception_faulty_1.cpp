/*
Check "Exception in Parent Thread" in "08 Managing a Thread"
Example of an exception in parent thread. The exception happen too early 
and the thread was still active. Since the join() or detach() was not called,
this cause the the program to call terminate()
and the program will crash

Answer from the instructor: 
The problem is that, when the exception is thrown, this will the destructor 
of thread object. And that happens before join() or detach() has been called.
So we have the thread object which is being destroyed without joining 
 */
#include <thread>
#include <iostream>

// Task function
void hello(){
    std::cout<<"Hello Thread" <<std::endl;
}

int main(){
    try{
        // Create an std::thread object
        std::thread thr(hello);

        // Throw an exception
        throw std::exception();

        thr.join();        
    }
    catch (std::exception& e){
        std::cout<<"Exception caught: " <<e.what() <<std::endl;
    }

    // Check that the program is still running
    std::cout<< "Finish"<<std::endl;
}