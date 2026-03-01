class Solution {
public:
    string trimTrailingVowels(string s) {
        int i = s.size()-1;
        while(i>=0) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u') i--;
            else break;
        }
        return s.substr(0,i+1);
    }
};