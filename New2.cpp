#include<iostream>
using namespace std;

class objcal
{
    private:
    static int count;
    
    public:
    objcal()
    {
        count++;
    }
    static int showcount()
    {
        return count;
    }
};

int objcal::count=0;

int main()
{
    cout<<"Number of Objects before Objects creation: "<<objcal::showcount()<<endl;
    objcal cal1, cal2, cal3, cal4, cal5;
    cout<<"Number of Objects after 5 Objects creation: "<<objcal::showcount()<<endl;
    objcal cal6, cal7, cal8;
    cout<<"Number of Objects after 3 more Objects creation: "<<objcal::showcount()<<endl;
    system("pause");
}
