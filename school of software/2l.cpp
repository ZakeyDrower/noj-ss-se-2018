// 8-Queens alg.
// Convert to full permutation of 1~8 with prefixed four number. then check each permutation -> get answer
// eg:
//  O  X  X  X  X  X  X  X
//  X  X  X  X  X  X  O  X
//  X  X  X  X  O  X  X  X
//  X  X  X  X  X  X  X  O
//  X  O  X  X  X  X  X  X
//  X  X  X  O  X  X  X  X
//  X  X  X  X  X  O  X  X
//  X  X  O  X  X  X  X  X
//
/* input:
1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 0 1 0 0 0
2
output:
No
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
void permutation(int *known_indexs, int *rest_indexs, int l, int r);
void make_indexs_array(int *known_indexs, int *rest_indexs);
bool is_8queens_ans(int *known_indexs);
void swap(int *arr, int a, int b);

bool g_yes = false;

int main()
{
    int *queen_index_array = new int[8](); // chess table in one array.
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
    int *rest_indexs = new int[4]();
    // find rest indexs from 0-7. eg: ({0,6,4,2,0,0,0,0},{0,0,0,0}) -> {1,3,5,7}
    get_rest_indexs(queen_index_array, rest_indexs);

    // FULL PERMUTATION !!!
    permutation(queen_index_array, rest_indexs, 0, 3);
    if(g_yes)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

void get_rest_indexs(int *known_indexs, int *rest_indexs)
{
    int *pr = rest_indexs;
    for(int i=0; i<8;i++){
        bool flag = true;
        int *p = known_indexs;
        for(int j=0; j<4; j++){
            if(*(p++) == i) {flag=false; break;} // if index exists, pass
        }
        if(flag) *(pr++) = i; // if index not exists, store i
    }
}

void permutation(int *known_indexs, int *rest_indexs, int l, int r)
{
    if (l == r){
        // over
        make_indexs_array(known_indexs, rest_indexs);
        int* p = known_indexs;
        //for (int i=0; i<8;i++){
        //    cout << *(p++) << " ";
        //} cout << endl;
        if(is_8queens_ans(known_indexs))
            g_yes = true;
    } else {
        for (int i = l; i <= r; i++){
            swap(rest_indexs, i, l);
            permutation(known_indexs, rest_indexs, l + 1, r);
            swap(rest_indexs, i, l);
        }
    }
}

void make_indexs_array(int *known_indexs, int *rest_indexs)
{
    for (int i = 0; i < 4; i++)
        known_indexs[4 + i] = rest_indexs[i];
}

bool is_8queens_ans(int *known_indexs)
{
    for (int i = 0; i < 8 - 1; i++){
        for (int j = i + 1; j < 8; j++){
            if (labs(i - j) == labs(known_indexs[i] - known_indexs[j]))
                return false;
        }
    }
    return true;
}


void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
