class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++) {
            vector<int> temp;
            for(int j = 0; j<=i; j++) {
                if(j == 0 || j == i) temp.push_back(1);
                else {
                    temp.push_back(ans.back()[j]+ans.back()[j-1]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};