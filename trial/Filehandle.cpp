#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream quiz("quiz.txt");
    quiz << "What is the capital of France?\n";
    quiz << "What is the capital of Germany?\n";
    quiz << "What is the capital of Italy?\n";
    quiz << "What is the capital of Spain?\n";
    quiz << "What is the capital of Portugal?\n";
    quiz.close();    
}