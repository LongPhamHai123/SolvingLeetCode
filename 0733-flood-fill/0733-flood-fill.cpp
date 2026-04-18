class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int original_color, int color) {
        int row = image.size();
        int col = image[0].size();
        if (original_color == color) return;
        if ( (sr < 0 || sr >= row) || (sc < 0 || sc >= col ){
            return;
        }
        image[sr][sc] = color;
        dfs( image,sr+1,sc, original_color, color);
        dfs( image,sr-1,sc, original_color, color);
        dfs( image,sr,sc+1, original_color, color);
        dfs( image,sr,sc-1, original_color, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original_color = image[sr][sc];
        if (original_color == color) return image;
        dfs(image,sr,sc, original_color, color);
        return image;
    }

};