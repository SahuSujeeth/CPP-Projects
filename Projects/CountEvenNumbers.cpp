#include <bits/stdc++.h>
using namespace std;
int countEven(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {12, 7, 4, 19, 22, 3, 8, 10};
    int result = countEven(arr, 8);
    cout << "The even count of the given array is the: " << result;

    return 0;
}