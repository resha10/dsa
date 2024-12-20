#include<iostream>

using namespace std;

int main()
{

    int number , sum , first , last;
    
    cout << "enter any numbers: ";
    cin >> number;

    last = number % 10;

    while (number >=10)
    {
        number = number / 10;
    }

    first = number;  
    
   sum = first + last;
    
    cout << "\n the sum of first and last digites :" << sum << endl;
    
    return 0;


}