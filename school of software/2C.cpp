// prime number between [a, b]
#include <iostream>
using namespace std;

bool is_prime_num(int num)
{
    if(num==1)
        return false;
    for (int i = 2; i < num; i++)
        if(num%i == 0)
            return false;
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b;i++){
        if(is_prime_num(i))
            cout << i << endl;
    }

    return 0;
}
