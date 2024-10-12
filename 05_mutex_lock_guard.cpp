#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

// It is recommmend to use lock_guard because it will unlock when it is out of scope
// The risk of using mutex.lock() and mutex.unlock() is that if there exist an exception
// Our critical section will never be unlock and therefore, our programm will stuck indefinitely
// Using lock_guard or unique_lock is safer
void work(int &count, mutex &mtx){
    for(int i=0;i<1E6;i++){
            lock_guard<mutex> guard(mtx);
            ++count;        
    }
}

int main(){
    
    int count = 0;

    mutex mtx;

    // What is ref?
    thread t1(work, ref(count), ref(mtx));
    thread t2(work, ref(count), ref(mtx));

    t1.join();
    t2.join();

    cout<<count<<endl;

    return 0;
}