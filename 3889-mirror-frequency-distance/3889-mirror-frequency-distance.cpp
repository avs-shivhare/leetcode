class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int> mpp;
        for(auto &i: s) mpp[i]++;
        int sum = 0;
        for(auto &i: s) {
            char m = ' ';
            if('a' <= i && i <= 'z') {
                m = (25-(i-'a'))+'a';
            }
            else {
                m = (9-(i-'0'))+'0';
            }
            sum += abs(mpp[i]-mpp[m]);
            mpp[i] = 0;
            mpp[m] = 0;
        }
        return sum;
    }
};