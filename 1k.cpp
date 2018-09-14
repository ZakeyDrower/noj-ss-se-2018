// 拆分数字并从低位到高位输出
#include <iostream>

using namespace std;

int main()
{
    __int64 num;
    cin >> num;
    while(num)
    {
        __int16 lb = num%10;
        num /= 10;
        cout << lb << endl;
    }
    return 0;
}