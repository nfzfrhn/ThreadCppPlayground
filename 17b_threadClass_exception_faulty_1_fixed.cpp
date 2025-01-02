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

Solution:
one solution is to move the thread object outside the try/catch blocks.
Then we call join() in the try block again, and we also join() in the 
catch block
So when the thread object is destroyed at the end of this scope, the 
destructor is called and the thread will have been joined in both cases
 */
#include <thread>
#include <iostream>

// Task function
void hello(){
    std::cout<<"Hello Thread" <<std::endl;
}

int main(){

    // Create an std::thread object
    std::thread thr(hello);

    try{

        // Code that might throw an exception
        throw std::exception();

        // No exception if we got here - call join() as usual
        thr.join();        
    }
    catch (std::exception& e){
        std::cout<<"Exception caught: " << e.what() <<std::endl;

        // Call join() before thr's destructor is called
        thr.join();
    }

    // Check that the program is still running
    std::cout<< "Finish"<<std::endl;
}