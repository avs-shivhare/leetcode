class Solution {
public:
    int find(vector<int> &arr,long long el,long long &target) {
        int n = arr.size();
        int ans = n;
        int l = 0,r = n-1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(el*(long long)arr[mid] >= target) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        //cout<<ans<<" "<<el<<endl;
        return n-ans;
    }
    vector<int> successfulPairs(vector<int>& a, vector<int>& b, long long target) {
        vector<int> ans;
        sort(b.begin(),b.end());
        int n = a.size();
        for(int i = 0; i<n; i++) {
            ans.push_back(find(b,a[i],target));
        }
        return ans;
    }
};