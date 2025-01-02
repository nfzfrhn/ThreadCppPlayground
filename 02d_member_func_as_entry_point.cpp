// Example of using a member function as a thread's entr point
#include <thread>
#include <iostream>

// Class whose member function
// Will be used as the thread's entry point
class Greeter{
    public:
        void hello(){
            std::cout<<"Hello Member Function Thread" << std::endl;
        }
};

int main(){
    // Create an object of the class
    Greeter greet;

    // Create an std::thread object
    // Pass a pointer to the member function
    std::thread thr(&Greeter::hello, &greet);

    thr.join();
}