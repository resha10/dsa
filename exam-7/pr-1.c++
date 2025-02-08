#include <iostream>

using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    
    Node(int value) 
    {
        data = value;
        next = nullptr;
    }
};
    class LinkedList
 {
private:
    Node* head;

public:
    LinkedList() 
    {
        head = nullptr;
    }

    void append(int data);
    void insert_at_beginning(int data);
    bool search(int key);
    void delete_node(int key);
    void reverse();
    void display();
};

void LinkedList::append(int data)
 {
    Node* newNode = new Node(data);
    if (head == nullptr) 
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::insert_at_beginning(int data)
 {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

bool LinkedList::search(int key) 
{
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void LinkedList::delete_node(int key) 
{
    Node* temp = head;
    Node* prev = nullptr;
    
    if (temp != nullptr && temp->data == key)
     {
        head = temp->next;
        delete temp;
        return;
    }
    
    while (temp != nullptr && temp->data != key)
     {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == nullptr) return;
    
    prev->next = temp->next;
    delete temp;
}

void LinkedList::reverse() 
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr)
     {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void LinkedList::display() 
{
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Append\n2. Insert at Beginning\n3. Search\n4. Delete\n5. Reverse\n6. Display\n7. Exit\n";
}

int main() {
    LinkedList list;
    int choice, value;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) 
        {
            case 1:

                cout << "Enter value to append: ";
                cin >> value;
                list.append(value);
                break;

            case 2:

                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insert_at_beginning(value);
                break;

            case 3:

                cout << "Enter value to search: ";
                cin >> value;
                if (list.search(value))
                    cout << value << " found in the list." << endl;
                else
                    cout << value << " not found in the list." << endl;
                break;

            case 4:

                cout << "Enter value to delete: ";
                cin >> value;
                list.delete_node(value);
                break;

            case 5:

                list.reverse();
                cout << "Linked list reversed." << endl;
                break;

            case 6:

              cout << "Linked List: ";
                list.display();
                break;

            case 7:

                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } 
    while (choice != 7);
    
    return 0;
}