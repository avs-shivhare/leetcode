class Solution {
public:
    int distinctPoints(string s, int k) {
        int a = 0,b = 0;
        for(auto i: s) {
            if(i == 'U') b++;
            else if(i == 'D') b--;
            else if(i == 'L') a--;
            else a++;
        } 
        unordered_map<char,int> mpp;
        int l = 0,r = 0;
        int n = s.size();
        set<pair<int,int>> st;
        while(r<n) {
            mpp[s[r]]++;
            while(l<r && r-l+1 > k) {
                mpp[s[l]]--;
                l++;
            }
            if(r-l+1 == k) {
                int x = a,y = b;
                for(auto i: mpp) {
                    if(i.first == 'U') {
                        y -= i.second;
                    }
                    else if(i.first == 'D') {
                        y += i.second;
                    }
                    else if(i.first == 'L') {
                        x += i.second;
                    }
                    else {
                        x -= i.second;
                    }
                }
                st.insert({x,y});
            }
            r++;
        }
        return st.size();
    }
};