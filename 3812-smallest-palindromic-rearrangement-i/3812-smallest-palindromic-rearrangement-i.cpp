class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mpp;
        for(auto i: s) {
            mpp[i]++;
        }
        string ans = "";
        bool flag = false;
        for(auto &i: mpp) {
            if(i.second & 1) {
                flag = true;
            }
            int cnt = i.second/2;
            while(cnt--) {
                ans += i.first;
            }
            i.second %= 2;
        }
        for(auto i: mpp) {
            if(i.second) {
                ans += i.first;
                break;
            }
        }
        string temp = "";
        if(flag) {
            temp = ans.substr(0,ans.size()-1);
        }
        else temp = ans;
        reverse(temp.begin(),temp.end());
        return ans+temp;
    }
};