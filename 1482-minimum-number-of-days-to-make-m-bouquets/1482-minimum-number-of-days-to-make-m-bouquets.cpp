class Solution {
public:
    int find(vector<int> &arr,int day,int adj) {
        int cnt = 0;
        int maxi = 0;
        for(int i: arr) {
            if(day >= i) {
                cnt++;
            }
            else {
                cnt = 0;
            }
            if(cnt == adj) {
                maxi++;
                cnt = 0;
            }
        }
        return maxi;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        long long n = bloom.size();
        if((long long)m*(long long)k > n) return -1;
        int maxi = *max_element(bloom.begin(),bloom.end());
        int low = 0,high = maxi;
        int ans = -1;
        while(low <= high) {
            int mid = (low+high)>>1;
            int temp = find(bloom,mid,k);
            if(m <= temp) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};