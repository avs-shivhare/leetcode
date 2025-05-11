class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int cnt = 0;
        for(auto i: nums) {
            while(!st.empty() && st.top() > i) {
                st.pop();
            }
            if(st.empty() || st.top() < i) {
                if(i > 0) cnt++;
                st.push(i);
            }
        }
        return cnt;
    }
};