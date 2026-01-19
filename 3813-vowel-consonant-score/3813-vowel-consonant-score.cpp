class Solution {
public:
    int vowelConsonantScore(string s) {
        int c = 0,v = 0;
        for(auto &i: s) {
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
                v++;
            }
            else if('a' <= i && i <= 'z') c++;
        }
        if(c>0) return v/c;
        return 0;
    }
};