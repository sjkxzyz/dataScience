#include <iostream>
#include "AutoTimer.h"
#include "IntVector.h"

using namespace std;

void TestInsertHead(int num)
{
    Sufe::IntVector vec;
    cout << "Insert " << num << " elements at head" << endl;

    AutoTimer timer;
    for (int i = 0; i < num; i++)
    {
        vec.InsertHead(i);
    }
}

void TestReserveAndInsertHead(int num)
{
    Sufe::IntVector vec;
    cout << "Reserve and insert " << num << " elements at head" << endl;

    AutoTimer timer;
    for (int i = 0; i < num; i++)
    {
        // Calling reserve in loop is bad
        vec.Reserve(vec.Size() + 1);
        vec.InsertHead(i);
    }
}

void TestInsertTail(int num)
{
    Sufe::IntVector vec;
    cout << "Insert " << num << " elements at tail" << endl;

    AutoTimer timer;
    for (int i = 0; i < num; i++)
    {
        vec.InsertEnd(i);
    }
}

int main(int argc, char *argv[])
{
    int num = 50000;
    if (argc > 1)
    {
        num = atoi(argv[1]);
    }

    // test vector is growing while inserting

    Sufe::IntVector s;
    s.InsertHead(1);
    s.InsertHead(2);
    s.InsertEnd(4);
    for(int k=0;k<s.Size();++k) cout<<s[k]<<" ";
    
    Sufe::IntVector foo;
    cout << "Making foo grow:" << endl;
    int cap = foo.Capacity();
    cout << "size/capacity is " << foo.Size() << " / " << cap << endl;
    for (int i = 0; i < num; i++)
    {
        foo.InsertEnd(i);
        if (cap != foo.Capacity())
        {
            cap = foo.Capacity();
            cout << "size/capacity becomes " << foo.Size() << " / " << cap << endl;
        }
    }
    cout << endl;

    // test insert patterns
    TestInsertTail(num);           // fastest
    TestInsertHead(num);           // slow
    TestReserveAndInsertHead(num); // slower

    return 0;
}
