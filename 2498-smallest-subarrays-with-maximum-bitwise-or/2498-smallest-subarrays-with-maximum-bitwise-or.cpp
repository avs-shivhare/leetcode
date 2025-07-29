class Solution {
public:
    bool check(vector<int> &prev,vector<int> &fin,vector<int> &t) {
        for(int i = 0; i<32; i++) {
            //cout<<t[i]-prev[i]<<" "<<fin[i]<<endl;
            if(fin[i] && t[i]-prev[i] <= 0) return false;
        }
        return true;
    }
    int find(vector<int> &prev,vector<int> &fin,vector<vector<int>> &temp,int l,int r) {
        int ans = r;
        while(l<=r) {
            int mid = (l+r)>>1;
            //cout<<"checking for "<<mid<<" -> ";
            //cout<<l<<" "<<r<<" "<<mid<<endl;
            if(check(prev,fin,temp[mid])) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        //cout<<ans<<endl;
        return ans;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> temp(n);
        vector<int> cnt(32,0);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<32; j++) {
                if(nums[i] & (1<<j)) {
                    cnt[j]++;
                }
            }
            // cout<<i<<" -> ";
            // for(int j = 0; j<32; j++) {
            //     cout<<cnt[j]<<" ";
            // }
            // cout<<endl;
            temp[i] = cnt;
        }
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++) {
            vector<int> prev(32,0);
            if(i>0) {
                prev = temp[i-1];
            }
            vector<int> fin(32,0);
            fin = temp[n-1];
            //cout<<i<<" -> "<<endl;
            for(int j = 0; j<32; j++) {
                //curr[j] -= prev[j];
                fin[j] -= prev[j];
                //cout<<fin[j]<<" ";
            }
            //cout<<endl;
            ans[i] = find(prev,fin,temp,i,n-1)-i+1;
        }
        return ans;
    }
};