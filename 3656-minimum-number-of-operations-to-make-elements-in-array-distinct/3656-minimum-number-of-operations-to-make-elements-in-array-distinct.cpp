class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int cnt = 0;
        for(auto i: nums) {
            if(mpp[i] == 1) cnt++;
            mpp[i]++;
        }
        int ans = 0;
        if(cnt == 0) return 0;
        for(auto i: nums) {
            mpp[i]--;
            if(mpp[i] == 1) cnt--;
            ans++;
            if(cnt == 0) break;
        }
        //cout<<ans<<endl;
        return (int)ceil((double)ans/3.0);
    }
};