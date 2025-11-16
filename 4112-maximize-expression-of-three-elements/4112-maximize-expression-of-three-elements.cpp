class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos,neg;
        for(auto i: nums) {
            if(i<0) neg.push_back(i);
            else pos.push_back(i);
        }
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        int ans = -1e9;
        n = pos.size();
        int m = neg.size();
        if(n >=2) {
            if(m) ans = max(ans,pos[n-1]+pos[n-2]-neg.front());
            if(n > 2) ans = max(ans,pos[n-1]+pos[n-2]-pos.front());
        } 
        if(m >= 2) {
            if(n) ans = max(ans,neg.back()+pos.back()-neg.front());
            if(m > 2) ans = max(ans,neg.back()+neg[m-2]-neg.front());
        }
        return ans;
    }
};