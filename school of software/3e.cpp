// permutation
#include <iostream>
#include <stdio.h>
using namespace std;

void swap(char *str, int a, int b) 
{
    char t = str[a];
    str[a] = str[b];
    str[b] = t;
}

void permutation(char *str, int l, int r)
{
    if(l==r-1){
        // output
        for (int i = 0; i < r; i++)
            printf("%c", str[i]);
        printf("\n");
    }
    else
    {
        for (int i = l; i < r; i++){
            swap(str, i, l);
            permutation(str, l + 1, r);
            swap(str, i, l);
        }
    }
}

int main()
{
    char str[11] = "abcdefghig";
    int n;
    cin >> n;
    permutation(str, 0, n);
    return 0;
}