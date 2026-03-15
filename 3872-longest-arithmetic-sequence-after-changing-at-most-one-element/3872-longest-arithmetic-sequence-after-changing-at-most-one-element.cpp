class Solution {
public:
    int longestArithmetic(vector<int>& arr) {
        int n = arr.size();
        vector<int> diff;
        for(int i = 1; i<n; i++) {
            diff.push_back(arr[i]-arr[i-1]);
        }
        vector<int> prefix(n,1),suffix(n,1);
        prefix[0] = 1;
        for(int i = 1; i<n-1; i++) {
            if(diff[i-1] == diff[i]) prefix[i] += prefix[i-1];
        }
        for(int i = n-3; i>=0; i--) {
            if(diff[i] == diff[i+1]) suffix[i] += suffix[i+1];
        }
        // for(auto i: diff) cout<<i<<" ";
        // cout<<endl;
        // for(auto i: prefix) cout<<i<<" ";
        // cout<<endl;
        // for(auto i: suffix) cout<<i<<" ";
        // cout<<endl;
        int ans = 3;
        for(int i = 0; i<n; i++) {
            int left = 0;
            int right = 0;
            if(i>1) {
                //if(i+1<n && arr[i-1]+2*diff[i-2] == arr[i+1]) ans = max(ans,prefix[i-2]+3);
                ans = max(prefix[i-2]+2,ans) ;
                left = prefix[i-2];
            }
            else if(i>0) left = 1;
            if(i+1<n-1) {
                //if(i>0 && arr[i-1]+2*diff[i+1] == arr[i+1]) ans = max(ans,suffix[i+1]+3);
                ans = max(ans,suffix[i+1]+2);
                right = suffix[i+1];
            }
            else if(i+1 < n) right = 1;
            if(left && right) {
                if(i>1 && arr[i-1]+2*diff[i-2] == arr[i+1]) {
                    ans = max(ans,left+right+2);
                }
                if(i+1<n-1 && arr[i-1]+2*diff[i+1] == arr[i+1]) {
                    ans = max(ans,left+right+2);
                }
                if(i+1<n-1 && i>1 && arr[i-1]+2*diff[i+1] == arr[i+1] && diff[i-2] == diff[i+1]) {
                    ans = max(ans,left+right+3);
                }
            }
        }
        return ans;
    }
};