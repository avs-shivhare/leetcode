class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mpp;
        for(auto i: s1) {
            mpp[i]++;
        }
        sort(s1.begin(),s1.end());
        int m = s1.size();
        int n = s2.size();
        for(int i =0; i<n && i+m<=n; i++) {
            if(mpp.count(s2[i])) {
                string temp = s2.substr(i,m);
                sort(temp.begin(),temp.end());
                if(temp == s1) return true;
            }
        }
        return false;
    }
};