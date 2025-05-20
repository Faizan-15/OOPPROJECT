#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    void setValue(int v) {
        value = v;
    }
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    const MyClass obj; // Creating a constant object
    // obj.setValue(5); // This line would cause a compilation error
    obj.display(); // This will display the default value (uninitialized)
    return 0;
}