class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l =0,r =0;
        vector<int> hash(256,0);
        int cnt =0,ind = -1,mini =INT_MAX;
        for(char i : t) {
            hash[i]++;
        }
        while(r<n) {
            if(hash[s[r]] >0) cnt++;
            hash[s[r]]--;
            while(cnt == m) {
                if(mini > r-l+1) {
                    mini = r-l+1;
                    ind = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        if(ind == -1) return "";
        return s.substr(ind,mini);
    }
};