class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int leftSum = 0,rightSum =0;
        int ans = 0;
        for(int i =0; i<k; i++) {
            leftSum += card[i];
        } 
        ans = leftSum;
        int right = n-1;
        for(int i =k-1; i>=0; i--) {
            leftSum -= card[i];
            rightSum += card[right--];
            ans = max(ans,leftSum+rightSum);
        }
        return ans;
    }
};