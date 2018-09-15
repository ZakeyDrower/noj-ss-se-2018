// 8-Queens alg. -- + +|| xin sai !!!!
/* input:
1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0
0 0 0 0 0 0 1 0
1
output:
Yes
input:
1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 0 1 0 0 0
7
output:
Yes
*/

#include <iostream>
#include <math.h>
using namespace std;

void get_rest_indexs(int *known_indexs, int *rest_indexs);
void make_indexs_array(int *known_indexs, int *rest_indexs);
bool is_8queens_ans(int *known_indexs);

bool g_yes = false;

int main()
{
    int *queen_index_array = new int[4](); // chess table in one array.
    int q_index = 0; // index for queens

    // read first three queens
    for(int i=0;i<3;i++){
        for(int j=0;j<8;j++){
            int temp_int;
            cin >> temp_int;
            if(temp_int == 1)
                queen_index_array[q_index++] = j;
        }
    }
    // read the 4'th queen
    cin >> queen_index_array[q_index++];

    if(is_8queens_ans(queen_index_array))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

void make_indexs_array(int *known_indexs, int *rest_indexs)
{
    for (int i = 0; i < 4; i++)
        known_indexs[4 + i] = rest_indexs[i];
}

bool is_8queens_ans(int *known_indexs)
{
    for (int i = 0; i < 4 - 1; i++){
        for (int j = i + 1; j < 4; j++){
            if (labs(i - j) == labs(known_indexs[i] - known_indexs[j]))
                return false;
            if(known_indexs[i] == known_indexs[j])
                return false;
        }
    }
    return true;
}
