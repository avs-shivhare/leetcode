class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mpp;
        for(auto &i: s) mpp[i]++;
        string ans = "";
        char odd = '1';
        for(auto &i: mpp) {
            if(i.second&1) odd = i.first;
            int el = i.second>>1;
            while(el--) {
                ans += i.first;
            }
        }
        string temp = ans;
        reverse(temp.begin(),temp.end());
        if(odd != '1') return ans+odd+temp;
        return ans+temp;
    }
};