#include<iostream>

using namespace std;

int main()
{

    int score;
    char grade;

    cout << "enter score out of 100 :" ;
    cin >> score;

    grade = (score >= 90)?'a':
            (score >= 80)?'b':
            (score >= 70)?'c':
            (score >= 60)?'d':
            (score >= 50)?'e':'f';

    cout << "your grade is" << endl;

    switch(grade)
    {
        case a:
        cout << "excellent work" << endl;
        break;

        case b:
        cout << "well done" << endl;
        break;

        case c:
        cout << "good job" << endl;
        break;

        case d:
        cout << "you passesd, but you could do it better" << endl;
        break;

        case f:
        cout << "sorry , you failed" << endl;
        break;

        default:
        cout << "do better next time" << endl; 
}
        if(grade == 'a' || grade == 'b' || grade == 'c' || grade == 'd' || grade == 'f')
        {
            cout << "Congratulations! You are eligible for the next level "<< endl;
        }
        else 
        {
            cout << "Please try again next time" << endl;
        }
}
