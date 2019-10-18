#include <iostream>
#include "mystack.h"
using namespace std;

const int maxm = 100, maxn = 100;
int MAZE[maxm][maxn], m, n;
int MARK[maxm + 2][maxn + 2];
int dx[8] = {-1,-1,-1,0,0,1,1,1}, dy[8] = {-1,0,1,-1,1,-1,0,1}; //记录移动的八个方位

//1表示障碍物 0表示空位
void input()
{
    cin >> m >> n;
    int t;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> t;
            MAZE[i][j] = t;
        }
    }
}
struct pos getMove(struct pos curr)
{
    struct pos next = curr;
    for (int i = 0; i < 8; i++)
    {
        int x = curr.first + dx[i], y = curr.second + dy[i];
        if (MAZE[x][y] == 0 && MARK[x][y] != 1 && x >= 0 && x < m && y >= 0 && y < n)
        {
            next.first = x;
            next.second = y;
            MARK[x][y] = 1;
            return next;
        }
    }
    return curr; //移动不了则返回当前位置
}
void dfs()
{
    Stack Path = createNullStack();
    struct pos curr, next;
    curr.first = 0;
    curr.second = 0;
    push(curr, Path);
    MARK[0][0] = 2;
    while (!isEmpty(Path))
    {
        curr = top(Path);
        next = getMove(curr);
        if (curr.first == next.first && curr.second == next.second) //如果是当前位置表示移动失败
        {
            pop(Path);
        }
        else
        {
            push(next, Path);
        }
        if (next.first == m - 1 && next.second == n - 1)
        {
            struct pos route[1000];
            int z = 0;
            while (!isEmpty(Path))
            {
                curr = top(Path);
                route[z++] = curr;
                pop(Path);
            }
            for (int k = z - 1; k >= 0; k--)
            {
                cout << "(" << route[k].first << "," << route[k].second << ")";
                if (k % 5 == 0)
                    cout << endl;
                if (k)
                    cout << "->";
            }
            return;
        }
    }
    cout << "noPath" << endl;
}
int main()
{
    input();
    dfs();
    return 0;
}