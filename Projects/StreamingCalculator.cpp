#include <bits/stdc++.h>
using namespace std;

int main()
{
    char package;
    int numDevices;
    int totalCost = 0;

    int devicesOver = 0;
    const int includedA = 1;
    const int includedB = 3;
    const int includedC = 5;

    const int baseA = 9;
    const int baseB = 14;
    const int baseC = 20;

    const int extraA = 6;
    const int extraB = 4;
    const int extraC = 2;

    cout << "Welcome to the Streaming Subscription Calcluator!" << endl;
    cout << "Enter Your package (A, B or C): ";
    cin >> package;

    cout << "Enter number of simultanoues devices user: ";
    cin >> numDevices;

    if (package == 'A')
    {
        totalCost += baseA;
        if(numDevices > includedA)
        {
          devicesOver = numDevices - includedA;
          totalCost += devicesOver * extraA;
        }
    }
    else if (package == 'B')
    {
        totalCost += baseB;
        if(numDevices > includedB)
        {
            devicesOver = numDevices - includedB;
            totalCost += devicesOver * extraB;
        }
    }
    else if (package == 'C')
    {
        totalCost += baseC;
        if(numDevices > includedC){
            devicesOver = numDevices - includedC;
            totalCost += devicesOver * extraC;
        }
    }
    else
    {
        cout << "Invalid package selection." << endl;
        return 0;
    }

    cout << "Your total cost for the month is: $" << totalCost << endl;

    return 0;
}