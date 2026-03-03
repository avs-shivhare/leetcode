class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while(n-- > 1) {
            string temp = s;
            for(auto &i: temp) {
                i = ((i-'0')+1)%2+'0';
            }
            reverse(temp.begin(),temp.end());
            s += "1";
            s += temp;
        }
        return s[k-1];
    }
};