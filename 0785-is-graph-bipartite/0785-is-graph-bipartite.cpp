class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> queue;
        for (int i=0; i < n; i++) {
            if (color[i] == -1) {
                
                color[i] = 0;
                queue.push(i);
                while (!queue.empty()) {
                    int node = queue.front();
                    queue.pop();
                    for (int nei: graph[node]) {
                        if(color[nei] == -1) {
                            color[nei] = 1 - color[node];
                            queue.push(nei);
                        }else if (color[nei] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};