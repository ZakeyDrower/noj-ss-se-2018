// 0-1 backpack problem
//     -- MAX(SIGMA(Pi)), MIN(SIGMA(Ci))
// method 1: Greedy Alg (local optimal solution && global better solution)
// method 2: Dynamic Plan (selected)
//           T(f) = ??      S(f) = O(n^2) || S(f) = O(n)
// method 3: Enumeration (similar to exhaustive n-bit binary number) (selected)
//           T(f) = O(n!)   S(f) = O(n)
// [PS] multiple test data
#include <iostream>
#include <memory.h>
using namespace std;

/// method 2 global vars & funs declaration

/// method 3 global vars & func declaration
void enum_fun();
void init_enum_vars(int *w, int *p);
void exhaustive(int *arr, int index, int n, int c, int *w, int *p);
int is_valid_ans(int *arr, int c, int n, int *w, int *p);

int g_max_p;

// main
int main()
{
    enum_fun();
    return 0;
}

/// method 3
void enum_fun()
{
    int n = 1;       // number of things
    int c = 1;       // total capacity

    while (cin >> n >> c)
    {
        if(n==0 && c==0)
            return;
        int w[10] = {0}; // weight arr
        int p[10] = {0}; // price arr
        int arr[10] = {0};
        g_max_p = 0;
        for (int i = 0; i < n; i++)
            cin >> w[i];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        exhaustive(arr, 0, 10, c, w, p);

        cout << g_max_p << endl;
    }
}

void exhaustive(int *arr, int index, int n, int c, int *w, int *p)
{
    if(index == n)
    {
        // calculate sum(w) and sum(c)
        int temp = is_valid_ans(arr, c, n, w, p);
        g_max_p = temp > g_max_p ? temp : g_max_p;
    }
    else
    {
        arr[index] = 0;
        exhaustive(arr, index + 1, n, c, w, p);
        arr[index] = 1;
        exhaustive(arr, index + 1, n, c, w, p);
    }
}

// return total price if is an ans. if not, return 0
int is_valid_ans(int *arr, int c, int n, int *w, int *p)
{
    int sum_w = 0, sum_p = 0;
    for (int i = 0; i < n; i++)
    {
        sum_w += w[i] * arr[i];
        sum_p += p[i] * arr[i];
    }
    if (sum_w > c)
    {
        return 0;
    }
    else
    {
        return sum_p;
    }
}