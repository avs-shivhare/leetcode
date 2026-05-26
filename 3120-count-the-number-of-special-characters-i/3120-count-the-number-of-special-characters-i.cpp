class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> mpp;
        int ans = 0;
        for(auto &i: word) {
            mpp[i]++;
        }
        for(char i = 'a'; i<='z'; i++) {
            ans += min(mpp[i],mpp[i-32]) > 0;
        }
        return ans;
    }
};