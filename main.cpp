#include <bits/stdc++.h>
using namespace std;

template<class T>
class SMVector
{
private:
    int capacity;
    int size;
    T* arr;
    typedef T *iterator;
public:
    // Constructors and Big 4
    SMVector(int n = 5)
    {
        capacity = n;
        size=0;
        arr = new T[capacity];
    }
    //---------------------------------
    SMVector (T* temp, int n )
    {
        arr = new T[n];
        size = n;
        capacity = n * 2;
        for (int i = 0; i < n; ++i)
        {
            arr [i]= temp [i];
        }
    }
    //---------------------------------
    SMVector (const SMVector& other)
    {
        size = other.size;
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i <size; ++i)
        {
            arr[i]= other.arr[i];
        }
    }
    //---------------------------------
    ~SMVector()
    {
        delete [] arr;
    }
    //----------------------------------
    SMVector &operator=(const SMVector& other)
    {
        if(this != &other)
        {
            delete [] arr;
            size = other.size;
            capacity = other.capacity;
            arr = new T[capacity];
            for (int i = 0; i < other.size; ++i)
            {
                this-> arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    //------------------------------------------
    SMVector &operator=(const SMVector&& other)
    {
        if(this != &other)
        {
            delete [] arr;
            size = other.size;
            capacity = other.capacity;
            arr = new T[capacity];
            for (int i = 0; i < other.size; ++i)
            {
                this-> arr[i] = other.arr[i];
            }
            other.arr = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }
    //------------------------------------------
    // Access operations
    T& operator[](int n)
    {
        if(n > size-1)
        {
            cout<<"Invalid index!!";
            exit(0);
        }
        else
            return arr[n];
    }
    //------------------------------------------
    // Iterators
    iterator begin()
    {
        return arr;
    }
    iterator end()
    {
        return arr+(size);
    }
    //------------------------------------------
    // Comparison operations
    bool operator==(const SMVector<T>&other )
    {
        if(size != other.size)
            return false;
        else
        {
            for (int i = 0; i < size; ++i)
            {
                if(arr[i] != other.arr[i])
                    return false;
            }
        }
        return true;
    }
    //------------------------------------------
    bool operator< (const SMVector<T>&other)
    {
        for (int i = 0; i < min(size,other.size); ++i)
        {
            if(arr[i] < other.arr[i])
                return true;
        }
        if(other.size > size)
            return true;
        else
            return false;
    }
    //------------------------------------------
};
int main()
{
    int x1[5]={1,2,3,5,6};
    SMVector<int>x(x1,5);
    SMVector<int>y(x);
    cout<<y[0];
}