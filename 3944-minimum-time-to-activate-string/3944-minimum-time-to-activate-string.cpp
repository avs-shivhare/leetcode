class Solution {
public:
    bool check(vector<int> &order,string s,int &k,int mid) {
        for(int i = 0; i<=mid; i++) {
            s[order[i]] = '*';
        }
        int n = s.size();
        vector<int> last(n,n-1);
        int x = n;
        for(int i = n-1; i>=0; i--) {
            if(s[i] == '*') x = i;
            last[i] = x;
        }
        long long cnt = 0;
        for(int i = 0; i<n; i++) {
            cnt += n-last[i];
        }
        //cout<<mid<<" "<<cnt<<endl;
        return cnt >= k;
    }
    int minTime(string s, vector<int>& order, int k) {
        int l = 0,r = s.size()-1;
        int ans = -1;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(check(order,s,k,mid)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};