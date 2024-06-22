class Solution {
public:
    int find(vector<int> &nums,int k) {
        int n = nums.size();
        int i =0,j =0;
        int odd = 0,ans = 0;
        while(i<n) {
            if(nums[i]&1) odd++;
            while(j<i && odd > k) {
                if(nums[j] & 1) odd--;
                j++;
            }
            if(odd <= k) ans += i-j+1;
            i++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return find(nums,k)-find(nums,k-1);
    }
};