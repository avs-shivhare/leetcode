class Solution {
public:
    bool prime(int x) {
        if(x < 2) return false;
        for(int i = 2; i*i<=x; i++) {
            if(x%i == 0) return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto i: nums) {
            mpp[i]++;
        }
        for(auto i: mpp) {
            if(prime(i.second)) return true;
        }
        return false;
    }
};