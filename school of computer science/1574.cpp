// 求第k小的数
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    int *arr = new int[10001]();
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    sort(arr, arr+n);
    cout << arr[k-1] << endl;
    return 0;
}