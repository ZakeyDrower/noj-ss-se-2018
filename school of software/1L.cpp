// 转换二进制并从低位输出
#include <iostream>

using namespace std;

int main()
{
    __int64 num;
    cin >> num;

    while(num)
    {
        cout << num % 2 << endl;
        num /= 2;
    }

    return 0;
}