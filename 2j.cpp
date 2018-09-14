// 合并输出两个有序数组
#include <iostream>
using namespace std;

int main()
{
    int na, nb;
    int *a = new int(20);
    int *b = new int(20);

    cin >> na;
    for (int i = 0; i < na; i++)
        cin >> a[i];
    cin >> nb;
    for(int i = 0; i < nb; i++)
        cin >> b[i];

    int i, j;
    for (i = 0, j = 0; i < na && j < nb; ){
        if(a[i]<b[j])
            cout << a[i++] << endl;
        else
            cout << b[j++] << endl;
    }
    while(i<na)
        cout << a[i++] << endl;
    while(j<nb)
        cout << b[j++] << endl;

    return 0;
}