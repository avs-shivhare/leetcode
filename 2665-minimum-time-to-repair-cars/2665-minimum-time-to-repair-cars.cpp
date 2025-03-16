class Solution {
public:
    long long find(long long rank,long long &maxi,long long car) {
        long long ans = 0;
        long long l = 0,r = car;
        while(l<=r) {
            long long mid = (l+r)>>1;
            if(rank*(mid*mid) <= maxi) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
    bool check(vector<int> &rank,long long &mid,long long cars) {
        for(auto i: rank) {
            cars -= find(i,mid,cars);
        }
        return cars <= 0;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1,r = *max_element(ranks.begin(),ranks.end());
        r *= (long long)cars*(long long)cars;
        long long ans = r;
        while(l<=r) {
            long long mid = (l+r)>>1;
            if(check(ranks,mid,cars)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};