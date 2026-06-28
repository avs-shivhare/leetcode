class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans = 0;
        for(auto &i: arr) {
            if(ans+1 <= i) ans++;
        }
        return ans;
    }
};