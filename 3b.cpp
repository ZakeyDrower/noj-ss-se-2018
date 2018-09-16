// k 阶Fibonacci的第m项
#include <iostream>
#include <queue>
using namespace std;

long sum(long *arr, int k)
{
    long sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    return sum;
}

void printarr(long * arr, int k){
    for (int i = 0; i < k;i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    int k=2, m=1;
    cin >> k >> m;
    long *arr = new long[k]();
    arr[k - 1] = 1;
    printarr(arr, k);
    if (m <= k)
    {
        cout << arr[m-1] << endl;
    }
    else
    {
        int i;
        for (i = 0; i < m - k; i++)
        {
            arr[i % k] = sum(arr, k);
            printarr(arr, k);
        }
        cout << arr[(i-1) % k] << endl;
    }
    return 0;
}