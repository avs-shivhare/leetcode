class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        priority_queue<int> maxi;
        priority_queue<int,vector<int>,greater<int>> mini;
        int sum = 0,sum2 = 0;
        for(auto i: nums) {
            if(mini.size() < k) {
                sum += i;
                mini.push(i);
            }
            else if(mini.top() < i) {
                sum -= mini.top();
                mini.pop();
                sum += i;
                mini.push(i);
            }
            if(maxi.size() < k) {
                sum2 += i;
                maxi.push(i);
            }
            else if(maxi.top() > i) {
                sum2 -= maxi.top();
                maxi.pop();
                sum2 += i;
                maxi.push(i);
            }
        }
        return abs(sum-sum2);
    }
};