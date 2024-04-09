class Solution {
public:
    int timeRequiredToBuy(vector<int>& T, int k) {
        int n = T.size();
        int i =0;
        int cnt =0;
        while(T[k] != 0) {
            if(T[i] == 0) {
                i = (i+1)%n;
                continue;
            }
            else {
                T[i]--;
                i = (i+1)%n;
                cnt++;
            }
        }
        return cnt;
    }
};