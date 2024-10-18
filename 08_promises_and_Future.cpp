#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <future>

/*
A perfect analogy is you go to the doctor, you get a test and they give you some kind of receipt for the test and then you just hand them back the receipt
and you just stand and waiting there untill finally they give you the result.

So this future is a thing you can get immediately. You get it straight away, but it's not until the result is actually ready that you actually get the result 
from the future.
*/

using namespace std;

double calculatePi(int terms)
{
    double sum = 0.0;
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
    promise<double> promise;

    auto do_calculation = [&](int terms){
        auto result = calculatePi(terms);

        promise.set_value(result);
    };
    //This will run but we have nowhere of getting the result
    thread t1(do_calculation, 1E6);

    future<double> future = promise.get_future();

    cout<<setprecision(15)<<future.get()<<endl;

    t1.join();
    return 0;
}