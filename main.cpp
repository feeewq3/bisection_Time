#include <iostream>
#include <cmath>
#include <iomanip>
using std::cout;
using std::endl;
using std::setprecision;

float g= 32.17, s0= 300, m= 0.25, k= 0.1;
double f(double t){ return (s0 - ( (m*g)/k )*t + ( (pow(m,2)*g)/-pow(k,2) )*(1.0-exp((-k*t)/m)));     }


void bisection(double a, double b, double TOL){
    int n = ceil(log2(( b - a) / TOL ) );
    double p=0.0;
    for (int i = 0; i < n; ++i) {
        p = ( b + a ) / 2.0;
        cout<< setprecision(20)<<i+1<<"\t"<<p<<endl;
        if(f(a)*f(p) < 0) b = p;
        else a = p;
    }
}

int main() {
    bisection(0,10,pow(10,-5));
    cout<<f(0)<<endl;
    cout<<f(10)<<endl;
    return 0;
}
