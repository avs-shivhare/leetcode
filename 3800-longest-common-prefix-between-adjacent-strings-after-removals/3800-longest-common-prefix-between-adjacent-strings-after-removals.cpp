class Solution {
public:
    int common(string &x,string &y) {
        int n = min((int)x.size(),(int)y.size());
        for(int i = 0; i<n; i++) {
            if(x[i] != y[i]) return i;
        }
        return n;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> prefix(n+1,0),suffix(n+1,0);
        for(int i = 1; i<n; i++) {
            prefix[i] = max(prefix[i-1],common(words[i],words[i-1]));
        }
        for(int i = n-2; i>=0; i--) {
            suffix[i] = max(suffix[i+1],common(words[i],words[i+1]));
        }
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++) {
            int maxi = (i > 0 ? prefix[i-1] : 0);
            maxi = max(maxi,(i < n-1 ? suffix[i+1] : 0));
            if(i > 0 && i < n-1) maxi = max(maxi,common(words[i-1],words[i+1]));
            ans[i] = maxi;
        }
        return ans;
    }
};