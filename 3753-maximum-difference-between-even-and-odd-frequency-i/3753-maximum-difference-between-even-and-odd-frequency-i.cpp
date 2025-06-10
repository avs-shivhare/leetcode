class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int,int> mpp;
        for(auto i: s) {
            mpp[i]++;
        }
        int odd = 0,even = 1e9;
        for(auto i: mpp) {
            if(i.second&1) {
                odd = max(odd,i.second);
            }
            else even = min(even,i.second);
        }
        return odd-even;
    }
};