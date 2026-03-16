class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> fsum(n,vector<int>(m,0)),rsum(n,vector<int>(m,0));
        for(int i = 0; i<n; i++) {
            int r = i,c = 0;
            int sum = 0;
            while(r>=0 && c<m) {
                sum += grid[r][c];
                fsum[r][c] = sum;
                r--;
                c++;
            }
        }
        for(int i = 1; i<m; i++) {
            int r = n-1,c = i;
            int sum = 0;
            while(r>=0 && c<m) {
                sum += grid[r][c];
                fsum[r][c] = sum;
                r--;
                c++;
            }
        }
        for(int i = 0; i<n; i++)  {
            int r = i,c = 0;
            int sum = 0;
            while(r<n && c < m) {
                sum += grid[r][c];
                rsum[r][c] = sum;
                r++;
                c++;
            }
        }
        for(int i = 1; i<m; i++) {
            int r = 0,c = i;
            int sum = 0;
            while(r<n && c < m) {
                sum += grid[r][c];
                rsum[r][c] = sum;
                r++;
                c++;
            }
        }
        int f = INT_MIN,s = INT_MIN,t = INT_MIN;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] > f) {
                    t = s;
                    s = f;
                    f = grid[i][j];
                }
                else if(grid[i][j] < f && grid[i][j] > s) {
                    t = s;
                    s = grid[i][j];
                }
                else if(grid[i][j] < f &&  grid[i][j] < s && grid[i][j] > t) {
                    t = grid[i][j];
                }
                int cnt = 1;
                while(i-cnt>=0 && j+cnt < m && i+cnt < n && j+cnt<m) {
                    if(i-cnt+cnt < n && j+cnt+cnt < m) {
                        int sum1 = fsum[i-cnt][j+cnt]-fsum[i][j]+grid[i][j];
                        int sum2 = fsum[i-cnt+cnt][j+cnt+cnt]-fsum[i+cnt][j+cnt]+grid[i+cnt][j+cnt];
                        int sum3 = rsum[i-cnt+cnt][j+cnt+cnt]-rsum[i-cnt][j+cnt]+grid[i-cnt][j+cnt];
                        int sum4 = rsum[i+cnt][j+cnt]-rsum[i][j]+grid[i][j];
                        int com = grid[i][j]+grid[i-cnt][j+cnt]+grid[i+cnt][j+cnt]+grid[i-cnt+cnt][j+cnt+cnt];
                        int total = sum1+sum2+sum3+sum4-com;
                        if(total > f) {
                            t = s;
                            s = f;
                            f = total;
                        }
                        else if(total < f && total > s) {
                            t = s;
                            s = total;
                        }
                        else if(total < f && total < s && total > t) t = total;
                    }
                    cnt++;
                }
            }
        }
        vector<int> ans;
        if(f != INT_MIN) ans.push_back(f);
        if(s != INT_MIN) ans.push_back(s);
        if(t != INT_MIN) ans.push_back(t);
        return ans;
    }
};