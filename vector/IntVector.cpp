#include <cassert>
#include "IntVector.h"

using namespace std;
using namespace Sufe;

IntVector::IntVector()
    : m_size(0),
      m_capacity(16)
{
    m_data = new int[m_capacity]{0};
}

IntVector::IntVector(std::initializer_list<int> list)
{
    m_size = list.size();
    m_capacity = std::max(2 * m_size, 16);
    m_data = new int[m_capacity]{0};
    std::copy(list.begin(), list.end(), m_data);
}

IntVector::IntVector(const IntVector &other)
    : m_data(nullptr), m_size(0), m_capacity(0)
{
    // TODO: 按课件实现复制构造函数
    Reserve(other.m_capacity);

    m_size=other.m_size;

    for(int i=0;i<m_size;i++)
        m_data[i]=other[i];
}

IntVector &IntVector::operator=(const IntVector &rhs)
{
    // TODO: 按课件实现赋值运算符重载
    if(this == &rhs)
        return *this;
    
    if(m_capacity<rhs.m_size)
            Reserve(rhs.m_capacity);
    
    m_size = rhs.m_size;
    for(int i=0;i<m_size;++i)
        m_data[i]=rhs[i];

    return *this;
}

void IntVector::Insert(int idx, int val)
{
    // TODO: 按算法思路实现Insert
    if(m_size == m_capacity)
        Reserve(2*m_capacity);
    if(idx==m_size)
    {
        m_data[m_size]=val;
    }
    else
    {
        for(int i=m_size;i>=0;--i)
        {
            if(i < idx)
            {
                m_data[i]=m_data[i];
            }
            if(i == idx)
            {
                m_data[i]=val;

            }
            if(i > idx)
            {
                m_data[i]=m_data[i-1];
            }
        }

    }
           
    m_size++;
}

void IntVector::Delete(int idx)
{
    // TODO: 按算法思路实现Delete
    if(m_size <1/4 *m_capacity)
    {
        Reserve(1/2* m_capacity);
    }
    if(idx == m_size-1)
    {
        m_data[m_size-1]=0;
        
    }
    else
    {
         for(int i=0;i<m_size-1; ++i)
        {
            if(i < idx)
            {
                m_data[i]=m_data[i];
            }
            else
            {
                m_data[i]=m_data[i+1];
            }
           
        }
    }
   
    m_size--;

}

void IntVector::Resize(int sz, int val)
{
    // TODO: 按课件实现Resize
    if(sz>=0)
    {
        Reserve(sz);
        for(int i=m_size;i<sz;i++)
            m_data[i]=val;
        m_size=sz;
    }
}

void IntVector::Reserve(int cap)
{
    // TODO: 按课件实现Reserve
    if(cap > m_capacity)
    {
        int *data= new(nothrow) int[cap];
        if(data)
        {
            int sz =m_size;
            for(int i=0;i<sz;i++)
            {
                data[i]=m_data[i];
            }

            Reset();
            m_data=data;
            m_size=sz;
            m_capacity=cap;
        }


    }

}

int &IntVector::At(int idx)
{
    assert(idx >= 0 && idx < m_size);
    return m_data[idx];
}

void IntVector::Reset()
{
    if (m_data)
    {
        delete[] m_data;
        m_data = nullptr;
        m_capacity = m_size = 0;
    }
}

ostream &operator<<(ostream &out, const Sufe::IntVector &arr)
{
    for (int i = 0; i < arr.Size(); i++)
    {
        out << arr[i] << " ";
    }
    return out;
}
