#include "SMVector.h"
int main()
{
    int x1[5]={1,2,3,5,6};
    SMVector<int>x(x1,5);
    SMVector<int>y(x);
    cout<<y;
}
