class Solution {
public:
    long long maximumHappinessSum(vector<int>& happ, int k) {
        sort(happ.begin(),happ.end(),greater<int>());
        long long ans = 0;
        int n = happ.size();
        long long inc = 0;
        for(int i =0; i<n; i++) {
            if(happ[i]-inc > 0 && k) {
                ans += happ[i]-inc;
                inc++;
                k--;
            }
            else break;
        }
        return ans;
    }
};