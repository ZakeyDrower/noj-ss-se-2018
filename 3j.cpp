// 素数环 == 暴力破解，逻辑正确，超时
// 想到一个方法，但是时间复杂度很高。我算算……O(N! * 2^N)（全排列嵌套穷举N位二级制，即01） , 10E19的数量级！！！
// n个数，n<=16,n[i]<=16  ==>> max{n[i]+n[i+1]}<32, min{n[i]+n[i+1]}>2
// 【重新考虑】上面思路没错，但是为了降低时间复杂度，考虑将全排列与二进制结合，即所谓“回溯”。也类似于“剪枝”的讲法，发现不对立马回头。
// 可以开始编码。
// 【重新考虑】不存在回溯。全排列时间省不了，每个排列下还有n的时间消耗。重新开始编码。
// 还有疑问：如何解决重复环？  ==》 记录所有环为数组

// 卧槽，我又把题看错了，这个是加强版。新开个文件做吧。
#include <iostream>
#include <vector>
using namespace std;

int count_ans = 0;
int iap[32] =
    {0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
     0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
     0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
     0, 1}; // isp : is a prime. max{n[i]+n[i+1]} = 31
vector<int*> rec_vec;

void permutation(int *arr, int index, int n);
bool is_prime_circle(int *arr, int arr_length);
bool not_recorded(int *arr, int arr_length);

int main()
{
    int n;
    int arr[16] = {0};

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    permutation(arr, 0, n);

    cout << count_ans << endl;
    // for (int i = 0; i < rec_vec.size();i++){
    //     for (int j = 0; j < 16;j++){
    //         cout << rec_vec[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

        return 0;
}

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// 以单元测试，除了find answer部分外没有任何问题
void permutation(int *arr, int index, int n)
{
    if(index == n-1)
    {
        // for (int i = 0; i < n;i++){
        //     cout << arr[i] << ' ';
        // }
        // cout << endl;
        // find answers
        for (int i = 3; i <= n; i++)
        {
            if (is_prime_circle(arr, i))
                if (not_recorded(arr, i))
                    count_ans++;
            }
    }
    else
    {
        for (int i = index; i < n; i++)
        {
            swap(arr, index, i);
            permutation(arr, index + 1, n);
            swap(arr, index, i);
        }
    }
}

bool is_prime_circle(int *arr, int n)
{
    for (int i = 0; i < n - 1;i++)
        if(iap[arr[i]+arr[i+1]] == 0)
            return false;
    if(iap[arr[0]+arr[n-1]]==0)
        return false;
    return true;
}

bool is_same_circle(int *a, int *b, int n)
{
    int i = 0, j = 0;
    // 找到首位相等的下标
    while(a[i] != b[j]){
        j++;
        if(j==n)
            return false;
    }
    // 判断是不是同一个环
    for (; i < n; i++)
    {
        if(a[i] != b[(j+i)%n])
            return false;
    }
    return true;
}

bool not_recorded(int *arr, int n)
{
    // 判断，如果已记录，返回false
    for (int i = 0; i < rec_vec.size(); i++)
        // 得到每条记录中的环
        if(is_same_circle(arr, rec_vec[i], n))
            return false;
    // 未记录，记录后返回ture
    int *rec = new int[n]();
    for (int i = 0; i < n; i++)
        rec[i] = arr[i];
        rec_vec.push_back(rec); 
    return true;
}