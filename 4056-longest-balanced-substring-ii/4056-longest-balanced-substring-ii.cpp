class Solution {
public:
    int find(char x,char y,string &s) {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == x) sum++;
            else if(s[i] == y) sum--;
            else {
                mpp.clear();
                mpp[0] = i;
                sum = 0;
                continue;
            }
            if(mpp.find(sum) != mpp.end()) {
                ans = max(ans,i-mpp[sum]);
            }
            else mpp[sum] = i;
        }
        return ans;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        map<pair<int,int>,int> mpp;
        mpp[{0,0}] = -1;
        vector<int> cnt(3,0);
        for(int i = 0; i<n; i++) {
            cnt[s[i]-'a']++;
            int ab = cnt[0]-cnt[1];
            int ac = cnt[0]-cnt[2];
            if(mpp.find({ab,ac}) != mpp.end()) ans = max(ans,i-mpp[{ab,ac}]);
            else mpp[{ab,ac}] = i;
        }
        int len = 1;
        for(int i = 1; i<n; i++) {
            if(s[i-1] == s[i]) len++;
            else {
                ans = max(ans,len);
                len = 1;
            }
        }
        ans = max(ans,len);
        ans = max({ans,find('a','b',s),find('a','c',s),find('b','c',s)});
        return ans;
    }
};