class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int cap = 1e9,ind = -1;
        int n = capacity.size();
        for(int i = 0; i<n; i++) {
            if(capacity[i] >= itemSize && cap > capacity[i]) {
                cap = capacity[i];
                ind = i;
            }
        }
        return ind;
    }
};