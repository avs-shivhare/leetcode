class Solution {
public:
    bool check(vector<long long> &arr,int &k,long long mid,long long side) {
        int n = arr.size();
        for(int i = 0; i<n; i++) {
            int cnt = 1;
            int j = i;
            while(cnt < k) {
                int ind = lower_bound(arr.begin(),arr.end(),arr[j]+mid)-arr.begin();
                if(ind == n) {
                    break;
                }
                j = ind;
                cnt++;
                if(mid+arr[j] > 4ll*side+arr[i]) {
                    cnt = 0;
                    break;
                }
            }
            if(cnt == k) return true;
        }
        return false;
    }
    int maxDistance(int n, vector<vector<int>>& points, int k) {
        long long l = 1,r = 1e12;
        long long ans = 0;
        vector<long long> res;
        for(auto &i: points) {
            if(i[1] == 0) res.push_back(1ll*i[0]);
            else if(i[0] == n) res.push_back(n+i[1]);
            else if(i[1] == n) res.push_back(3ll*n-i[0]);
            else res.push_back(4ll*n-i[1]);
        }
        sort(res.begin(),res.end());
        while(l<=r) {
            long long mid = (l+r)>>1ll;
            if(check(res,k,mid,n)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};