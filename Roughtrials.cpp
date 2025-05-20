#include<iostream>
using namespace std;

class Box
{
      private:
              int width;
              int colour;
      public:
             Box() {width=0,colour="Green";}
             friend void setwidth(Box &b, Box &c);
};

void setwidth(Box &b, Box &c)
{
     b.width = 10;
     c.colour = "Blue";
}

int main()
{
    Box box;
    box.setwidth();
    return 0;
}
