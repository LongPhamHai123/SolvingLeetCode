class Solution {
public:
    int n;
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>>& queue) {
        if ( i <0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return;
        grid[i][j] = 2;
        queue.push({i,j});
        for (auto& dir: directions) dfs(grid, i + dir[0], j + dir[1], queue);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool found = false;
        queue <pair<int,int>> queue;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j , queue);
                    found = true;
                }
            }
        }
        int steps = 0;
        while (!queue.empty()) {
            int size = queue.size();
            while (size) {
                auto [x,y] = queue.front(); queue.pop();
                for (auto& dir: directions) {
                    int dx = x + dir[0];
                    int dy = y + dir[1];
                    if (dx < 0 || dx >=n || dy < 0 || dy >= n) continue;
                    if (grid[dx][dy] == 1) return steps;
                    if (grid[dx][dy] == 0) {
                        grid[dx][dy] = 2;
                        queue.push({dx,dy});
                    }
                }
                size--;
            }
            steps++;
        }
        return -1;
    }
};