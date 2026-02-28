#include <bits/stdc++.h>
using namespace std;
void productArray(array<int,6>myArray,int& result)
{
  result = 1;
  for(auto s : myArray)
  {
    result *= s;
  }
  
}
int main()
{
    array<int,6>myArray{1,2,3,4,5,6};
    int product;
    productArray(myArray,product);
    cout << "The final product of the array is the : " << product;

    return 0;
}