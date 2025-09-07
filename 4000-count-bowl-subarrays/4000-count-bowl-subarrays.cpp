class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long ans = 0;
        stack<int> st;
        int n = nums.size();
        vector<int> prefix(n,-1),suffix(n,-1);
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(!st.empty()) prefix[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i<n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(!st.empty()) suffix[i] = st.top();
            st.push(i);
        }
        for(int i = 0; i<n; i++) {
            if(prefix[i] != -1 && suffix[i] != -1) ans++;
        }
        return ans;
    }
};