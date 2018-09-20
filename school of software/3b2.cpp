// k 阶斐波那契数列的第m项
// 注：m从零开始！
#include <iostream>
using namespace std;

int main()
{
    int k, m;
    cin >> k >> m;

    if(m < k-1)
    {
        cout << 0 << endl;
    }
    else 
    {
        __int64 f[100000];
        for (int i = 0; i < k - 1; i++)
            f[i] = 0;
        f[k - 1] = 1;
        for (long i = k; i <= m; i++)
        {
            long sum = 0;
            for (long j = i - k; j <= i; j++)
                sum += f[j];
            f[i] = sum;
        }
        cout << f[m] << endl;
    }
    return 0;
}
