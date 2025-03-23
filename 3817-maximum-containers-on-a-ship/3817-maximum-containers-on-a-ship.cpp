class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int deck = n*n;
        int cnt = (long long)maxWeight/(long long)w;
        return min(cnt,deck);
    }
};