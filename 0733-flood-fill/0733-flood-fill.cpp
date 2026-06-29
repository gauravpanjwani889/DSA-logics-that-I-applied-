class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &image, int initial_color, int new_color) {
        // Change the color of the current pixel
        image[row][col] = new_color;
        
        int n = image.size();
        int m = image[0].size();

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];

            // CRITICAL: Only move to neighbors matching the ORIGINAL starting color
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initial_color) {
                dfs(nrow, ncol, image, initial_color, new_color);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_color = image[sr][sc];
        
        // If the starting pixel already has the target color, doing anything will cause infinite recursion
        if (initial_color == color) {
            return image;
        }
        
        // Start the DFS process exactly once from the designated starting point
        dfs(sr, sc, image, initial_color, color);
        
        return image;
    }
};