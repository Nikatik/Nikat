#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <random>

using namespace std;
class CInt2
{
    unsigned char *a;
    int N;
    public:
    CInt2(int n);
    ~CInt2();

    CInt2 (const CInt2 &);
    CInt2 (CInt2 &&);

    CInt2 &operator=(const CInt2 &);
    CInt2 &operator=(CInt2 &&);


    void SetZero();
    void Clean();
    void CopyOnly(const CInt2 &b);
    void print();

    CInt2 operator+(CInt2);
    CInt2 operator-(CInt2);

    CInt2 normal(int c);
};
