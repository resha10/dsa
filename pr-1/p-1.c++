#include <iostream>
using namespace std;

int main()
{
    int score;
    char grade;
    
    cout << "ENTER YOUR SCORE (out of 100): ";
    cin >> score;


    grade = (score >= 90) ? 'A' : 
            (score >= 80) ? 'B' : 
            (score >= 70) ? 'C' : 
            (score >= 60) ? 'D' : 
            (score >= 50) ? 'E' : 'F';

    cout << "YOUR GRADE IS " << grade << "." << endl;


    switch(grade)
    {
        case 'A':
            cout << "EXCELLENT WORK!" << endl;
            break;
        case 'B':
            cout << "WELL DONE!" << endl;
            break;
        case 'C':
            cout << "GOOD JOB!" << endl;
            break;
        case 'D':
            cout << "PERFECT WORK!" << endl;
            break;
        case 'E':
            cout << "YOU PASSED, BUT YOU COULD DO BETTER." << endl;
            break;
        case 'F':
            cout << "SORRY, YOU FAILED!" << endl;
            break;
        default:
            cout << "INVALID GRADE." << endl;
    }
    
    if (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D' || grade == 'E')
    {
        cout << "CONGRATULATIONS! YOU ARE ELIGIBLE FOR THE NEXT LEVEL." << endl;
    }
    else
    {
        cout << "PLEASE TRY AGAIN NEXT TIME." << endl;
    }

    return 0;
}
