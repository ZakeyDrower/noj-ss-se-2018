// 3n+1猜想
#include <iostream>
using namespace std;

int main()
{
    int num;
    int l = 1;
    cin >> num;
    while(num!=1)
    {
        if (num % 2 == 0)
        {
            num /= 2;
        }
        else
        {
            num = num * 3 + 1;
        }
        l++;
    }
    cout << l << endl;
    return 0;
}