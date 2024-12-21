#include<iostream>

using namespace std;

int main() 
{
    int n=5 , i ,j; 
    
    for(i=1;i<=n;i++) 
    {
       
        for(j=1;j<=n-i;j++) 
        {
            cout << " ";  
        }

        for(j=1;j<=i;j++) 
        {
            if(j == 1 || j == i || i == n) 
            {
                cout << "* ";  
            }
            else 
            {
                cout << "  "; 
            }
        }
        cout << endl;
    }
}