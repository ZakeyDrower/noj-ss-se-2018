// reverse Polish notatio
// input: 32+5*
// output:20
// 
// 这个算法oj判断WA？用栈写是
#include <iostream>
using namespace std;

int add(char *s);

int main()
{
    char *str = new char[30]();
    cin >> str;

    cout << add(str) << endl;

    return 0;
}

int add(char *str)
{
    int a = (int)(*str)-48, b=0;
    str++;
    while(*str != '\0')
    {
        switch (*str)
        {
            case '+':
                a += b;
                break;
            case '-':
                a -= b;
                break;
            case '*':
                a *= b;
                break;
            case '/':
                a /= b;
                break;
            default:
                b = (int)(*str) - 48;
                break;
        }
        str++;
    }
    return a;
}