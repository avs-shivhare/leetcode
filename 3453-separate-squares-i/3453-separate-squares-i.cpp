class Solution {
public:
    double check(vector<vector<int>>& arr, double mid) {
        double a=0;
        for (auto& s : arr) {
            double l=s[2], y0=s[1]+l; 
            if (mid>=y0) continue;

            double h=min(l, y0-mid);
            a+=l*h;
        }
        return a;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double l = 1e10, r = 0;
        for (auto i : squares) {
            r = max(r,(double) i[1]+i[2]); 
            l = min(l,(double)i[1]);
        }
        double area = check(squares,-1e9);
        double a2 = area/2.0;
        while((r-l)> 1e-5) {
            double mid = (l+r)/2.0;
            //cout<<mid<<endl;
            auto ans = check(squares,mid);
            if(ans > a2) l = mid;
            else r = mid;
        }
        return l;
    }
};