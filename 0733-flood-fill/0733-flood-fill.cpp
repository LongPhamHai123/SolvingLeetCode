class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int original_color, int color) {
        int row = image.size();
        int col = image[0].size();

        // kiểm tra biên
        if (sr < 0 || sr >= row || sc < 0 || sc >= col) return;

        // kiểm tra màu khác gốc
        if (image[sr][sc] != original_color) return;

        // tô màu
        image[sr][sc] = color;

        // duyệt 4 hướng
        dfs(image, sr+1, sc, original_color, color);
        dfs(image, sr-1, sc, original_color, color);
        dfs(image, sr, sc+1, original_color, color);
        dfs(image, sr, sc-1, original_color, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color = image[sr][sc];
        if (original_color == color) return image; // tránh vòng lặp vô hạn
        dfs(image, sr, sc, original_color, color);
        return image;
    }

};