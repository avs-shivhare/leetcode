class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> temp(n,0);
        for(int i = 0; i<n; i++) {
            int cnt = 0;
            for(int j = n-1; j>=0; j--) {
                if(grid[i][j] == 0) cnt++;
                else break;
            }
            temp[i] = cnt;
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            int index = -1;
            for(int j = i; j<n; j++) {
                if(temp[j] >= n-i-1) {
                    index = j;
                    break;
                }
            }
            if(index == -1) return -1;
            while(index > i) {
                swap(temp[index],temp[index-1]);
                ans++;
                index--;
            }
        }
        return ans;
    }
};