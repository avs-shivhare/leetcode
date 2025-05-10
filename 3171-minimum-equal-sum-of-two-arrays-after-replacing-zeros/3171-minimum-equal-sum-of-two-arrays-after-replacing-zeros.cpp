class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int cnt = 0,cnt2 = 0;
        long long sum = 0,sum2 = 0;
        for(auto i: nums1) {
            if(i == 0) cnt++;
            sum += i;
        }
        for(auto i: nums2) {
            if(i == 0) cnt2++;
            sum2 += i; 
        }
        if(cnt) {
            sum += (cnt-1);
            cnt = 1;
        }
        if(cnt2) {
            sum2 += (cnt2-1);
            cnt2 = 1;
        }
        if(cnt == 0 && cnt2 == 0) {
            if(sum == sum2) return sum;
            return -1;
        }
        else if(cnt == 0 && cnt2) {
            if(sum > sum2) return sum;
            return -1;
        }
        else if(cnt && cnt2 == 0) {
            if(sum < sum2) return sum2;
            return -1;
        }
        return max(sum,sum2)+1;
    }
};