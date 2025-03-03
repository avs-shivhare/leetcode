class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> great,less,equal;
        for(auto i: nums) {
            if(i < pivot) {
                less.push(i);
            }
            else if(i == pivot) equal.push(i);
            else great.push(i);
        }
        for(auto &i: nums) {
            if(!less.empty()) {
                i = less.front();
                less.pop();
            }
            else if(!equal.empty()) {
                i = equal.front();
                equal.pop();
            }
            else {
                i = great.front();
                great.pop();
            }
        }
        return nums;
    }
};