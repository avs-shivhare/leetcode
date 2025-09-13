class Solution {
public:
    int maxFreqSum(string s) {
        int cnt = 0,cnt2 = 0;
        unordered_map<char,int> mpp;
        for(auto i: s) {
            mpp[i]++;
        }
        for(auto i: mpp) {
            if(i.first == 'a' || i.first == 'e' || i.first == 'i' || i.first == 'o' || i.first == 'u') cnt = max(cnt,i.second);
            else cnt2 = max(cnt2,i.second);
        }
        return cnt+cnt2;
    }
};