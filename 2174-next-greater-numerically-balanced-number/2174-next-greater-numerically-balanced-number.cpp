class Solution {
public:
    int nextBeautifulNumber(int n) {
        long long nn = n+1;
        while(true) {
            unordered_map<int,int> mpp;
            string t = to_string(nn);
            bool flag = true;
            for(auto &i: t) {
                mpp[i-'0']++;
                if(mpp[i-'0'] > i-'0') {
                    flag = false;
                    break;
                }
            }
            for(auto i: mpp) {
                if(i.first != i.second) {
                    flag = false;
                    break;
                }
            }
            if(flag) return nn;
            nn++;
        }
        return -1;
    }
};