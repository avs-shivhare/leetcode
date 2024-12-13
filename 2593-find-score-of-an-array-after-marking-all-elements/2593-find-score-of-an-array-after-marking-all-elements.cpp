class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int,int>> st;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            st.insert({nums[i],i});
        }
        long long ans = 0;
        while(st.size()) {
            auto x = st.begin();
            ans += x->first;
            if(x->second+1 < n) {
                st.erase({nums[x->second+1],x->second+1});
            }
            if(x->second-1 >= 0) {
                st.erase({nums[x->second-1],x->second-1});
            } 
            st.erase({x->first,x->second});
        }
        return ans;
    }
};