class Solution {
public:
    void invert(string &s) {
        for(auto &i: s) {
            if(i == '0') i ='1';
            else i = '0';
        }
        return;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        int i =1;
        while(i<n && k > s.size() ) {
            string t = s;
            invert(t);
            reverse(t.begin(),t.end());
            s += "1"+t;
            i++;
        }
        return s[k-1];
    }
};