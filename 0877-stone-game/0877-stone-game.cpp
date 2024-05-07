class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int left = 0; int right = n-1;
        int alice  = 0, bob = 0;
        bool f = true;
        while(left <= right) {
            if(f) {
                if(piles[left] > piles[right]) {
                    alice += piles[left++];
                }
                else {
                    alice += piles[right--];
                }
            } 
            else {
                if(piles[left] < piles[right]) {
                    bob += piles[left++];
                }
                else {
                    bob += piles[right--];
                }
            }
            f = !f;
        }
        //cout<<alice<<" "<<bob<<endl;
        return alice > bob;
    }
};