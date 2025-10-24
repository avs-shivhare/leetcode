class Solution {
public:
    int nextBeautifulNumber(int n) {
        long long nn = n+1;
        while(true) {
            vector<int> mpp(10,0);
            string t = to_string(nn);
            bool flag = true;
            for(auto &i: t) {
                mpp[i-'0']++;
                if(mpp[i-'0'] > i-'0') {
                    flag = false;
                    break;
                }
            }
            for(int i = 0; i<10; i++) {
                if(mpp[i] && mpp[i] != i) {
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