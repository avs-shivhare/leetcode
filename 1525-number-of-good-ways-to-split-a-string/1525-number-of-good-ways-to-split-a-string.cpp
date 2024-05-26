class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        int n = s.size();
        vector<int> prefix(n,0),sufix(n,0);
        unordered_map<char,int> mpp,mpp1;
        for(int i =0; i<n; i++) {
            mpp[s[i]]++;
            prefix[i] = mpp.size();
        }
        for(int i =n-1; i>= 0; i--) {
            mpp1[s[i]]++;
            sufix[i] = mpp1.size();
        }
        for(int i =0;i<n-1; i++) {
            if(prefix[i] == sufix[i+1]) ans++;
        }
        return ans;
    }
};