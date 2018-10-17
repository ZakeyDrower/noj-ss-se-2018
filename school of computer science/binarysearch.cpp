// binary search
// 2018-09-20
#include <iostream>
using namespace std;

void non_recursive_search(int *arr, int length, int key)
{
    int low = 0;
    int high = length - 1;
    int middle;

    while(low <= high)
    {
        middle = (low + high) / 2;
        if(arr[middle] > key)
            high = middle - 1;
        else if(arr[middle] < key)
            low = middle + 1;
        else
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

void recursive_serarch(int *arr, int low, int high, int key)
{
    if(low > high)
    {
        cout << "No" << endl;
    }
    else
    {
        int middle = (low + high) / 2;
        if(arr[middle] > key)
            recursive_serarch(arr, low, middle - 1, key);
        else if(arr[middle] < key)
            recursive_serarch(arr, middle + 1, high, key);
        else
            cout << "Yes" << endl;
    }
}

int main()
{
    int n, m;
    int *arr = new int[100001];
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    cin >> m;
    
    while(m--)
    {
        int key;
        cin >> key;
        //non_recursive_search(arr, n, key);
        recursive_serarch(arr, 0, n - 1, key);
    }

    return 0;
}