class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k) return false;
        if(n == k) return true;
        unordered_map<char,int> mpp;
        for(auto i: s) {
            mpp[i]++;
        }
        int odd = 0,even = 0;
        for(auto i: mpp) {
            odd += i.second%2;
            even += i.second/2;
        }
        if(odd > k) return false;
        return true;
    }
};