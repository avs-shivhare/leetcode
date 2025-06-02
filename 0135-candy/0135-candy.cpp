class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> prefix(n,1),suffix(n,1);
        for(int i = 1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) prefix[i] += prefix[i-1];
        }
        int ans = max(prefix[n-1],suffix[n-1]);
        for(int i = n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) suffix[i] += suffix[i+1];
            ans += max(prefix[i],suffix[i]);
        }
        return ans;
    }
};