class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0; i<n; i++) {
            unordered_map<int,int> mpp;
            map<int,int> mpp2;
            for(int j = i; j<n; j++) {
                mpp2[mpp[nums[j]]]--;
                if(mpp2[mpp[nums[j]]] <= 0) mpp2.erase(mpp[nums[j]]);
                mpp[nums[j]]++;
                mpp2[mpp[nums[j]]]++;
                if(mpp.size() == 1) ans = max(ans,j-i+1);
                else if(mpp2.size() == 2) {
                    int first = mpp2.begin()->first;
                    int second = next(mpp2.begin())->first;
                    //cout<<first<<" "<<second<<" -> "<<i<<" "<<j<<endl;
                    if(2ll*first == second) ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};