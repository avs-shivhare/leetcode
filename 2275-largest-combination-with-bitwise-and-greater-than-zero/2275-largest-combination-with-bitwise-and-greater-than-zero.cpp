class Solution {
public:
    int largestCombination(vector<int>& can) {
        vector<int> cnt(32,0);
        for(auto i: can) {
            for(int j =0; j<32; j++) {
                if(i & (1<<j)) cnt[j]++;
            }
        }
        int temp = 0;
        for(auto i: cnt) {
            temp = max(temp,i);
        }
        return temp;
    }
};