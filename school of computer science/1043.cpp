// 跳马问题
#include <iostream>
#include <queue>
using namespace std;

int x1, y1, x2, y2;
int m1, m2;
int step[200][200];
queue<int> q;

int bfs();
int moveto(int u, int dir);

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        m1 = (x1 - 1) * 200 + y1 - 1;
        m2 = (x2 - 1) * 200 + y2 - 1;
        while(!q.empty())
            q.pop();
        for (int i = 0; i < 200;i++)
            for (int j = 0; j < 200;j++)
                step[i][j] = 0;
        cout << bfs() << endl;
    }
    return 0;
}

int bfs()
{
    int u;
    int row, col;
    int sr, sc;
    step[x1 - 1][y1 - 1] = 1;
    q.push(m1);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        sr = u / 200;
        sc = u % 200;

        for (int i = 0; i < 8; i++)
        {
            int v = moveto(u, i);
            row = v / 200;
            col = v % 200;
            if(row >= 0 && row < 200 && col >= 0 && col < 200)
                if(row == (x2-1) && col == (y2-1))
                {
                    return step[sr][sc];
                }
                else if(step[row][col] == 0)
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
    row = u / 200;
    col = u % 200;
    
    switch (dir)
    {
        case 0:
            row -= 1;
            col -= 2;
            break;
        case 1:
            row -= 2;
            col -= 1;
            break;
        case 2:
            row -= 2;
            col += 1;
            break;
        case 3:
            row -= 1;
            col += 2;
            break;
        case 4:
            row += 1;
            col += 2;
            break;
        case 5:
            row += 2;
            col += 1;
            break;
        case 6:
            row += 2;
            col -= 1;
            break;
        case 7:
            row += 1;
            col -= 2;
            break;
    }
    if(row < 0 || col < 0 || row >= 200 || col >= 200)
        return -1;
    else
        return row * 200 + col;
}