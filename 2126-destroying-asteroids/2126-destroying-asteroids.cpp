class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& as) {
        sort(as.begin(),as.end());
        long long sum = mass;
        for(auto &i: as) {
            if(sum >= i) {
                sum += i;
            }
            else return false;
        }
        return true;
    }
};