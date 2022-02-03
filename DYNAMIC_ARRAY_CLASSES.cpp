





#include <iostream>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

class dynamicarray
{
    int *data;
    int nextindex;
    int size;

 public:
    dynamicarray()
    {
        this->data = new int[5];
        nextindex = 0;
        size = 5;
    }

    dynamicarray(dynamicarray const &d)
    {
        // this->data = d.data;  //shallow copy

        this->data = new int[d.size];
        for (int i = 0; i < d.nextindex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->size = d.size;
        this->nextindex = d.nextindex;
    }

    void operator=(dynamicarray const &d)
    {

        this->data = new int[d.size];
        for (int i = 0; i < d.nextindex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->size = d.size;
        this->nextindex = d.nextindex;
    }

    void add(int element)
    {
        if (nextindex == size)
        {
            int *newdata = new int[2 * size];
            for (int i = 0; i < size; i++)
            {
                newdata[i] = data[i];
            }
            delete[] this->data;
            this->data = newdata;
            size = 2 * size;
        }
        data[nextindex] = element;
        nextindex++;
    }
    int get(int i)
    {
        if (i < nextindex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }

    void print()
    {
        for (int i = 0; i < nextindex; i++)
        {
            cout << this->data[i] << " ";
        }
        cout<<endl;
    }
};
int main()
{
    dynamicarray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();

    dynamicarray d2(d1);
    d2.print();

    return 0;
}
