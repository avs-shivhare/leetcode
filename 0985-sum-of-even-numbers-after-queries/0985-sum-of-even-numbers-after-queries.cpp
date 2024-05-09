class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n = q.size();
        int sum = 0;
        for(int i: nums) {
            if((i & 1) == 0) sum += i;
        }
        vector<int> ans(n,0);
        //cout<<sum<<endl;
        for(int i =0; i<n; i++) {
            int val = q[i][0];
            int ind = q[i][1];
            int temp = nums[ind];
            if((temp & 1) == 0) {
                if(((temp +val) & 1) ==0 ) {
                    sum += val;
                    nums[ind] += val;
                }
                else {
                    sum -= temp;
                    nums[ind] += val;
                }
            }
            else {
                if(((temp+val) & 1) == 0) {
                    sum += temp+val;
                    nums[ind] += val;
                }
                else {
                    nums[ind] += val;
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};