// Example with thread ID
#include <thread>
#include <iostream>

// Task function
// Displays the thread's ID
void hello(){
    std::cout<<"Hello from thread with ID "<< std::this_thread::get_id()<<std::endl;
}

int main(){
    // Display the main thread's ID
    std::cout << "Main thread has ID " << std::this_thread::get_id() << std::endl;

    // Create a std::thread object
    std::thread thr(hello);

    // Display the child thread's ID
    std::cout<< "Hello thread has ID " << thr.get_id() <<std::endl;

    // Wait for the thread to complete
    thr.join();

    // Display the child thread's ID again
    std::cout<<"Hello thread now has ID"<<thr.get_id() << std::endl;

    std::cout<< std::endl;
    std::cout<< std::endl;
}