// 素数环
#include <iostream>
#include <vector>
using namespace std;

int count_ans = 0;
int iap[32] =
    {0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
     0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
     0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
     0, 1}; // isp : is a prime. max{n[i]+n[i+1]} = 31
vector<int *> rec_vec;

int ia[16] = {0};   // 保存输入的数字
int oa[16] = {0};   // 保存环中的数字
int used[17] = {0}; // 标记已经使用过的数字
int n = 0;

void dfs(int index);

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ia[i];

    dfs(0);

    cout << count_ans/n << endl;

    return 0;
}

void dfs(int index)
{
    if(index > 1)
        if(iap[oa[index-1]+oa[index-2]] == 0)
            return;
    
    if(index == n)
    {
        if(iap[oa[n-1] + oa[0]] == 1)
            //if(not_recorded(oa, n)) // 因为会包含所有的元素，所以一个环会有n中排列
                count_ans++;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if(used[ia[i]] == 0)
            {
                used[ia[i]] = 1;
                oa[index] = ia[i];
                dfs(index + 1);
                used[ia[i]] = 0;
            }
        }
    }    
}