#ifndef _HELPERS_H_
#define _HELPERS_H_

template<typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

#endif