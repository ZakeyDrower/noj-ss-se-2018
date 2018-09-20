// 走迷宫
/*
INPUT:
3 3
0 0
2 2
0 0 0
1 1 0
0 1 0
OUPUT:
Yes
*/
#include <iostream>
using namespace std;

int m, n;           // matrix: m * n
int x1, x2, y1, y2; // (x1, y1) -> (x2, y2)
int **maze;         // maze matrix

int arrived = 0;

bool can_go(int x, int y);
void go(int x, int y, char dir);

int main()
{
    cin >> m >> n;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    maze = new int *[m];
    for (int i = 0; i < m; i++)
        maze[i] = new int[n]();
    // read maze
    for (int i = 0; i < m * n; i++)
        cin >> maze[i / n][i % n];
    // if (can_go(x1, y1 + 1))
    //     go(x1, y1 + 1, 'd');
    // if (arrived==0 && can_go(x1 - 1, y1))
    //     go(x1 - 1, y1, 'w');
    // if (arrived==0 && can_go(x1, y1 - 1))
    //     go(x1, y1 - 1, 'a');
    // if (arrived==0 && can_go(x1 + 1, y1))
    //     go(x1 + 1, y1, 's');
    go(x1, y1, ' ');
    if(arrived == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

void go(int x, int y, char dir)
{
    if(arrived == 0)
    {
        if(x==x2 && y==y2)
        {
            arrived = 1;
        }
        else
        {
            maze[x][y] = 1; // imporve efficiency !
            
            switch (dir)
            {
                case 'w':
                    if(can_go(x, y+1)) go(x, y+1, 'd');
                    if(can_go(x-1, y)) go(x-1, y, 'w');
                    if(can_go(x, y-1)) go(x, y-1, 'a');
                    break;
                case 'a':
                    if(can_go(x-1, y)) go(x-1, y, 'w');
                    if(can_go(x, y-1)) go(x, y-1, 'a');
                    if(can_go(x+1, y)) go(x+1, y, 's');
                    break;
                case 's':
                    if(can_go(x, y-1)) go(x, y-1, 'a');
                    if(can_go(x+1, y)) go(x+1, y, 's');
                    if(can_go(x, y+1)) go(x, y+1, 'd');
                    break;
                case 'd':
                    if(can_go(x+1, y)) go(x+1, y, 's');
                    if(can_go(x, y+1)) go(x, y+1, 'd');
                    if(can_go(x-1, y)) go(x-1, y, 'w');
                    break;
                default:
                    if(can_go(x-1, y)) go(x-1, y, 'w');
                    if(can_go(x, y-1)) go(x, y-1, 'a');
                    if(can_go(x+1, y)) go(x+1, y, 's');
                    if(can_go(x, y+1)) go(x, y+1, 'd');
                    break;
            }
        }
    }
}

bool can_go(int x, int y)
{
    if (x >= 0 && x < m && y >= 0 && y < n)
        if (maze[x][y] == 0) // (x, y) is not wall and not been here before
            return true;
    return false;
}