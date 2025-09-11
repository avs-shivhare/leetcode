class Solution {
public:
    string sortVowels(string s) {
        vector<int> ans;
        for(auto i: s) {
            char x = tolower(i);
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        int j = 0;
        for(auto &i: s) {
            char x = tolower(i);
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                i = ans[j];
                j++;
            }
        }
        return s;
    }
};