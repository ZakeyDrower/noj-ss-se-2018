// enumeration n-bit binary number
#include <iostream>
#include <stdio.h>
using namespace std;

void recursion(char *s, int index, int n);

int main()
{
    char *bs = new char[21]();
    int n;
    cin >> n;
    recursion(bs, 0, n);
    return 0;
}

void recursion(char *s, int index, int n)
{
    if(index == n)
    {
        for (int i = 0; i < n; i++)
            printf("%c", s[i]);
        printf("\n");
    }
    else
    {
        s[index] = '0';
        recursion(s, index + 1, n);
        s[index] = '1';
        recursion(s, index + 1, n);
    }
}