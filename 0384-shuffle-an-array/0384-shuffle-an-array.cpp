class Solution {
public:
    //vector<vector<int>> temp;
    vector<int> original;
    int n = 0;
    Solution(vector<int>& nums) {
        original = nums; 
        n = nums.size();
    
    }
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int> ans(original);
        for(int i = n-1; i>=0; i--) {
            int val = rand()%(i+1);
            swap(ans[i],ans[val]);
        } 
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */