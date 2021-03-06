// 电子老鼠闯迷宫
/*
2 9 11 8
XXXXXXXXXXXX
X......X.XXX
X.X.XX.....X
X.X.XX.XXX.X
X.X.....X..X
X.XXXXXXXXXX
X...X.X....X
X.XXX...XXXX
X.....X....X
XXX.XXXX.X.X
XXXXXXX..XXX
XXXXXXXXXXXX
*/
#include <iostream>
using namespace std;

int g_min_step = 150;
int x1, y1, x2, y2;
int maze[13][13] = {0};
int count = 0;
int arrived = 0;

bool can_go(int x, int y);
void go(int x, int y, char dir, int step);

int main()
{
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 1; i <= 12; i++)
        for (int j = 1; j <= 12; j++)
        {
            char temp;
            cin >> temp;
            if(temp == 'X')
                maze[i][j] = 1;
            else
                maze[i][j] = 0;
        }

    go(x1, y1, ' ', 0);
    if(arrived)
        cout << g_min_step << endl;
    else
        cout << '0' << endl;
    return 0;
}

void go(int x, int y, char dir, int step)
{
    if(x==x2 && y==y2)
    {
        arrived = 1;
        if(step < g_min_step)
            g_min_step = step;
        // cout << "step: " << step << endl;
    }
    else
    {
        maze[x][y] = 1; // imporve efficiency !
        
        switch (dir)
        {
            case 'w':
                if(can_go(x, y+1)) go(x, y+1, 'd', step+1);
                if(can_go(x-1, y)) go(x-1, y, 'w', step+1);
                if(can_go(x, y-1)) go(x, y-1, 'a', step+1);
                break;
            case 'a':
                if(can_go(x-1, y)) go(x-1, y, 'w', step+1);
                if(can_go(x, y-1)) go(x, y-1, 'a', step+1);
                if(can_go(x+1, y)) go(x+1, y, 's', step+1);
                break;
            case 's':
                if(can_go(x, y-1)) go(x, y-1, 'a', step+1);
                if(can_go(x+1, y)) go(x+1, y, 's', step+1);
                if(can_go(x, y+1)) go(x, y+1, 'd', step+1);
                break;
            case 'd':
                if(can_go(x+1, y)) go(x+1, y, 's', step+1);
                if(can_go(x, y+1)) go(x, y+1, 'd', step+1);
                if(can_go(x-1, y)) go(x-1, y, 'w', step+1);
                break;
            default:
                if(can_go(x-1, y)) go(x-1, y, 'w', step+1);
                if(can_go(x, y-1)) go(x, y-1, 'a', step+1);
                if(can_go(x+1, y)) go(x+1, y, 's', step+1);
                if(can_go(x, y+1)) go(x, y+1, 'd', step+1);
                break;
        }
        maze[x][y] = 0; // imporve efficiency !
    }
}

bool can_go(int x, int y)
{
    if (x >= 1 && x <= 12 && y >= 1 && y <= 12)
        if (maze[x][y] == 0) // (x, y) is not wall and not been here before
            return true;
    return false;
}