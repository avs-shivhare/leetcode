class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(k,0);
        set<long long> st;
        for(auto &i: nums) {
            int x = (1ll*i%k+k)%k;
            st.insert(1ll*temp[x]*k+x);
            temp[x]++;
        }
        //cout<<st.size()<<endl;
        int x = 0;
        while(st.find(x) != st.end()) x++;
        return x;
    }
};