class Solution {
public:
    bool isValid(string s) {
        int i = s.find("abc");
        while(i != string::npos) {
            s.erase(i,3);
            i= s.find("abc");
        }
        return s.empty();
    }
};