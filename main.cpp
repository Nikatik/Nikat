#include "head.h"


int main()
{
    cout << "Привет, мир!" << endl;

    int n;
    cout<<"Введите максимальную размерность начальных чисел:"<<endl;
    //cout<<"Введите размерность первого числа:"<<endl;
    cin>>n;

    if(n<0)
    {
        cout<<"Неправильные входные данные!"<<endl;
        return -1;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0,n);

    CInt2 a (dist(gen));
    /*
    cout<<"Введите размерность второго числа:"<<endl;
    cin>>n;*/
    CInt2 b (dist(gen));

    cout<<"Первое число = ";
    a.print();

    cout<<"Второе число = ";
    b.print();

    CInt2 c (1);

    c=a+b;
    cout<<endl<<"Итог сложения равен : ";
    c.print();
    cout<<endl;

    c=a-b;
    cout<<"Итог вычитания равен : ";
    c.print();

    //todec1(a);

    return 0;
}
