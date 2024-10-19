#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <iomanip>

using namespace std;

/*
Packaged Task allow us to work with promises and futures but in a way that's nicer than if we work with them directly
*/

double calculatePi(int terms)
{
    double sum = 0.0;

    if(terms < 1)
    {
        throw runtime_error("Terms cannot be less than 1");
    }

    for(int i=0;i<terms;i++)
    {
        int sign = pow(-1,i);
        double term = 1.0/(i*2+1);
        sum +=sign*term;        
    }
    return sum*4;
}

int main()
{
    //std::packaged_task
    // This is a template type and you need to specify the type of function
    // So we dont mix any multithreading code with calculatePi function. Our custom function remain free from the multithreading code
    // We dont have to mention promise directly at all. The only thing that we deal directly is future and not promise
    packaged_task<double(int)> task1(calculatePi);

    future<double> future1 = task1.get_future();

    // To run the calculatePi function we create a thread
    // Move: Create a shallow copy of this and then copy into it any resources that is using pointers to memory or whatever, just in fact move them
    thread t1(move(task1), 0);

    try
    {
        double result = future1.get();
        cout<<setprecision(15)<<result<<endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    t1.join();
}