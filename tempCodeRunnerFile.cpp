#include <iostream>
#include <vector>
using namespace std;
int used[20] = {0};
void permutation(int *arr, int *ansarr, int index, int n)
{
    if (index == n)
    {
        for (int i = 0; i < n;i++)
            cout << ansarr[i] << ' ';
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if(used[arr[i]]==0){
                used[arr[i]] = 1;
                ansarr[index] = arr[i];
                permutation(arr, ansarr, index + 1, n);
                used[arr[i]] = 0;
            } 
        }
    }
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    int ansarr[4] = {0};
    permutation(a, ansarr, 0, 4);
    return 0;
}