class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        vector<int> hash(3,-1);
        for(int i =0; i<n; i++) {
            hash[s[i]-'a'] = i;
            if(hash[0] != -1 && hash[1] != -1 && hash[2] !=-1) {
                ans += 1+min(hash[0],min(hash[1],hash[2]));
            }
        }
        return ans;
    }
};