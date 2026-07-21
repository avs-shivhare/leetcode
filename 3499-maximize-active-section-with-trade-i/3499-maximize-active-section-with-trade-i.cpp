class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> cnt,el;
        int n = s.size();
        int i = 0;
        int sum = 0;
        for(auto &i: s) sum += i-'0';
        while(i<n) {
            int j = i+1;
            while(j < n && s[i] == s[j]) j++;
            cnt.push_back(j-i);
            el.push_back(s[i]-'0');
            i = j;
        }
        int ans = sum;
        n = cnt.size();
        for(int i = 0; i<n; i++) {
            if(el[i]) {
                ans = max(ans,cnt[i]);
                if(i > 0 && i < n-1 && !el[i-1] && !el[i+1]) {
                    int temp = cnt[i-1]+cnt[i+1];
                    ans = max(ans,sum+temp);
                }
            }
        }
        return ans;
    }
};