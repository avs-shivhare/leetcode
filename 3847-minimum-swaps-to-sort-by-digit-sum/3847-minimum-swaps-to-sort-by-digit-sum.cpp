class Solution {
public:
    int minSwaps(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            int digit = nums[i];
            int sum = 0;
            while(digit) {
                sum += digit%10;
                digit /= 10;
            }
            q.push({sum,nums[i]});
            mpp[nums[i]] = i;
        }
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            if(q.top().second == nums[i]) {
                q.pop();
            }
            else {
                int ind = mpp[q.top().second];
                mpp[nums[i]] = ind;
                swap(nums[i],nums[ind]);
                cnt++;
                q.pop();
            }
        }
        return cnt;
    }
};