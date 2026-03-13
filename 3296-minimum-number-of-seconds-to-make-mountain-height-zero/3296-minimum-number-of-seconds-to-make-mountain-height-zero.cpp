class Solution {
public:
    long long find(long long &m,int el,int mm) {
        long long ans = 0;
        long long l = 1,r = mm;
        //cout<<l<<" "<<r<<" "<<m<<endl;
        while(l<=r) {
            long long mid = (l+r)>>1ll;
            long long temp = ((mid*(mid+1))>>1ll);
            if(temp <= m && temp*el <= m) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
    bool check(long long &mid,vector<int> &arr,int &m) {
        long long cnt = 0;
        for(auto &i: arr) {
            if(mid < i) continue;
            cnt += find(mid,i,m);
            if(cnt >= m) return true;
        }
        //cout<<cnt<<" "<<mid<<endl;
        return cnt >= m;
    }
    long long minNumberOfSeconds(int m, vector<int>& wt) {
        long long ans = 0;
        long long l = 1,r = 1e18;
        sort(wt.begin(),wt.end());
        //r = 1ll*m*(1ll*wt[0]*(wt[0]+1)>>1ll);
        while(l<=r) {
            long long mid = (l+r)>>1ll;
            if(check(mid,wt,m)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};