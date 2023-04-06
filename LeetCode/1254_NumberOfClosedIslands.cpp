class Solution {
public:
    bool alldir(int i, int j, int row, int col, vector<vector<int>> &grid){
        if(i<0 || i==row || j<0 || j==col){
            return false;
        }
        if(grid[i][j] == 1){
            return true;
        }
        grid[i][j] = 1;
        
        int down = alldir(i+1, j, row, col, grid);
        int left = alldir(i, j-1, row, col, grid);
        int right = alldir(i, j+1, row, col, grid);
        int up = alldir(i-1, j, row, col, grid);
        
        if(up==1 && up==down && down == right && right == left){
            return true;
        }
        
        return false;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int row = grid.size(), col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 0){
                    count += alldir(i, j, row, col, grid);
                }
            }
        }
        return count;
    }
};
