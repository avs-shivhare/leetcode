class Solution {
public:
    int countDaysTogether(string aa, string la, string ab, string lb) {
        int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ad = stoi(aa.substr(3,2));
        int am = stoi(aa.substr(0,2));
        int bd = stoi(ab.substr(3,2));
        int bm = stoi(ab.substr(0,2));
        int lad = stoi(la.substr(3,2));
        int lam = stoi(la.substr(0,2));
        int lbd = stoi(lb.substr(3,2));
        int lbm = stoi(lb.substr(0,2));
        int ans = 0;
        int s = max(am,bm);
        int e = min(lbm,lam);
        for(int i = s; i<e-1; i++) {
            ans += day[i];
        }
        if(s == e) {
            int sm = (am == bm ? max(ad,bd): am > bm ? ad: bd);
            int em = (lam == lbm ? min(lad,lbd): lam > lbm ? lbd: lad);
            ans += max(0,em-sm+1);
        }
        else if(s < e) {
            ans += max(0,day[s-1]-(am == bm ? max(ad,bd): am > bm ? ad: bd)+1);
            ans += (lam == lbm ? min(lad,lbd): lam > lbm ? lbd: lad);
        }
        return ans;
    }
};