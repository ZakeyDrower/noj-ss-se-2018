// 回文质数
// 难点：时间优化，方法：剪枝，剪枝，剪枝
// 苦思冥想后的两个小时：奇怪，怎么还是超时
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

bool is_prime_num(__int64 num);
bool is_palin_num(__int64 num);
int count_bit(__int64 num);

int main()
{
    __int64 a, b;
    cin >> a >> b;

    for (__int64 i = a; i <= b; i++){
        if (i % 2 == 0 && i != 2)
            continue;
        if (i % 3 == 0 && i != 3)
            continue;
        if (i % 5 == 0 && i != 5)
            continue;
        int cb = count_bit(i);
        if (cb % 2 == 0 && i != 11){
            int s = 1;
            for (int j = 1; j <= cb; j++)
            {
                s *= 10;
            }
            i = s;
            continue;
        }
        // judge
        if (is_palin_num(i))
            if (is_prime_num(i))
                printf("%ld\n", i);
    }

    return 0;
}

bool is_prime_num(__int64 num)
{
    for (__int64 i = 2; i <= sqrt(num); i++)
        if(num%i == 0)
            return false;
    return true;
}

bool is_palin_num(__int64 num)
{
    // __int64 num_cp = num;
    // __int64 rev_num = 0;
    // while(num){
    //     rev_num = rev_num * 10 + num % 10;
    //     num /= 10;
    // }
    // if(num_cp==rev_num)
    //     return true;
    // return false;
    __int64 a[10];
    int count = 0;
    while(num)
    {
        count++;
        a[count] = num % 10;
        num /= 10;
    }
    int i = count;
    while (i > (count / 2))
    {
        if (a[i] != a[count + 1 - i])
            return false;
        i--;
    }
    return true;
}

int count_bit(__int64 num)
{
    int cb = 0;
    while(num)
    {
        num /= 10;
        cb++;
    }
    return cb;
}