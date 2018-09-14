// 幸运的编号进阶版——《选太子》，双向循环链表, Vector
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    vector<int> vec;
    cin >> n >> m;
    // init vector
    for (int i = 1; i <= 2*n; i++)
        vec.push_back(i);

    int index = 0;
    while(vec.size()>1)
    {
        index = (index + m - 1) % vec.size();
        //cout << "delete : " << vec[index] << endl;
        // 当第m个人呗淘汰的时候
        if(vec[index]==n){
            // 淘汰
            vec.erase(vec.begin() + index); 
            // 倒转vector 调整下标
            vector<int> newvec;
            while(!vec.empty()){
                newvec.push_back(vec[vec.size()-1]);
                vec.pop_back();
            }
            vec = newvec;
            index = index - 1;
            if(index<0) // 如果左溢出，尾部填补
                index += vec.size();
            index = vec.size() - (index + 1);
            continue;
        }
        // 淘汰
        vec.erase(vec.begin() + index);        
    }
    cout << vec[0] << endl;
    return 0;
}