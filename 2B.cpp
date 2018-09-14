// 1A改为1 2 4
#include <iostream>
using namespace std;

int main()
{
    int64_t num;
    cin >> num;
    
    if (num%3 == 0) {
        cout << "No" << endl;  
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}