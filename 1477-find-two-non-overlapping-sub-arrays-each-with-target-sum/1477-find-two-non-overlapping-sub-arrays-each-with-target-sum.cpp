class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<long long> prefix(n,0);
        prefix[0] = arr[0];
        for(int i = 1; i<n; i++) {
            prefix[i] = prefix[i-1]+arr[i];
        }
        // for(auto &i: prefix) cout<<i<<" ";
        // cout<<endl;
        vector<long long> suffix(n+1,1e9);
        for(int i = n-1; i>=0; i--) {
            int index = lower_bound(prefix.begin(),prefix.end(),prefix[i]-arr[i]+target)-prefix.begin();
            // cout<<i<<" "<<index<<endl;
            if(index < n && prefix[index]-prefix[i]+arr[i] == target) {
                suffix[i] = 1ll*index-i+1;
            }
        }
        for(int i = n-1; i>=0; i--) {
            suffix[i] = min(suffix[i],suffix[i+1]);
        }
        // for(auto &i: suffix) cout<<i<<" ";
        // cout<<endl;
        unordered_map<long long,int> mpp;
        long long sum = 0;
        mpp[0] = -1;
        long long ans = 1e9;
        for(int i = 0; i<n; i++) {
            sum += arr[i];
            long long rem = sum-target;
            if(mpp.find(rem) != mpp.end()) {
                //cout<<i<<" "<<mpp[i]<<endl;
                ans = min(ans,i-mpp[rem]+suffix[i+1]);
            }
            mpp[sum] = i;
            //cout<<sum<<" index "<<i<<endl;
        }
        if(ans >= 1e9) return -1;
        return ans;
    }
};