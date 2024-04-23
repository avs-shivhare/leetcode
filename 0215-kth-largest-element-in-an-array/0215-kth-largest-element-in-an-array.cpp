class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        int n = nums.size();
        int i =0;
        for( i =0; i<k; i++) {
            //cout<<nums[i]<<endl;
            q.push(nums[i]);
        }
        for(;i<n; i++) {
            if(q.top() < nums[i]) {
                //cout<<nums[i]<<endl;
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};