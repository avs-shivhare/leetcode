class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int> odd,even;
        int n = s1.size();
        for(int i = 0; i<n; i++) {
            if(i&1) odd[s1[i]]++;
            else even[s1[i]]++;
        }
        for(int i = 0; i<n; i++) {
            if(i&1) {
                if(odd.find(s2[i]) != odd.end()) {
                    odd[s2[i]]--;
                    if(odd[s2[i]] == 0) odd.erase(s2[i]);
                }
                else return false;
            }
            else {
                if(even.find(s2[i]) != even.end()) {
                    even[s2[i]]--;
                    if(even[s2[i]] == 0) even.erase(s2[i]);
                }
                else return false;
            }
        }
        return odd.empty() && even.empty();
    }
};