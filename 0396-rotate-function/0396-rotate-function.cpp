class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int allSum = 0;
        int ans = 0;
        int n = nums.size();
        deque<int> q;
        for(int i =0; i<n; i++) {
            sum += (nums[i]*i);
            allSum += nums[i];
            q.push_back(nums[i]);
        }
        ans = sum;
        int i =0;
        while(i<n) {
            sum = sum-(q.back()*(n-1));
            int next = allSum-q.back();
            sum += next;
            int val = q.back();
            q.pop_back();
            q.push_front(val);
            ans = max(ans,sum);
            i++;
        }
        return ans;
    }
};