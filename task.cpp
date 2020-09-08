#include "head.h"

my::my()
{
    for (int i=0;i<n;i++)
    {
        x[i]=rand()%50;
    }
}

void print(const my &v)
{
    for(int i=0;i<n;i++)
    {
        cout<<v.x[i]<<" ";
    }
    cout<<endl;
}

my my::operator+(const my &v)
{
    my tmp;
    for (int i=0;i<n;i++)
    {
        tmp.x[i]=x[i]+v.x[i];
    }
    return tmp;
}

my my::operator*(int a)
{
    my tmp;
    for (int i=0;i<n;i++)
    {
        tmp.x[i]=x[i]*a;
    }
    return tmp;
}

my operator*(int a, const my & v)
{
    my tmp;
    for (int i=0;i<n;i++)
    {
        tmp.x[i]=a*v.x[i];
    }
    return tmp;
}
