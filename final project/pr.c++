#include<iostream>
using namespace std;


    struct Node 
    {
        int data;
        Node* next;
    };

    class LinkedList 
    {
    private:
         Node* head;
    public:
        LinkedList() 
	{ head = nullptr;}

    void insert(int value) 
    {
        Node* newNode = new Node{value, nullptr};
        if (!head) 
        {
            head = newNode;
        } 
        else
        {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() 
    {
        Node* temp = head;
        while (temp) 
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    int* toArray(int &size)
    {
        size = 0;
        Node* temp = head;
        while (temp) 
        {
            size++;
            temp = temp->next;
        }

        int* array = new int[size];
        temp = head;

        for (int i = 0; i < size; i++)
        {
            array[i] = temp->data;
            temp = temp->next;
        }
        return array;
    }
};

    void merge(int array[], int left, int middle, int right) 
	{
        int n1 = middle - left + 1, n2 = right - middle;
        int L[n1], R[n2];

        for (int i = 0; i < n1; i++) L[i] = array[left + i];
        for (int i = 0; i < n2; i++) R[i] = array[middle + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) array[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while (i < n1) array[k++] = L[i++];
        while (j < n2) array[k++] = R[j++];
	}

    void mergeSort(int array[], int left, int right) 
    {
        if (left < right)
        {
            int middle = left + (right - left) / 2;
            mergeSort(array, left, middle);
            mergeSort(array, middle + 1, right);
            merge(array, left, middle, right);
    	}
	}

    int partition(int array[],int low,int high)
    {
        int pt = array[high],i = low - 1;
        for(int j = low ; j < high ; j++)
        
            if(array[j] < pt) swap(array[++i], array[j]);
            
        swap(array[i + 1], array[high]);
        return i + 1;
    }

      void Quicksort(int array[], int low , int high)
        {
            if(low < high)
            {
                int pi = partition(array , low , high);
                Quicksort (array, low, pi - 1);
                Quicksort(array, pi + 1, high);
        }
    }

        int binarysearch(int array[] , int left , int right , int key)
        {
            while(left <= right)
            {
                int middle = left + (right - left) / 2;
                if(array[middle] == key) return middle;
                if(array[middle] < key) left = middle + 1;
                else right = middle - 1;
            }
                return - 1;
        }

    void menu()
    {
        LinkedList list;
        int choice , value;   

        while (true)
        {
            cout << "menu\n";
            cout << "1. insert element in Linked List ";
            cout << "2. display linked list";
            cout << "3. short merging";
            cout << "4. quick sorting";
          	cout << "5. binary search";
            cout << "6. exit /n";

            cout << "enter choice";
            cin >> choice;

        if (choice == 1)
        {
            cout << "enter value:";
            cin >> value;
            list.insert(value);
        }

        else if (choice == 2)
        {
            cout << "linked list";
            list.display();
        }
        
        else if(choice == 3 || choice == 4)
        {
            int size;
            int *array = list.toArray(size);
            if (size == 0)
            {
                cout << "list is empty";
                continue;
            }
        
            if (choice == 3) mergeSort(array , 0 , size - 1)
        {
            else quicksort(array, 0 , size - 1);
            cout << "sorted array :";
            for(int i = 0 ; i > size ; i++)
            cout << array[i] ;
            delete[] array;
        }
}

        else if(choice == 5)
        {
            int size , key ;
            int * array = list.toArray(size);
            if(size == 0)
            {
                cout << "list is empty!";
                continue;
            }

        mergeSort(array , 0 , size - 1);
            cout << "enter value of search :";
            cin >> key;

            int index = binarysearch(array , 0 , size - 1);
            if(index != 1)
            {
            else cout << "value not found \n ";
            delete[] array;
            } 

        else if (choice == 6)
        break;
        else cout << "invalid choice , try again \n";
    }
} 
        }
    int main()
    {
        menu();
        return 0;
	}
