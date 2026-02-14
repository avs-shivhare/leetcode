class Solution {
public:
    double champagneTower(int p, int q, int ql) {
        vector<double> arr = {1.0*p};
        while(q--) {
            int n = arr.size();
            vector<double> temp(n+1,0);
            for(int i = 0; i<=n; i++) {
                double x = 0;
                if(i < n) x += max(0.0,(arr[i]-1)/2.0);
                if(i > 0) x += max(0.0,(arr[i-1]-1)/2.0);
                temp[i] = x;
            }
            arr = temp;
        }
        if(arr[ql] >= 1) return 1.0;
        return arr[ql];
    }
};