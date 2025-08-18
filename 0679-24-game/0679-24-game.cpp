class Solution {
public:
    bool find(vector<double> &arr) {
        if(arr.size() == 1) {
            return fabs(arr[0]-24.0) < 1e-6; 
        }
        int n = arr.size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i == j) continue;
                vector<double> next;
                for(int k = 0; k<n; k++) {
                    if(k == i || k == j) continue;
                    next.push_back(arr[k]);
                }
                double a = arr[i];
                double b = arr[j];
                vector<double> res = {a+b,a-b,b-a,a*b};
                if(fabs(a) > 1e-6) res.push_back(b/a);
                if(fabs(b) > 1e-6) res.push_back(a/b);
                for(auto x: res) {
                    next.push_back(x);
                    if(find(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> arr(cards.begin(),cards.end());
        return find(arr);
    }
};