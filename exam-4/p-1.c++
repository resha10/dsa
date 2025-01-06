#include<iostream>

using namespace std;

void calculator()
{
    int choice;
    int x,z;

    cout << " input/outout "<< endl;

    cout << "press 1 for +" << endl ;
    cout << "press 2 for -" << endl ;
    cout << "press 3 for *" << endl ;
    cout << "press 4 for /" << endl ;
    cout << "press 5 for %" << endl ;
    cout << "press 0 for the exit" << endl;

    cout << "enter your choice :";
    cin >> choice ;

    if (choice >= 1 && choice <= 5)
     {
            cout << "enter the frist number: ";
            cin >> x;

            cout << "enter second number : ";
            cin >> z;

    switch(choice)
    {
        case 1:
            cout << " addition of : " << x + z << endl;

        break;

        case 2:
              cout << " substraction of : " << x - z << endl;
        break;

        case 3:
            cout << " multiplication of : " << x * z << endl;

         break;

        case 4:
              cout << " division  of : " << x / z << endl;

        break;

        case 5:
              cout << " modulas of : " << x % z << endl;
        break;
    
}
}
}
main() 
{
     calculator();
     return 0;
}