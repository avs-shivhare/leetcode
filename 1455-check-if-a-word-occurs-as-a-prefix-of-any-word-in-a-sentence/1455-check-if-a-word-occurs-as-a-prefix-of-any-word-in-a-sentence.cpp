class Solution {
public:
    int isPrefixOfWord(string sen, string se) {
        int cnt = 1;
        int n = se.size();
        stringstream s(sen);
        string temp = "";
        while(s>>temp) {
            if(temp.size() >= n && temp.substr(0,n) == se) return cnt;
            cnt++; 
        }
        return -1;
    }
};