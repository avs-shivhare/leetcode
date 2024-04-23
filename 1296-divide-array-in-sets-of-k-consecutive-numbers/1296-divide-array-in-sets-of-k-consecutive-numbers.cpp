class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k != 0) return false;
        sort(nums.begin(),nums.end());
        vector<int> q;
        while(nums.size()) {
            int i =0;
            while(i<nums.size() && q.size() < k) {
                if(q.empty() || q.back() +1 == nums[i] || q.back()-1 == nums[i]) {
                    q.push_back(nums[i]);
                    nums.erase(nums.begin()+i);
                }
                else i++;
            }
            if(q.size() != k) return false;
            q.clear();
        }
        return true;
    }
};