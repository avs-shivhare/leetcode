class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> temp;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,vector<int>> mpp;
        int p = 0;
        mpp[temp[p].second].push_back(temp[p].second);
        for(int i = 1; i<n; i++) {
            if(temp[i].first-temp[i-1].first <= limit) mpp[temp[p].second].push_back(temp[i].second);
            else {
                p = i;
                mpp[temp[p].second].push_back(temp[i].second);
            }
        }
        p = 0;
        while(p<n) {
            int el = temp[p].second;
            sort(mpp[el].begin(),mpp[el].end());
            for(auto &i: mpp[el]) {
                nums[i] = temp[p].first;
                p++;
            }
        }
        return nums;
    }
};