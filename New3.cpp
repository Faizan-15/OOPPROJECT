#include<iostream>
using namespace std;

class alter {
private:
    int x=8;//Default value provided.

public:
    void initializer(int y)
    {
        x=y;
    }
    void display() const
    {
        cout<<"Value: "<<x<<endl;
    }
};

int main() {
    const alter alt; // Creating a constant object
    // alt.initializer(5); // This line causes a compilation error because a constant value cannot be changed or modified at all, So it is kept as comment.
    alt.display(); // This will display the default value as have been set above at line#6.
    system("pause");
}
