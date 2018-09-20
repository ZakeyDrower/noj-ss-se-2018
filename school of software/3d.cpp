// 三阶幻方
#include <iostream>
#include <stdio.h>
using namespace std;

void method1();
void method2(int m);
void permutaion(int *m, int index, int n);

int main()
{
    //method1();  // enumaration == 乱序：奇怪，递归不会出现的问题啊……
    method2(0); // search == AC
    return 0;
}

void method1()
{
    int mat[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    permutaion(mat, 0, 9);
}

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void permutaion(int *mat, int index, int n)
{
    if (index == n - 1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (mat[i * 3] + mat[i * 3 + 1] + mat[i * 3 + 2] != 15) // hang
                return;
            if (mat[i] + mat[i + 3] + mat[i + 6] != 15) // lie
                return;
        }
        if (mat[0] + mat[4] + mat[8] != 15 || mat[2] + mat[4] + mat[6] != 15)
            return;
        for (int i = 0; i < 3; i++)
        {
            printf("%d %d %d\n", mat[i * 3], mat[i * 3 + 1], mat[i * 3 + 2]);
        }
        printf("\n");
    }
    else
    {
        for (int i = index; i < n; i++)
        {
            swap(mat, i, index);
            permutaion(mat, index + 1, n);
            swap(mat, i, index);
        }
    }
}

//////////////////////////////////////////////////////////////////////
int a[3][3];
int used[10] = {0};

void testans();

void method2(int m)
{
    if (m == 9)
        testans();
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (used[i] == 0)
            {
                a[m / 3][m % 3] = i;
                used[i] = 1;
                method2(m + 1);
                used[i] = 0;
            }
        }
    }
}

void testans()
{
    for (int i = 0; i < 3; i++)
        if (a[i][0] + a[i][1] + a[i][2] != 15 || a[0][i] + a[1][i] + a[2][i] != 15) //行列不为15
            return;
    if (a[0][0] + a[1][1] + a[2][2] != 15 || a[0][2] + a[1][1] + a[2][0] != 15) //左斜右斜不为15
        return;
    // output
        for (int i = 0; i < 3; i++)
        {
            printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
        }
        printf("\n");
}