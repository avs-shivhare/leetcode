class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mpp;
        unordered_map<int,priority_queue<vector<int>>> mpp2;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            mpp2[nums[i]%3].push({nums[i],i});
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<3; j++) {
                while(!mpp2[j].empty() && mpp2[j].top()[1] <= i) mpp2[j].pop();
            }
            int curr = nums[i]%3;
            for(int j = 0; j<3; j++) {
                for(int k = 0; k<3; k++) {
                    if((j+k+curr)%3 == 0 && !mpp2[j].empty() && mpp.find(k) != mpp.end()) {
                        ans = max(ans,mpp[k]+nums[i]+mpp2[j].top()[0]);
                    }
                }
            }
            mpp[curr] = max(mpp[curr],nums[i]);
        }
        return ans;
    }
};