#include <iostream>
#include <thread>

using namespace std;

void hello(int i)
{
    cout<<"Hello Concurrent World "<< i <<endl;
}

class background_task{
    public:
        void operator()() const
        {
            void do_something();

        }
};

int main()
{
    thread t1(hello,5);
    t1.join();
}