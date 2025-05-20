#include <iostream>
using namespace std;

void Input(int arr[], int size)
{
    cout<< "Enter " << size << " elements: ";
    
    for (int i = 0; i< size; i++)
    {
        cin>>arr[i];
    }
} 

void MergArray(int arr1[], int arr2[], int arr3[], int size1, int size2)
{
    int i = 0, j = 0, k = 0;

    for (i = 0; i< size1; i++)
    {
        arr3[k++] = arr1[i];
    }
    for (j = 0; j < size2; j++)
    {
        arr3[k++] = arr2[j];
    }
} 

void AscendingOrder(int arr[], int size)
{
    for (int i = 0; i< size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] >arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp;
            }
        }
    } 
} 

void Display(int arr[], int size)
{
    cout<< "Merged Array in Ascending Order: "; 
    for (int i = 0; i< size; i++)
    {
        cout<<arr[i] << " "; 
    } 
    cout<<endl;
} 

int main()
{
    int size1, size2;

    cout<< "Enter size of first array: "; 
    cin>> size1;
    cout<< "Enter size of second array: "; 
    cin>> size2;

    int arr1[size1], arr2[size2], arr3[size1 + size2];

    cout<< "Input for first array:" <<endl;
    Input(arr1, size1);

    cout<< "Input for second array:" <<endl;
    Input(arr2, size2);

    MergArray(arr1, arr2, arr3, size1, size2);
    AscendingOrder(arr3, size1 + size2);
    Display(arr3, size1 + size2);
    system("pause");
    return 0;
}