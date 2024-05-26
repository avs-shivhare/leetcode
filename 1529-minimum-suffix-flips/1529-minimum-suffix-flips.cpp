class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int i =0;
        //cout<<s<<endl;
        int one = 0,zero = 0;
        while(i<n && s[i] == '0') i++;
        while(i<n) {
            if(s[i] == '1') {
                while(i<n && s[i] == '1') i++;
                one++;
            }
            else {
                while(i<n && s[i] == '0') i++;
                zero++;
            }
        }
        return one+zero;
    }
};