class Solution {
public:
    vector<vector<int>> pas;
    int mod = 1e9+7;
    void build(int n) {
        pas.push_back({1});
        for(int i = 1; i<=n; i++) {
            vector<int> temp;
            temp.push_back(1);
            for(int j = 1; j<i; j++) {
                temp.push_back((pas.back()[j-1]+pas.back()[j])%mod);
            }
            temp.push_back(1);
            pas.push_back(temp);
        }
        return;
    }

    long long find(vector<int> &nums) {
        if(nums.size() <= 2) return 1;
        int root = nums[0];
        vector<int> left,right;
        for(int i = 1; i<nums.size(); i++) {
            if(nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        long long l = find(left);
        long long r = find(right);
        long long t = pas[left.size()+right.size()][left.size()];
        return l*r%mod*t%mod;
    }
    int numOfWays(vector<int>& nums) {
        build(nums.size());
        return (find(nums)-1+mod)%mod;
    }
};