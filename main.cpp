#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class cstring
{
    public:
    int n;char *s;
    cstring()
    {
        setzero();
    }
    cstring(const cstring &b)
    {
        copyonly(b);
    }
    ~cstring()
    {
        clean();
    }
    void setzero()
    {
        n=0;
        s=NULL;
    }
    void clean()
    {
        delete[] s;
        setzero();
    }
    void copyonly(const cstring &b)
    {
        n=b.n;
        s=new char[n];
        memcpy(s,b.s,n);
    }
    cstring operator+(const cstring &b);
    cstring & operator=(const cstring &b)
    {
        if(&b!=this)
        {
            clean();
            copyonly(b);
        }
        return *this;
    }
    cstring &operator=(const char*b)
    {
        n=strlen(b);
        s=new char[n];
        memcpy(s,b,n);
        return *this;
    }
    void show()
    {
        printf("<");
        for(int i=0; i<n; i++)
        {
            printf("%c",s[i]);
        }
        printf(">");
    }
};

cstring cstring::operator+(const cstring &b)
{
    cstring r;
    r.n=n+b.n;
    if (r.n)
    {
        r.s=new char[r.n];
        memcpy(r.s,s,n);
        memcpy(r.s+n,b.s,b.n);
    }
    return r;
}

int main()
{
    cstring x, y, z;
    x="123";
    y="456";
    z=x+y;
    z.show();
    return 0;
}
