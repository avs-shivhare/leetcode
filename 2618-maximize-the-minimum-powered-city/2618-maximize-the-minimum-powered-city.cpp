class Solution {
public:
    bool check(vector<int> &arr,long long mid,int x,int k) {
        //cout<<mid<<endl;
        int n = arr.size();
        int l = 0, r= 0;
        long long sum = 0;
        vector<long long> prefix(n,0);
        while(r<n) {
            sum += arr[r];
            sum += prefix[r];
            while(l<r && r-l+1 > 2ll*x+1) {
                sum -= arr[l];
                sum -= prefix[l];
                l++;
            }
            if(r-l+1 == x+1) {
                if(sum < mid) {
                    long long diff = min(1ll*k,abs(mid-sum));
                    sum += diff;
                    prefix[r] += diff;
                    k -= diff;
                    if(sum < mid) {
                        //cout<<l<<" "<<r<<endl;
                        return false;
                    }
                }
            }
            else if(r-l+1 == 2ll*x+1) {
                if(sum < mid) {
                    long long diff = min(1ll*k,abs(mid-sum));
                    sum += diff;
                    prefix[r] += diff;
                    k -= diff;
                    if(sum < mid) {
                        //cout<<l<<" "<<r<<endl;
                        return false;
                    }
                }
            }
            r++;
        }
        while(l<n) {
            sum -= arr[l];
            sum -= prefix[l];
            l++;
            if(n-l == x+1) {
                if(sum < mid) {
                    long long diff = min(1ll*k,abs(mid-sum));
                    sum += diff;
                    prefix[r-1] += diff;
                    k -= diff;
                    if(sum < mid) {
                        //cout<<l<<" "<<r<<endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }
    long long maxPower(vector<int>& arr, int x, int k) {
        long long l = 0,r = accumulate(arr.begin(),arr.end(),0ll)+1ll*k;
        long long ans = 0;
        while(l<=r) {
            long long mid = (l+r)>>1ll;
            if(check(arr,mid,x,k)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};