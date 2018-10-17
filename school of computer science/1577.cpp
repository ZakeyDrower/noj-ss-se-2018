// 0-1 backpack, use dynamic plan
#include <iostream>
using namespace std;

// gloabl vars
int g_n; // number max:10
int g_c; // capacity

int main()
{
   cin >> g_n >>g_c;

        // init vars
        int w[100000] = {0};
        int p[100000] = {0};
        int dp[100000] = {0};
        // input
        for (int i = 0; i < g_n; i++)
            cin >> w[i];
        for (int i = 0; i < g_n; i++)
            p[i] = w[i];
        // get ans
        for (int i = 0; i < g_n; i++)
        {
            for (int c = g_c; c >= w[i]; c--)
            {
                dp[c] = max(dp[c], dp[c - w[i]] + p[i]);
            }
        }
        cout << dp[g_c] << endl;
    return 0;
}