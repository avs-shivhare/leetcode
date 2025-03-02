class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        set<vector<pair<int,int>>> st;
        for(int i = 0; i<n; i++) {
            if(i+k <= n) {
                vector<pair<int,int>> temp;
                for(int x = i; x<i+k; x++) {
                    temp.push_back({nums[x],x});
                }
                st.insert(temp);
            }
        }
        int ans = -1;
        unordered_map<int,vector<vector<pair<int,int>>>> mpp;
        for(auto i: st) {
            unordered_set<int> x;
            for(auto j: i) {
                if(x.count(j.first)) continue;
                mpp[j.first].push_back(i);
                x.insert(j.first);
            }
        }
        for(auto i: mpp) {
            if(i.second.size() == 1) ans = max(ans,i.first);
        }
        return ans;
    }
};