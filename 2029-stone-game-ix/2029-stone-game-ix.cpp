class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> arr(3,0);
        for(auto &i: stones) {
            arr[i%3]++;
        }
        if(arr[0]&1) {
            return abs(arr[1]-arr[2]) > 2;
        }
        return arr[1] > 0 && arr[2] > 0;
    }
};