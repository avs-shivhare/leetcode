class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int last = -1e9;
        int cnt = 0;
        sort(nums.begin(),nums.end());
        for(auto i: nums) {
            int prev = i-k;
            prev = max(prev,last+1);
            if(prev <= 1ll*i+k) {
                last = prev;
                cnt++;
            }
            //cout<<prev<<" "<<last<<" "<<i<<endl; 
        }
        return cnt;
    }
};