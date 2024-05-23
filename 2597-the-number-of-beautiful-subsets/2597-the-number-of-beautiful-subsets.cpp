class Solution {
public:
    int f(int i,int &n,vector<int> &temp,unordered_map<int,int> &mpp,vector<int> &nums,int &k) {
        if(i == n) {
            if(temp.size()>0) return 1;
            return 0;
        }
        int pick = 0,notPick = 0;
        int x = nums[i];
        notPick = f(i+1,n,temp,mpp,nums,k);
        if((x-k < 0 || !mpp[x-k]) && (x+k > 1000 || !mpp[x+k])) {
            mpp[nums[i]]++;
            temp.push_back(nums[i]);
            pick = f(i+1,n,temp,mpp,nums,k);
            temp.pop_back();
            mpp[nums[i]]--;
        }
        return pick+notPick;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> temp;
        unordered_map<int,int> mpp;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return f(0,n,temp,mpp,nums,k);
    }
};