class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n,0);
        for(int i = 0; i<n; i++) {
            diff[i] = abs(nums1[i]-nums2[i]);
        }
        diff.push_back(0);
        sort(diff.begin(),diff.end(),greater<long long>());
        long long ans = 0;
        long long rem = 1ll*k1+k2;
        for(int i = 0; i<n; i++) {
            if((diff[i]-diff[i+1])*(i+1) <= rem) {
                rem -= (diff[i]-diff[i+1])*(i+1);
            }
            else {
                long long t = rem/(i+1);
                diff[i] -= t;
                rem -= t*(i+1);
                if(rem) {
                    ans = rem*((diff[i]-1)*(diff[i]-1));
                    ans += ((i+1)-rem)*(diff[i]*diff[i]);
                }
                else {
                    ans += (i+1)*(diff[i]*diff[i]);
                }
                cout<<ans<<" "<<i<<endl;
                for(int j = i+1; j<n; j++) {
                    ans += diff[j]*diff[j];
                }
                break;
            }
        }
        return ans;
    }
};