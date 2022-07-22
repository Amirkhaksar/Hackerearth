/**
 * @file escapeFromGrid.cpp
 * @author amir aghazadeh (cssu-ama)
 * @brief 
 * @version 0.1
 * @date 2022-07-22
 * @id 259
 * @language cpp
 * @questionLink https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/escape-from-grid-google-ff752cb1/
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <queue>

using namespace std;
const int MAX = 1e3 + 5;
int grid[MAX][MAX], dist[MAX][MAX], n, m;
bool vis[MAX][MAX];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int bfs(int fromX, int fromY)
{
    queue <pair<int, int> > q;
    pair <int, int> p;
    dist[fromX][fromY] = 0;
    q.push({fromX, fromY});
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        fromX = p.first;
        fromY = p.second;
        if(fromX == 0 or fromX == n-1 or fromY == 0 or fromY == m-1)
            return dist[fromX][fromY];
        for(int i = 0;i < 4;++i)
        {
            int x = fromX + dr[i];
            int y = fromY + dc[i];
            if(x >= 0 and x < n and y >= 0 and y < m and grid[x][y] != 1 and vis[x][y] == false)
            {
                vis[x][y] = true;
                dist[x][y] = dist[fromX][fromY] + 1;
                q.push({x, y});
            }
        }
    }
    return -1;

}

int main()
{
    int ans, x, y;
    cin >> n >> m;
    for(int i = 0;i < n;++i) for(int j = 0;j < m;++j)
    {
        cin >> grid[i][j];
        vis[i][j] = false;
        dist[i][j] = 0;
        if(grid[i][j] == 2)
            x = i, y = j;
    }
    ans = bfs(x, y);
    cout << ans << endl;
    return 0;
}