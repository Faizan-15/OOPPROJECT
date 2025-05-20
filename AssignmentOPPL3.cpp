#include <iostream>
using namespace std;

/* Class XLI declared in Advance so that it can be used in GLI class without any error.*/ 
class XLI;

// Class GLI is being declared and defined well
class GLI {
private:
    int valueG; // Private data member
    static int CarCount; // Static data member to count objects

public:
    // Parameterized Constructor
    GLI(int val) : valueG(val) {
        CarCount++; // Increments object counter whenever a new object is created
    }

    // Static member function to get the object count
    static int getCarCount() {
        return CarCount;
    }

    // Friend function declaration and will be defined later
    friend void displayValues(const GLI &g, const XLI &x);
};

// Initializing static data member as 0
int GLI::CarCount = 0; //return_type ClassName(Scope) Static Data Member

// Class B is being declared and defined well
class XLI {
private:
    int valueX; // Private data member

public:
    // Parameterized Constructor
    XLI(int val) : valueX(val) {} // Value is being assigned to store it and can be used later where needed.

    // Friend function declaration
    friend void displayValues(const GLI &g, const XLI &x);
};

// Friend function definition
void displayValues(const GLI &g, const XLI &x) {
    cout << "Value in GLI"<< g.getCarCount() <<": " << g.valueG << endl;
    cout << "Value in XLI: " << x.valueX << endl << endl;
}

int main() {
    // Create objects of class GLI and XLI
    XLI X1(30);
    GLI G1(10);

    // Displaying first to check whether counting is working perfectly or not
    displayValues(G1, X1);

    //Again creating another object
    GLI G2(20);

    // Display second values using the friend function
    displayValues(G2, X1);

    //Again creating another object
    GLI G3(90);

    // Display third values using the friend function
    displayValues(G3, X1);

    // At the last displaying total number of GLI Cars created
    cout << "Number of GLI Cars Manufactured: " << GLI::getCarCount() << endl << endl;
    
    //Necessary to stay on result instance of EXE file
    system("pause");
}
