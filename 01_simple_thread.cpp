#include <iostream>
#include <thread>

using namespace std;

void hello()
{
    cout<<"Hello Concurrent World"<<endl;
}

int main()
{
    thread t1(hello);
    t1.join();
}