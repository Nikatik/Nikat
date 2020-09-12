#include "head.h"
int predict;

void ShowBin(char a, int N)
{

    for(int i = 0; i < 8-N-1; i++)
        a = a << 1;
    for (int i = 0; i < N+1; i++)
    {
        predict++;
        if (a & 0x80)
            cout << "1";
        else
            cout << "0";
        a = a << 1;
        if(predict%4==0) cout<<" ";
        if((N+1)%4!=0&&predict==(N+1)%4)
        {
            cout<<" ";
            predict=4;
        }
    }
}

long long int multy (int a, int b)
{
    long long int tmp=a;
    if (b==0)
    {
        return 1;
    }
    for(int i=1; i<b;i++)
    {
            tmp=a*tmp;
    }

    return tmp;
}
void CInt2::SetZero()
{
   N=0;
   a=NULL;
}

void CInt2::Clean()
{
    if(a!=NULL)
        delete [] a;
    SetZero();
}

void CInt2::CopyOnly(const CInt2 &b)
{
        a = new unsigned char[((b.N/8)+1)*sizeof(unsigned char)];
        for(int h=0;h<(b.N/8)+1;h++)
        {
            a[h]=b.a[h];
        }
        N=b.N;
}

CInt2::CInt2(int n)
{
    if(n>=0)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0,n);
        a = new unsigned char[((n/8)+1)*sizeof(unsigned char)];
        N=0;
        predict=0;
        for(int i=0; i<n/8+1;i++)
        {
            a[i]=0;
        }
        int c=dist(gen);
        int b=0;
        for (int i=0;i<c;i++)
        {
            uniform_int_distribution<> dist(0, (n) - 1);
            b=dist(gen);
            while((a[b/8] | multy(2,b%8))== a[b/8]) b=dist(gen);

            a[b/8] = a[b/8] | multy(2,b%8);
            predict=0;
            if (N<b)
            {
                N=b;
            }
        }
    }else{
        cout<<"Неправильные входные данные!"<<endl;
        a = new unsigned char[1*sizeof(unsigned char)];
        a[0]=0;
        N=n;
    }
    predict=0;
}

CInt2::~CInt2()
{
    Clean();
}

CInt2::CInt2 (const CInt2 &b)
{
    if(this!=&b)
    {
        this->N=0;
        CopyOnly(b);
    }
}

CInt2::CInt2 (CInt2 &&b)
{
    if(this!=&b)
    {
        this->N=b.N;
        this->a=b.a;
        b.a=NULL;
        b.N=0;
    }
}

CInt2& CInt2::operator=(const CInt2 &b)
{
    if(this!=&b)
    {
        Clean();
        CopyOnly(b);
    }
    return *this;
}

CInt2& CInt2::operator=(CInt2 &&b)
{
    if(this!=&b)
    {
        Clean();
        this->N=b.N;
        this->a=b.a;
        b.a=NULL;
        b.N=0;
    }
    return *this;
}

CInt2 CInt2::normal(int c)
{
        CInt2 tmp(1);
        tmp=*this;
        int tmp1=tmp.N;
        tmp.N=c;
        delete [] this->a;
        this->a = new unsigned char[(c/8+1)*sizeof(unsigned char)];
        for(int h=0;h<tmp1/8+1;h++)
        {
            this->a[h]=tmp.a[h];
        }
        for(int i=(tmp1)/8+1;i<=c/8;i++)
        {
            this->a[i]=0;
        }
        this->N=c;
        return *this;
}

long long int todec(const unsigned char *a, int N)
{
    unsigned long long int G=0;
    for(int i=0;i<=N;i++)
    {
        if(i ==0 && (a[i/8] | multy(2,i%8)) == a[i/8])
        {
            G=1;
        }
        if( i!=0 && (a[i/8] | multy(2,i%8)) == a[i/8])
        {
            G+=multy(2, i);
        }
    }
    return G;
}

void CInt2::print()
{

    predict=0;
    char tmp;
    tmp=a[N/8];
    ShowBin(tmp, N%8);
    for(int i=N/8-1;i>=0;i--)
    {
        tmp=a[i];
        ShowBin(tmp,7);
    }
    tmp=0;
    if(N<=63)
    {
        cout<<"     В десятичной системе это равно "<<todec(a,N);
    }
    cout<<endl;
    predict=0;
}

CInt2 CInt2::operator+(const CInt2 brr)
{
    int c=max(this->N, brr.N), g=0;
    CInt2 tmp (c);

    for(int h=0;h<tmp.N/8+1;h++) tmp.a[h]=0;

    unsigned char *crr;
    unsigned char *drr;

    tmp.N=c;

    if(this->N<c)
    {
        crr = new unsigned char[(c+1)*sizeof(unsigned char)];
        for(int i=this->N/8+1;i<=c/8+1;i++)
            crr[i]=0;
        for(int i=0;i<=this->N/8;i++)
        {
            crr[i]=this->a[i];
        }
    }else crr=this->a;

    if(brr.N<c)
    {
        drr = new unsigned char[(c+1)*sizeof(unsigned char)];
        for(int i=brr.N/8+1;i<=c/8+1;i++)
            drr[i]=0;
        for(int i=0;i<=brr.N/8;i++)
        {
            drr[i]=brr.a[i];
        }
    }else drr=brr.a;

    for(int i=0;i<=c;i++)
    {
        while(1)
        {
            if((crr[i/8] | multy(2,i%8)) == crr[i/8] && (drr[i/8] | multy(2,i%8)) == drr[i/8] && g>0)
            {
                tmp.a[i/8] = tmp.a[i/8] | multy(2,i%8);
                break;
            }

            if((crr[i/8] | multy(2,i%8)) == crr[i/8] && (drr[i/8] | multy(2,i%8)) == drr[i/8] && g<=0)
            {
                g++;
                tmp.a[i/8] = tmp.a[i/8] & ( 255 - multy(2,i%8));
                break;
            }

            if ((crr[i/8] | multy(2,i%8))== crr[i/8] || (drr[i/8] | multy(2,i%8))== drr[i/8])
            {
                if(g>0)
                {
                    tmp.a[i/8] = tmp.a[i/8] & ( 255 - multy(2,i%8));
                    break;
                }else{
                    tmp.a[i/8] = tmp.a[i/8] | multy(2,i%8);
                    break;
                }
            }

            if ((crr[i/8] | multy(2,i%8))!= crr[i/8] && (drr[i/8] | multy(2,i%8))!= drr[i/8] && g==0)
            {
                tmp.a[i/8] = tmp.a[i/8] & ( 255 - multy(2,i%8));
                break;
            }

            if ((crr[i/8] | multy(2,i%8))!= crr[i/8] && (drr[i/8] | multy(2,i%8))!= drr[i/8] && g!=0)
            {
                tmp.a[i/8] = tmp.a[i/8] | multy(2,i%8);
                g--;
                break;
            }
        }
    }
    if(g>0)
    {
        tmp=tmp.normal(c+g+2);
        for(int i=c+1;g>0;i++)
        {
            tmp.a[i/8] = tmp.a[i/8] | multy(2,i%8);
            g--;
        }
    }
    for(int i=tmp.N;i>=0;i--)
    {
        if ((tmp.a[i/8] | multy(2,i%8))== tmp.a[i/8])
        {
            tmp.N=i;
            break;
        }

    }
    if ((tmp.a[tmp.N/8] | multy(2,tmp.N%8)) != tmp.a[tmp.N/8])
    {
        tmp.N=0;
    }
    if(this->N<c)
    {
        delete [] crr;
    }
    if(brr.N<c)
    {
        delete [] drr;
    }
    return tmp;
}

CInt2 CInt2::operator-(CInt2 brr)
{
    int c=max(this->N, brr.N)+1;
    if(this->N<c-1)
    {
        cout<<"Выход из беззнакового режима!"<<endl;
        return brr-*this;
    }
    CInt2 tmp (1);
    CInt2 drr (1);
    CInt2 crr (1);
    drr.a[0]=0;
    crr.a[0]=0;
    tmp.N=0;
    drr=brr;
    crr=*this;
    drr=drr.normal(c);
    crr=crr.normal(c);
    for(int h=0;h<c/8+1;h++) drr.a[h]=~drr.a[h];
    tmp.a[0]=1;
    drr=drr+tmp;
    tmp.a[0]=0;
    tmp=crr+drr;
    if((tmp.a[c/8] | multy(2,c%8))== tmp.a[c/8])
    {
        cout<<"Выход из беззнакового режима!"<<endl;
        if(todec(this->a,this->N)>todec(brr.a,brr.N)&&crr.N<65&&brr.N<65)
        {
            crr.print();
            drr.print();
            cout<<"Мухахахахх... А чё за фигня то?"<<endl;
            tmp.print();
        }
        return brr-*this;
    }
    tmp.a[tmp.N/8] = tmp.a[tmp.N/8] & ( 255 - multy(2,tmp.N%8));
    for(int i=c;i>=0;i--)
    {
        if ((tmp.a[i/8] | multy(2,i%8))== tmp.a[i/8])
        {
            tmp.N=i;
            break;
        }
        tmp.N=0;
    }
    return tmp;
}

