class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        int sum = 0;
        int prevSum = 0;
        int j = -2;
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++) {
            sum ^= pref[i];
            if(j>= 0) {
                prevSum ^= pref[j];
            }
            j++;
            ans[i] = sum^prevSum;
        }
        return ans;
    }
};