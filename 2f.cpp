// 幸运的编号，循环链表,Vector
#include <iostream>
#include <vector>
using namespace std;
/*
typedef struct Node
{
    int index;
    struct Node *next;
}Node, *Nodelist;
*/

int main()
{
    int n, m;
    vector<int> vec;
    cin >> n >> m;
    // init vector
    for (int i = 1; i <= n; i++)
        vec.push_back(i);

    int index = 0;
    while(vec.size()>1)
    {
        index = (index + m - 1) % vec.size();
        //cout << "delete : " << vec[index-1] <<" size : " << vec.size() << endl;
        vec.erase(vec.begin() + index);
    }
    cout << vec[0] << endl;
    return 0;
}