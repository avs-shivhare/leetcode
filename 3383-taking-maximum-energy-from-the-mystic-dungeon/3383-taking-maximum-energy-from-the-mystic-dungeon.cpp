class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        unordered_map<int,int> mpp;
        int ans = -1e9;
        for(int i = n-1; i>=0; i--) {
            int sum = energy[i]+mpp[i+k];
            mpp[i] = sum;
            //cout<<i<<" "<<sum<<endl;
            ans = max(ans,mpp[i]);
        }
        return ans;
    }
};