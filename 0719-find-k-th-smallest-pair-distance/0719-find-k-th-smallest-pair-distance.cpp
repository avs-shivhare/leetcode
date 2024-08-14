class Solution {
public:
    int find(vector<int> &nums,int dist) {
        int left = 0,right =0;
        int cnt = 0;
        int n = nums.size();
        for(right = 1; right<n ; right++) {
            while(nums[right]-nums[left] > dist) left++;
            cnt += right-left;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int right = nums[n-1]-nums[0];
        int left = 0;
        while(left < right) {
            int mid = left+(right-left)/2;
            int temp = find(nums,mid);
            if(temp >= k) right = mid;
            else left = mid+1;
        }
        return left;
    }
};