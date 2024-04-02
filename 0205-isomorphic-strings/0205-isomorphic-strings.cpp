class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> first,second;
        int n  = s.size();
        int m = t.size();
        if(n != m) return false;
        for(int i =0; i<n; i++) {
            if(first.find(s[i]) != first.end() || second.find(t[i]) != second.end()) {
                if(first[s[i]] != t[i] || second[t[i]] != s[i]) return false;
            }
            else {
                first[s[i]] = t[i];
                second[t[i]] = s[i];
            }
        }
        return true;
    }
};