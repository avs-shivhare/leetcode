class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(auto i: arr) {
            mpp[i]++;
        }
        for(auto i: target) {
            if(mpp.count(i)) {
                mpp[i]--;
                if(mpp[i] == 0) mpp.erase(i);
            }
            else return false;
        }
        if(mpp.empty()) return true;
        return false;
    }
};