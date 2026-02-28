#include <bits/stdc++.h>
using namespace std;
double Average(double a, double b, double c)
{
    return (a+b+c)/3;
}

int main()
{
    double result = Average(92.5,85.0,88.0);
    cout << "The Average of three numbers is: " << result ;

    return 0;
}