class Solution {
public:
    int find(int n) {
        int sum = 0;
        while(n) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>> temp;
        for(auto &i: nums) {
            temp.push_back({find(i),i});
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            mpp[nums[i]] = i;
        }
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] == temp[i].second) continue;
            int ind = mpp[temp[i].second];
            cnt++;
            swap(nums[i],nums[ind]);
            mpp[nums[ind]] = ind;
        }
        return cnt;
    }
};