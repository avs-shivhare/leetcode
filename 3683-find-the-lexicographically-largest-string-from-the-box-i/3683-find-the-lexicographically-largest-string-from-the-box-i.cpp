class Solution {
public:
    string answerString(string word, int x) {
        string ans = "";
        if(x == 1) return word;
        int n = word.size();
        int len = n-(x-1);
        for(int i = 0; i<n; i++) {
            string temp = word.substr(i,len);
            ans = max(ans,temp);
        }
        return ans;
    }
};