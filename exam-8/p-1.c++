#include <iostream>
using namespace std;

class Stack
 {
protected:
    int* arr;   
    int topIndex;
    int size; 

public:
    Stack(int s) 
    { 
        size = s;
        arr = new int[size];
        topIndex = -1; 
    }

    virtual ~Stack() 
    { 
    }

    virtual void push(int value) 
    {
        if (isFull()) 
        {
            cout << "Stack is full! Cannot push " << value << endl;
        } else
         {
            arr[++topIndex] = value;
            cout << value << " pushed into stack.\n";
        }
    }

    virtual void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty! Cannot pop.\n";
        } else 
        {
            cout << "Popped: " << arr[topIndex--] << endl;
        }
    }

    virtual int top()
     {
        if (!isEmpty()) 
        {
            return arr[topIndex];
        }
        cout << "Stack is empty! No top element.\n";
        return -1; 
    }

    bool isEmpty()
     {
        return topIndex == -1;
    }

    bool isFull()
     {
        return topIndex == size - 1;
    }
};


class DerivedStack : public Stack 
{

public:
    DerivedStack(int s) : Stack(s) {} 

    void push(int value) override
     {
        cout << "Derived class push method called.\n";
        Stack::push(value);
    }

    void pop() override
     {
        cout << "Derived class pop method called.\n";
        Stack::pop();
    }
};

int main() 
{
    int maxSize;
    cout << "Enter stack size: ";
    cin >> maxSize;

    DerivedStack s(maxSize);

    int choice, value;
    do 
    {
        cout << "\n1. Push\n2. Pop\n3. Display Top\n4. Check Empty \n5. Check Full\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.top() << endl;
                break;
            case 4:
                cout << (s.isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
                break;
            case 5:
                cout << (s.isFull() ? "Stack is full.\n" : "Stack is not full.\n");
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}