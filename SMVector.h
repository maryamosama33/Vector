#ifndef UNTITLED3_SMVECTOR_H
#define UNTITLED3_SMVECTOR_H
#include <bits/stdc++.h>
using namespace std;

template<class T>
class SMVector
{
private:
    int Capacity;
    int Size;
    T* arr;
    typedef T* iterator;
public:
    // Constructors and Big 4
    SMVector(int n = 5);
    SMVector (T* temp, int n );
    SMVector (const SMVector&);
    SMVector &operator=(const SMVector&);
    SMVector &operator=(const SMVector&&);
    ~SMVector()
    {
        delete [] arr;
    }
    //-----------------------------------------------

    // Access operations
    T& operator[](int n);

    // Iterators
    iterator begin()
    {
        return arr;
    }
    iterator end()
    {
        return arr+(Size);
    }

    // Comparison operations
    bool operator==(const SMVector<T>&other );
    bool operator< (const SMVector<T>&other);

    //Modifying operations
    int push_back(T element);
    T pop_back();
    void erase(iterator pos);
    void erase(iterator iterator1, iterator iterator2);
    void clear();
    void insert(iterator pos, T element);

    //Capacity operations
    int size() const;
    int capacity() const;
    int resize();
    bool empty();

    //Friends
    friend ostream& operator<<(ostream& out, SMVector<T> v)
    {
        for(int i = 0; i < v.Size; i++){
            out << v[i] << " ";
        }
        out << endl;
        return out;
    }
    //-----------------------------------------------
};


#endif
