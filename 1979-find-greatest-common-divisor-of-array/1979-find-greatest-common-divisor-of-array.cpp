class Solution {
public:
    int find(int a,int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a > b) return find(a%b,b);
        return find(a,b%a);
    }
    int findGCD(vector<int>& nums) {
        int mini = 1e9,maxi = -1e9;
        for(auto &i: nums) {
            mini = min(mini,i);
            maxi = max(maxi,i);
        }
        return find(mini,maxi);
    }
};