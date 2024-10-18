#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <future>

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
    thread t1(calculatePi, 1E6);
    t1.join();
    //cout<<setprecision(15)<<calculatePi(1000000)<<endl;;
    return 0;
}