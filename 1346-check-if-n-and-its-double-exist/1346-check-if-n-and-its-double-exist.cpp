class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(auto i: arr) mpp[i]++;
        for(auto i: arr) {
            if(mpp.count(2*i)) {
                if(i == 2*i) {
                    if(mpp[i] > 1) return true;
                }
                else return true;
            }
        }
        return false;
    }
};