class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        if(k == 0) return nums;
        vector<int> temp;
        for(auto &i: nums) {
            if(i >= 0) temp.push_back(i);
        }
        if(temp.empty()) return nums;
        k %= temp.size();
        reverse(temp.begin(),temp.begin()+k);
        reverse(temp.begin()+k,temp.end());
        reverse(temp.begin(),temp.end());
        int j = 0;
        for(auto &i: nums) {
            if(i>=0) {
                i = temp[j++];
            }
        }
        return nums;
    }
};