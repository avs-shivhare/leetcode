class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mpp;
        int n = s.size();
        int m = order.size();
        for(int i =0;i<n; i++) {
            mpp[s[i]]++;
        }
        string ans = "";
        for(int i =0;i<m; i++) {
            if(i>=n) break;
            while( mpp[order[i]] >=1) {
                ans += order[i];
                mpp[order[i]]--;
            }
        }
        for(auto i : mpp) {
            while(i.second >0) {
                ans += i.first;
                i.second--;
            }
        }
        return ans;
    }
};