class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        int sum = accumulate(a.begin(),a.end(),0);
        sort(c.begin(),c.end(),greater<int>());
        int ans = 0;
        for(auto &i: c) {
            if(sum <= 0) break;
            ans++;
            sum -= i;
        }
        return ans;
    }
};