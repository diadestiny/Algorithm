#include <iostream>
#include "myqueue.h"
using namespace std;
int m, n;
int MAZE[10][10];
int MARE[10][10] = {0};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
struct Node pre[10][10];
//pre数组用于保存路径信息
LinkQueue queue;
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
void BFS()
{
    InitQueue(queue);
    MARE[0][0] = 1;
    EnQueue(queue,Node(0,0));
    while (!IsEmpty(queue))
    {
        Node node = front(queue);
        DeQueue(queue);
        int r = node.r, c = node.c;
        for (int i = 0; i < 8; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && MARE[nr][nc] == 0 && MAZE[nr][nc] == 0)
            {
                MARE[nr][nc] = 1;
                EnQueue(queue,Node(nr,nc));
                pre[nr][nc] = Node(r, c);
                if (nr == m - 1 && nc == n - 1)
                    return;
            }
        }
    }
}
int main()
{
    input();
    BFS();
    int cur_r = m - 1, cur_c = n - 1;
    Node route[100];
    int i = 0,k;
    while(1)
    {
        route[i] = Node(cur_r, cur_c);
        i++;
        if(cur_r==0&&cur_c==0) break;
        int r=cur_r,c=cur_c;
        cur_r=pre[r][c].r;
        cur_c=pre[r][c].c;
    }
    k = i - 1;
    for (i=1; k >= 0; k--,i++)
    {
        cout << "(" << route[k].r << "," << route[k].c << ")";
        if (i % 5 == 0)
            cout << endl;
        if (k)
            cout << "->";
    }

    return 0;
}