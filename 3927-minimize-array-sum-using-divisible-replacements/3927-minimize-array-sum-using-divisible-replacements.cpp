class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum = 0;
        unordered_set<int> st;
        for(auto &i: nums) {
            int el = 1e9;
            int sq = sqrt(i);
            for(int j = 1; j<=sq; j++) {
                if(i%j == 0) {
                    if(st.find(j) != st.end()) el = min(el,j);
                    if(st.find(i/j) != st.end()) el = min(el,i/j);
                }
            } 
            if(el == 1e9) {
                sum += i;
                st.insert(i);
            }
            else {
                sum += el;
            }
        }
        return sum;
    }
};