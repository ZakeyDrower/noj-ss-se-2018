#include <iostream>
#include <queue>
 
using namespace std;
 
int x1, y1, x2, y2;
int m1, m2;
int a[12][12];
int step[12][12];
queue<int>q;
 
int search();
int moveto(int u, int dir);
 
int main()
{
    char x;
    int key;
    cin >> x1 >> y1 >> x2 >> y2;
    m1 = (x1-1) * 12 + y1-1;
    m2 = (x2-1) * 12 + y2-1;
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            cin >> x;
            if(x == 'X')a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
 
    /*for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }*/
 
    key = search();
    cout << key << endl;
 
   /* for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            cout <<  step[i][j] ;
            if(step[i][j] / 10 >= 1)cout << " ";
            else cout << "  ";
        }
        cout << endl;
    }*/
 
}
 
int search()
{
    int u;
    int row, col;
    int sr, sc;
 
    step[x1-1][y1-1] = 1;
 
    q.push(m1);
 
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        sr = u / 12;
        sc = u % 12;
 
        for(int i = 0; i < 4; i++)
        {
            int v = moveto(u,i);
            row = v / 12;
            col = v % 12;
            if(row == (x2-1) && col == (y2-1) && row >= 0 && row <= 11 && col >= 0 && col <= 11)
            {
 
                return (step[sr][sc]);
            }
            if(row >= 0 && row <= 11 && col >= 0 && col <= 11 && step[row][col] == 0 && a[row][col] == 0)
            {
                q.push(v);
                step[row][col] = step[sr][sc] + 1;
            }
        }
 
    }
 
}
 
int moveto(int u, int dir)
{
    int row, col;
    row = u / 12;
    col = u % 12;
    switch(dir)
    {
        case 0 : row++;break;
        case 1 : row--;break;
        case 2 : col++;break;
        case 3 : col--;break;
    }
 
    if(row < 0 || col < 0 ||row > 11 || col > 11) return (-1);//注意越界问题
    else return (row * 12 + col);
}