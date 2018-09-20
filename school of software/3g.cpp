// 大数乘法
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string c = "";

    // get and reverse big num1 and big num2
    // confirm +/- !!!!
    int flag = 0;
    string temp_s;
    cin >> temp_s;
    if (temp_s[0] == '-')
    {
        flag++;
        temp_s.erase(0, 1);
    }
    string a(temp_s.rbegin(), temp_s.rend());
    cin >> temp_s;
    if (temp_s[0] == '-')
    {
        flag++;
        temp_s.erase(0, 1);
    }
    string b(temp_s.rbegin(), temp_s.rend());

    int m = a.length();
    int n = b.length();
    // init resule c
    for (int i = 0; i < m + n; i++)
        c += "0";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num1 = ((int)b[i] - 48);
            int num2 = ((int)a[j] - 48);
            int num3 = ((int)c[i + j] - 48);
            int temp = ((int)b[i] - 48) * ((int)a[j] - 48) + ((int)c[i + j] - 48);
            c[i + j] = (char)(temp % 10 + 48);
            c[i + j + 1] = (char)(temp / 10 + 48) + ((int)c[i + j + 1] - 48);
        }
    }

    string ans(c.rbegin(), c.rend());

    while (ans[0] == '0')
    {
        ans.erase(0, 1);
    }

    if (ans.length() == 0)
        printf("0\n");
    else
    {
        if (flag % 2 == 1)
            printf("-");
        for (int i = 0; i < ans.length(); i++)
            printf("%c", ans[i]);
        printf("\n");
        //cout << ans << endl;
    }

    return 0;
}