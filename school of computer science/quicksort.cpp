#include <iostream>
using namespace std;

void swap(int *a, int i, int j)
{

    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int devide(int *arr, int left, int right)
{
    int pivotpos = left;
    int pivot = arr[left];

    for (int i = left + 1; i <= right; i++)
    {
        if (arr[i] < pivot)
        {
            pivotpos++;
            if (pivotpos != i)
                swap(arr, pivotpos, i);
        }
    }
    arr[left] = arr[pivotpos];
    arr[pivotpos] = pivot;

    return pivotpos;
}

void quick_sort(int *arr, int left, int right)
{
    if (left >= right)
        return;
    int p = devide(arr, left, right);
    quick_sort(arr, left, p - 1);
    quick_sort(arr, p + 1, right);
}

int main()
{
    int n;
    int *arr = new int[10001]();
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n;i++)
        cout << arr[i] << endl;
    
    return 0;
}