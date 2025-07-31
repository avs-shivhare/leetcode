class Solution {
public:
    unordered_set<int> st;
    bool check(vector<vector<int>> &prefix,vector<int> &curr,vector<int> &prev,int mid) {
        for(int j = 0; j<32; j++) {
            if(prefix[mid][j]-prev[j] > 0 && curr[j] == 0) return false;
        }
        return true;
    }
    int find(vector<vector<int>> &prefix,vector<int> &curr,vector<int> &prev,int l,int r) {
        int ans = r+1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(check(prefix,curr,prev,mid)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> prefix(n,vector<int>(32,0));
        vector<int> cnt(32,0);
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<32; j++) {
                if(arr[i] & (1<<j)) {
                    cnt[j]++;
                }
            }
            prefix[i] = cnt;
        }
        for(int i = 0; i<n; i++) {
            st.insert(arr[i]);
            vector<int> curr(32,0),prev(32,0);
            curr = prefix[i];
            if(i > 0) {
                prev = prefix[i-1];
                for(int j = 0; j<32; j++) {
                    curr[j] -= prefix[i-1][j];
                }
            }
            int l = i;
            do {
                l = find(prefix,curr,prev,l,n-1);
                //cout<<i<<" "<<l<<endl;
                l++;
                if(l<n) {
                    int x= 0;
                    for(int j = 0; j<32; j++) {
                        int k = prefix[l][j]-prev[j];
                        if(k>0) x |= (1<<j);
                        curr[j] = k;
                    }
                    st.insert(x);
                }
            }while(l<n);
        }
        // for(auto i: st) cout<<i<<" ";
        // cout<<endl;
        return st.size();
    }
};