#include "SMVector.h"

template<class T>
SMVector<T>:: SMVector(int n)
{
    Capacity = n;
    Size=0;
    arr = new T[Capacity];
}
//-----------------------------------------------
template<class T>
SMVector<T>::SMVector(T* temp, int n )
{
    arr = new T[n];
    Size = n;
    Capacity = n * 2;
    for (int i = 0; i < n; ++i)
    {
      arr [i]= temp [i];
    }
}
//-----------------------------------------------
template<class T>
SMVector<T>:: SMVector (const SMVector& other)
{
    Size = other.Size;
    Capacity = other.Capacity;
    arr = new T[Capacity];
    for (int i = 0; i <Size; ++i)
    {
        arr[i]= other.arr[i];
    }
}
//-----------------------------------------------
template<class T>
SMVector<T>& SMVector<T>::operator=(const SMVector& other)
{
    if(this != &other)
    {
        delete [] arr;
        Size = other.Size;
        Capacity = other.Capacity;
        arr = new T[Capacity];
        for (int i = 0; i < other.Size; ++i)
        {
            this-> arr[i] = other.arr[i];
        }
    }
    return *this;
}
//-----------------------------------------------
template<class T>
SMVector<T>& SMVector<T>:: operator=(const SMVector&& other)
{
    if(this != &other)
    {
        delete [] arr;
        Size = other.Size;
        Capacity = other.Capacity;
        arr = new T[Capacity];
        for (int i = 0; i < other.Size; ++i)
        {
            this-> arr[i] = other.arr[i];
        }
        other.arr = nullptr;
        other.Size = 0;
        other.Capacity = 0;
    }
    return *this;
}
//-----------------------------------------------
// Access operations
template<class T>
T& SMVector<T>::operator[](int n)
{
    try{
        if(n > Size - 1){
            throw "Index out of range!!";
        }
        else {
            return arr[n];
        }
    }
    catch(char const* str){
        cout << str << endl;
    }
}

//-----------------------------------------------
// Modifiers
template<class T>
bool SMVector<T>::operator==(const SMVector<T>&other )
{
    if(Size != other.Size)
        return false;
    else
    {
        for (int i = 0; i < Size; ++i)
        {
            if(arr[i] != other.arr[i])
                return false;
        }
    }
    return true;
}
//-----------------------------------------------
template<class T>
bool SMVector<T>:: operator< (const SMVector<T>&other)
{
    for (int i = 0; i < min(Size,other.Size); ++i)
    {
        if(arr[i] < other.arr[i])
            return true;
    }
    if(other.Size > Size)
        return true;
    else
        return false;
}
//-----------------------------------------------
template<class T>
int SMVector<T>:: push_back(T element)
{
    if(Size < Capacity){
    arr[Size++] = element;
    }
    else{
    resize();
    arr[Size++] = element;
    }
    return Size;
}

//-----------------------------------------------
template<class T>
T SMVector<T>:: pop_back()
{
    T* new_arr = new T[Capacity];
    T last = arr[Size - 1];
    Size -= 1;
    for(int i = 0; i < Size; i++){
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    new_arr = nullptr;
    return last;
}
//-----------------------------------------------
template<class T>
void SMVector<T>:: erase(iterator pos)
{
    int index;
    bool found = false;
    for(int i = 0; i < Size; i++){
        if(&arr[i] == pos){
            index = i;
            found = true;

        }
    }
    try{
        if(!found){
            throw "Erase - Index out of range!!";
        }
    }
    catch(char const* str){
        cout << str << endl;
        return;
    }
    for(int i = index; i < Size - 1; i++){
        arr[i] = arr[i + 1];
    }
    Size--;

}
//-----------------------------------------------
template<class T>
void SMVector<T>:: erase(iterator iterator1, iterator iterator2)
{
    if(iterator1 == iterator2){
        return;
    }
    int index1, index2;
    bool found1 = false, found2 = false;
    for(int i = 0; i < Size; i ++){
        if(&arr[i] == iterator1){
            index1 = i;
            found1 = true;
        }
        else if(&arr[i] == iterator2){
            index2 = i;
            found2 = true;
        }
    }
    if(end() == iterator2){
        erase(end() - 1);
        index2 = Size;
        found2 = true;
    }
    try{
        if(iterator1 > iterator2){
            throw "Erase - Iterator1 > Iterator2!!";
        }
        else if(!found1 || !found2){
            throw "Erase - Index out of range!!";
        }

    }
    catch(char const* str){
        cout << str << endl;
        return;
    }

    T* new_arr = new T[Capacity];
    for(int i = 0; i < index1; i++){
        new_arr[i] = arr[i];
    }
    int j = index1;
    for(int i = index2; i < Size; i++){
        new_arr[j++] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    new_arr = nullptr;
    Size = Size - (index2 - index1);
}

//-----------------------------------------------
template<class T>
void SMVector<T>:: clear()
{
    Size = 0;
}
//-----------------------------------------------
template<class T>
void SMVector<T>:: insert(iterator pos, T element)
{
    int index;
    bool found = false;
    if(end() == pos){
        push_back(element);
        return;
    }
    for(int i = 0; i < Size; i++){
        if(&arr[i] == pos){
            index = i;
            found = true;
        }
    }
    try{
        if(!found){
            throw "Insert - Index out of range!!";
        }
    }
    catch(char const* str){
        cout << str << endl;
        return;
    }
    if(Capacity > Size){
        for(int i = Size; i > index - 1; i--){
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        Size++;
    }
    else{
        resize();
        for(int i = Size; i > index; i--){
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        Size++;
    }
}
//-----------------------------------------------
template<class T>
int SMVector<T>:: size() const
{
    return Size;
}
//-----------------------------------------------
template<class T>
int SMVector<T>:: capacity() const
{
    return Capacity;
}
//-----------------------------------------------
template<class T>
int SMVector<T>:: resize()
{
    Capacity *= 2;
    T* new_arr = new T[Capacity];
    for(int i = 0; i < Size; i++){
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    new_arr = nullptr;
    return Capacity;
}
//-----------------------------------------------
template<class T>
bool SMVector<T>:: empty()
{
    if(Size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//-----------------------------------------------
