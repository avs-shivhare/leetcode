class Solution {
public:
    bool f(int i,int j,int &n,int &m,string &s,string &p) {
        if(i >= n && j>=m) return true;
        if(j>= m) return false;
        bool flag = false;
        if(i< n && (s[i] == p[j] || p[j] == '.') ) {
            flag = true;
        }
        if(j+1 < m && p[j+1] == '*') {
            bool fl = f(i,j+2,n,m,s,p);
            if(flag) {
                fl = fl || f(i+1,j,n,m,s,p);
            }
            return fl;
        }
        if(flag) {
            return f(i+1,j+1,n,m,s,p);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        return f(0,0,n,m,s,p);
    }
};