#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <future>
#include <exception>

/*
It is possible that you may be calculating something in your thread may go wrong and it may throw an exception. And it that case, the question arise what kind of signal
you get from your future that is not a result but instead is an exception?
*/

using namespace std;

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
    promise<double> promise;

    auto do_calculation = [&](int terms){
        try
        {
            auto result = calculatePi(terms);
            promise.set_value(result);
        }
        catch(const std::exception& e)
        {
            promise.set_exception(current_exception());
        }                
    };
    //This will run but we have nowhere of getting the result
    thread t1(do_calculation, 1E6);

    future<double> future = promise.get_future();

    try
    {
        cout<<setprecision(15)<<future.get()<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    t1.join();
    
    return 0;
}