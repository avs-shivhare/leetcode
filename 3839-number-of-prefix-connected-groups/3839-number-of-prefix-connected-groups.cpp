class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> mpp;
        for(auto &i: words) {
            if(i.size() < k) continue;
            string t = i.substr(0,k);
            mpp[t]++;
        }
        int ans = 0;
        for(auto &i: mpp) {
            if(i.second > 1) ans++;
        }
        return ans;
    }
};