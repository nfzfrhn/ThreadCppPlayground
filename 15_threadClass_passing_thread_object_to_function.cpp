// Example of a passing a std::thread object to a function
#include <thread>
#include <iostream>

// The task function
void hello(){
    using namespace std::literals;
    std::this_thread::sleep_for(2s);
    std::cout<<"Hello Thread"<<std::endl;
}

// Function taking a thread object as argument
// The object must be moved into the argument
// The func argument becomes the owner of that execution thread
// And are responsible for calling join() on that object
/*
if you are writing a function which takes a thread argument, then it is
probably a good idea to put in &&
When we have && and not a template parameter, that means it must be rvalue
If we dont have any &&, it looks like we can provide both rvalue and lvalue

if the caller provides an lvalue, it will be copied, but for thread object
the copy constructors are deleted, so that would give a compiler error
*/
void func(std::thread&& thr){
    std::cout<<"Received thread with ID"<< thr.get_id() << std::endl;

    // The function argument now "owns" the system thread
    // It is responsible for calling join()
    thr.join();
}

int main(){
    // std::thread is a move-only object
    std::thread thr(hello);

    // Display the child thread's ID
    std::cout << "Hello thread has ID" << thr.get_id() << std::endl;

    // Pass a named object using std::move()
    func(std::move(thr));

    // Pass a temporary object
    // func(std::thread(hello));
}