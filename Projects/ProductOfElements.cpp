#include <bits/stdc++.h>
using namespace std;
int productArray(array<int, 6> myArray)
{
    int product = 1;
    for (auto s : myArray)
    {
        product *= s;
    }
    return product;
}
int main()
{
    array<int, 6> myArray{1, 2, 3, 4, 5, 6};
    int result = productArray(myArray);
    cout << "The product of the array is the : " << result;

    return 0;
}