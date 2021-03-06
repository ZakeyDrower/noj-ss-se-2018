
#include <iostream>
#include <algorithm>
using namespace std;
bool fa, fb;
 
void dfs(int a, int b, int k)
{
    //气球的三种状态，只要b＝1存在，那么b就没有说谎
    //没必要判断a=1的情况，只有fb为真，fa为假，b赢
    if(b == 1)
    {
        fb = true;
        if(a == 1)
            fa = true;
    }
    if(k == 1 || (fa&&fb))
        return;
    if(a % k == 0)          //气球被a踩了
        dfs(a/k, b, k-1);
    if(b% k == 0)           //气球被b踩了
        dfs(a, b/k, k-1);
    dfs(a, b, k-1);         //气球未被踩
 
}
int main()
{
    int a, b;
    while(cin >> a >> b && (a != 0 && b != 0))
    {
        if(a < b)
            swap(a, b);
        fa = fb = 0;
 
        dfs(a, b, 100);
 
        //只有fa为假，fb为真，b赢
        if(!fa && fb)
            cout << b << endl;
        else
            cout << a << endl;
    }
    return 0;
}