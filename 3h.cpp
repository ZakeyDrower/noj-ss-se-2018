// 8 queens alg. without input.
// output as below:
// No 1:
// A.......
// ....A...
// .......A
// .....A..
// ..A.....
// ......A.
// .A......
// ...A....
// No 2:
// A.......
// .....A..
// .......A
// ..A.....
// ......A.
// ...A....
// .A......
// ....A...

// 穷举算法的弊端：不能按序输出
// 解决思路：使用全排列解决输出顺序问题

#include <iostream>
using namespace std;

int g_count_ans = 0;

void permutation(int *arr, int l, int r);
bool is_8queens_ans(int *arr);
void print_queens_table(int *arr);
void swap(int *arr, int a, int b);

int main()
{
    int *queen_index_array = new int[8]();
    for (int i = 0; i < 8; i++)
        queen_index_array[i] = i;
    g_count_ans = 0;
    permutation(queen_index_array, 0, 7);
    return 0;
}

void permutation(int *arr, int l, int r)
{
    if (l == r) {
        if (is_8queens_ans(arr))
        {
            print_queens_table(arr);
        }
    }else{
        for (int i = l; i <= r; i++){
            swap(arr, i, l);
            permutation(arr, l + 1, r);
            swap(arr, i, l);
        }
    }
}

bool is_8queens_ans(int *arr)
{
    for (int i = 0; i < 8 - 1; i++){
        for (int j = i + 1; j < 8; j++){
            if (labs(i - j) == labs(arr[i] - arr[j]))
                return false;
        }
    }
    return true;
}

void print_queens_table(int *arr)
{
    cout << "No " << ++g_count_ans << ":" << endl;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(j==arr[i])
                cout << "A";
            else
                cout << ".";
        }
        cout << endl;
    }
}

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}