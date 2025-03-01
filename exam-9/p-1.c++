#include<iostream>
#include<vector>

using namespace std;

     void selectionsort(vector<int>& array)
    {
        int n = array.size();
            for(int i = 0 ; i < n-1 ; i++)
            {
                int minindex = i;
            for(int j = i + 1 ; j < n ; j++)  
            {
                if(array[j] < array[minindex])
                {
                    minindex = j;
                }
            } 
                swap(array[i] , array[minindex]); 
            }
    }

    void merge(vector<int>& array, int left, int mid, int right)
     {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> leftArray(n1), rightArray(n2);
        
        for (int i = 0; i < n1; i++) leftArray[i] = array[left + i];
        for (int i = 0; i < n2; i++) rightArray[i] = array[mid + 1 + i];
        
        int i = 0, j = 0, z = left;

        while (i < n1 && j < n2)
         {
            if (leftArray[i] <= rightArray[j])
             {
                array[z] = leftArray[i];
                i++;
            } 
            else
            {
                array[z] = rightArray[j];
                j++;
            }
            z++;
        }

        while (i < n1)
        {
            array[z] = leftArray[i];
            i++;
            z++;
        }
        
        while (j < n2) 
        {
            array[z] = rightArray[j];
            j++;
            z++;
        }
    }

    void mergeSort(vector<int>& array, int left, int right) 
    {
        if (left < right) 
        {
            int mid = left + (right - left) / 2;
            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }
    

    int linearSearch(vector<int>& array, int key)
     {
        for (int i = 0; i < array.size(); i++) 
        {
            if (array[i] == key) return i;
        }
        return -1;
    }

    int binarySearch(vector<int>& array, int key) 
    {
        int left = 0, right = array.size() - 1;
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (array[mid] == key) return mid;
            else if (array[mid] < key) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    
    void displayArray(const vector<int>& array) 
    {
        for (int number : array) 
        {
            cout << number << " ";
        }
        cout << endl;
    }
    
    int main()
     {
        vector<int> array;
        int choice, size, key, index;
    
        do
         {
            cout << "\n Menu:\n";
            cout << "1. Enter array\n";
            cout << "2. Selection Sort\n";
            cout << "3. Merge Sort\n";
            cout << "4. Linear Search\n";
            cout << "5. Binary Search\n";
            cout << "6. Display Array\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
    
            switch (choice)
             {
                case 1:
                    cout << "Enter size of array: ";
                    cin >> size;
                    array.resize(size);
                    cout << "Enter elements: ";

                    for (int i = 0; i < size; i++) cin >> array[i];
                    break;

                case 2:
                    selectionsort(array);
                    cout << "Array sorted using Selection Sort.\n";
                    break;

                case 3:
                    mergeSort(array, 0, array.size() - 1);
                    cout << "Array sorted using Merge Sort.\n";
                    break;

                case 4:
                    cout << "Enter element to search: ";
                    cin >> key;
                    index = linearSearch(array, key);

                    if (index != -1) cout << "Element found at index " << index << endl;
                    else cout << "Element not found.\n";
                    break;

                case 5:
                    cout << "Enter element to search: ";
                    cin >> key;
                    index = binarySearch(array, key);

                    if (index != -1) cout << "Element found at index " << index << endl;
                    else cout << "Element not found.\n";
                    break;

                case 6:
                    cout << "Array: ";
                    displayArray(array);
                    break;

                case 7:
                    cout << "Exiting program...\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } 
        while (choice != 7);
    
        return 0;
    }
    
    
    