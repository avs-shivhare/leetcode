class Solution {
public:
    bool check(vector<int> &nums,int k) {
        int last = 0;
        int n = nums.size();
        for(int i = 0; i<n; i+=k) {
            int cnt = 0;
            for(int j = i+1; j<i+k; j++) {
                if(nums[j-1] > nums[j]) cnt++;
            }
            if(nums[i] < nums[i+k-1]) cnt++;
            if(cnt > 1) return false;
            int temp = 0;
            for(int j = i; j<i+k; j++) {
                if(nums[j] < last) return false;
                temp = max(temp,nums[j]);
            }
            last = max(temp,last);
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sq = sqrt(n);
        for(int i = 1; i<=sq; i++) {
            if(n%i == 0) {
                if(check(nums,i)) ans += i;
                if(n/i != i && check(nums,n/i)) ans += n/i;
            }
        }
        return ans;
    }
};