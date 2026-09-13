class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        map<pair<int,int>,int> mpp;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(img1[i][j] == 0) continue;
                for(int x = 0; x<n; x++) {
                    for(int y = 0; y<n; y++) {
                        if(img2[x][y] == img1[i][j]) {
                            mpp[{i-x,j-y}]++;
                            ans = max(ans,mpp[{i-x,j-y}]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};