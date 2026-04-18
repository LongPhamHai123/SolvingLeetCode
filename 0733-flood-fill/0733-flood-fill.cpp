class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int original_color, int color) {
        int row = image.size();
        int col = image[0].size();

        // 1. Check boundary trước
        if (sr < 0 || sr >= row || sc < 0 || sc >= col) {
            return;
        }

        // 2. Chỉ fill khi đúng màu ban đầu
        if (image[sr][sc] != original_color) {
            return;
        }

        // 3. Tô màu
        image[sr][sc] = color;

        // 4. DFS 4 hướng
        dfs(image, sr + 1, sc, original_color, color);
        dfs(image, sr - 1, sc, original_color, color);
        dfs(image, sr, sc + 1, original_color, color);
        dfs(image, sr, sc - 1, original_color, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color = image[sr][sc];

        // Nếu màu giống nhau thì khỏi làm
        if (original_color == color) return image;

        dfs(image, sr, sc, original_color, color);
        return image;
    }
};