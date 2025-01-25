class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> temp;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        vector<vector<pair<int,int>>> arr;
        for(int i = 0; i<n; i++) {
            if(arr.empty() || abs(arr.back().back().first - temp[i].first) > limit) {
                arr.push_back({temp[i]});
            }
            else {
                arr.back().push_back(temp[i]);
            }
        }
        for(auto i: arr) {
            vector<int> ind;
            for(auto x: i) {
                ind.push_back(x.second);
            }
            sort(ind.begin(),ind.end());
            for(int x = 0; x<i.size(); x++) {
                nums[ind[x]] = i[x].first;
            }
        }
        return nums;
    }
};