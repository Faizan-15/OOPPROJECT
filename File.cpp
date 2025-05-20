#include <iostream>
using namespace std; 

// Function to calculate the GCD of two numbers using Euclid's algorithm 
int gcd(int a, int b) 
{
    if (b == 0)
    {
        return a;
    }  
    else
    { 
        return gcd(b, a % b);
    } 
} 

// Recursive function to calculate the LCM of two numbers 
int lcm_recursive(int a, int b)
{
    return (a * b) / gcd(a, b);
} 

// Recursive function to calculate the LCM of three numbers
int lcm_three_numbers_recursive(int a, int b, int c)  
{
    return lcm_recursive(lcm_recursive(a, b), c);
}

// Iterative function to calculate the LCM of three numbers 
int lcm_three_numbers_iterative(int a, int b, int c)
{
    int lcm_ab = (a * b) / gcd(a, b);
    int lcm_abc = lcm_ab;
    while(lcm_abc % c != 0)
    {

        lcm_abc += lcm_ab;
    }
    return lcm_abc;
}

int main()
{
    int num1, num2, num3;
    cout<< "Enter three numbers: ";
    cin>> num1 >> num2 >> num3;
    int result_recursive = lcm_three_numbers_recursive(num1, num2, num3);
    cout<< "The LCM of " << num1 << ", " << num2 << ", and " << num3 << " (recursive) is: " <<result_recursive<<endl; 
    int result_iterative = lcm_three_numbers_iterative(num1, num2, num3); 
    cout<< "The LCM of " << num1 << ", " << num2 << ", and " << num3 << " (iterative) is: " <<result_iterative<<endl;
    system("pause");
    return 0;
}