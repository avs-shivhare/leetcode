class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i<n; i++) {
            vector<int> temp;
            int x = i, y = 0;
            while(x < n && y < n) {
                temp.push_back(grid[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end(),greater<int>());
            int j = 0;
            x = i;
            y = 0;
            while(x < n && y < n) {
                grid[x][y] = temp[j];
                j++;
                x++;
                y++;
            }
        }
        for(int i = 1; i<n; i++) {
            int x = 0,y = i;
            vector<int> temp;
            while(x < n && y < n) {
                temp.push_back(grid[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x = 0;
            y = i;
            int j = 0;
            while(x < n && y < n) {
                grid[x][y] = temp[j];
                j++;
                x++;
                y++;
            }
        }
        return grid;
    }
};