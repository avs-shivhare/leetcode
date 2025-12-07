class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        long long ans= 0;
        int n = t1.size();
        vector<vector<int>> temp;
        for(int i = 0; i<n; i++) {
            if(t1[i] >= t2[i]) {
                ans += t1[i];
                k--;
            }
            else temp.push_back({t2[i]-t1[i],t1[i],i});
        }
        sort(temp.begin(),temp.end());
        for(auto i: temp) {
            if(k > 0) {
                ans += i[1];
                k--;
            }
            else ans += t2[i[2]];
        }
        return ans;
    }
};