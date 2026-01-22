class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        bool flag  = false;
        int ans = 0;
        while(!flag) {
            vector<int> temp;
            flag = true;
            int mini = 0;
            for(int i = 1; i<nums.size(); i++) {
                if(nums[i-1] > nums[i]) {
                    flag = false;
                }
                if(nums[mini]+nums[mini+1] > nums[i]+nums[i-1]) {
                    mini = i-1;
                }
            }
            if(flag) return ans;
            for(int i = 0; i<mini; i++) {
                temp.push_back(nums[i]);
            }
            temp.push_back(nums[mini]+nums[mini+1]);
            for(int i = mini+2; i<nums.size(); i++) {
                temp.push_back(nums[i]);
            }
            nums = temp;
            // for(auto i: temp) cout<<i<<" ";
            // cout<<endl;
            ans++;
        }
        return ans;
    }
};