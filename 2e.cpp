// 最大公约数
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    while(a%b != 0){
        int remander = a % b;
        a = b;
        b = remander;
    }
    cout << b << endl;

    return 0;
}