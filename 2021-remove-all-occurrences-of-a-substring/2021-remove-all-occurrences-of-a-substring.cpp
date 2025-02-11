class Solution {
public:
    string removeOccurrences(string s, string part) {
        auto x = s.find(part);
        int n = part.size();
        while(x != string::npos) {
            s.erase(x,n);
            x = s.find(part);
        }
        return s;
    }
};