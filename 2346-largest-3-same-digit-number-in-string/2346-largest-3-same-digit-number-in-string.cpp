class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();
        unordered_map<char,int> mpp;
        int l = 0,r = 0;
        int cnt = 0;
        while(r<n) {
            if(mpp[num[r]] == 0) cnt++;
            mpp[num[r]]++;
            while(l<r && r-l+1 > 3) {
                mpp[num[l]]--;
                if(mpp[num[l]] == 0) cnt--;
                l++;
            }
            if(cnt == 1 && r-l+1 == 3 && ans < num.substr(l,3)) {
                ans = num.substr(l,3);
            }
            r++;
        }
        return ans;
    }
};