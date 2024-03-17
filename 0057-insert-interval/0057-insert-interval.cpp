class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newin) {
        int n = inter.size();
        int i =0,j =0;
        if(n == 0) return {newin};
        bool flag = true;
        vector<vector<int>> ans;
        // if(newin[1] < inter[0][0]){ 
        //     ans.push_back(newin);
        //     flag = false;
        // }
        for(int i =0; i<n;i++) {
            if(newin[0] <= inter[i][0] && inter[i][0] <= newin[1] && flag) {
                ans.push_back({newin[0],max(inter[i][1],newin[1])});
                flag = false;
            }
            else if(inter[i][0] <= newin[0] && newin[0] <= inter[i][1] && flag) {
                ans.push_back({inter[i][0],max(inter[i][1],newin[1])});
                flag = false;
            }
            else if(!ans.empty() && inter[i][0] <= ans.back()[1]) {
                auto temp = ans.back();
                ans.pop_back();
                ans.push_back({temp[0],max(inter[i][1],temp[1])});
            }
            else {
                ans.push_back({inter[i][0],inter[i][1]});
            }
        }
        if(flag) {
            ans.push_back(newin);
            sort(ans.begin(),ans.end());
        }
        return ans;
    }
};