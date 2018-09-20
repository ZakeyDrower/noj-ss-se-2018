// 装盘子
/*
思想：动态规划
方法：递归/规划
递归规律：(时间开销大)
f(m, n) = f(m, m)               m < n
f(m, n) = f(m, n-1) + 1         m = n
f(m, n) = f(m, n-1) + f(m-n, n) m > n
规划规律：（空间开销大）（优先）
int *mat = new int[m+1][n+1]()  <- 语法错了，意思一下
初始化：mat[1][1..n] = mat[1..m][1] = 1
计算：mat[i][1..i]
*/
#include <iostream>
using namespace std;

void printmatrix(int **mat, int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    int **mat = new int*[101]();
    for (int i = 0; i < 101;i++){
        mat[i] = new int[101]();
    }
    // 初始化
    for (int i = 1; i < 101; i++){
        mat[i][1] = 1;
        mat[1][i] = 1;
    }
    //printmatrix(mat, m, n);
    // calculate
    if(m < n) n = m;
    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            if(i > j)
                if(i-j < j)
                    mat[i][j] = mat[i][j - 1] + mat[i - j][i - j];
                else
                    mat[i][j] = mat[i][j - 1] + mat[i - j][j];
            if(i == j)
                mat[i][j] = mat[i][j - 1] + 1;
            //printmatrix(mat, m, n);
        }
    }
    cout << mat[m][n] << endl;
    return 0;
}

