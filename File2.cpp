#include <iostream> 

using namespace std; 

void findMostFrequentDigits(int numbers[], int size)
{
    int frequency[10] = {0};
    for (int i = 0; i< size; i++)
    {
        int currentNumber = numbers[i];
        // convert to positive
        if (currentNumber< 0)
        {
            currentNumber = -currentNumber;
        }
        while (currentNumber> 0)
        {
            int digit = currentNumber % 10;
            frequency[digit]++;
            currentNumber /= 10;
        }
    }
    
    int maxFrequency = 0;

    for (int i = 0; i< 10; i++)
    {
        if (frequency[i] >maxFrequency)
        {
            maxFrequency = frequency[i];
        }
    } 
    
    cout<< "Most frequent digit(s): ";
    
    for (int i = 0; i< 10; i++)
    {
        if (frequency[i] == maxFrequency)
        {
            cout<<i<< " ";
        }
    }
    cout<< "\nFrequency: " <<maxFrequency<<endl;
} 

int main()
{
    int size;
    cout<< "Enter the number of integers: ";
    cin>> size;

    int numbers[size];
    cout<< "Enter the integers: ";

    for (int i = 0; i< size; i++)
    {
        cin>> numbers[i];
    }

    findMostFrequentDigits(numbers, size);
    system("pause");
    return 0;
} 