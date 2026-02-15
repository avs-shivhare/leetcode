class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int c = 0;
        int i = 0;
        int n = a.size(),m = b.size();
        string ans = "";
        while(i<n && i<m) {
            int sum = (a[i]-'0')+(b[i]-'0')+c;
            ans += (sum%2)+'0';
            c = sum>>1;
            i++;
        }
        while(i<n) {
            int sum = (a[i]-'0')+c;
            ans += (sum%2)+'0';
            c = sum>>1;
            i++;
        }
        while(i<m) {
            int sum = (b[i]-'0')+c;
            ans += (sum%2)+'0';
            c = sum>>1;
            i++;
        } 
        if(c) ans += '1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};