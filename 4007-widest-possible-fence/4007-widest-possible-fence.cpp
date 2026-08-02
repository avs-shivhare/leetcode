class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long,int> mpp,res;
        for(auto &i: planks) {
            mpp[i]++;
            res[i]++;
        }
        vector<long long> arr;
        for(auto &i: mpp) arr.push_back(i.first);
        for(int i = 0; i<arr.size(); i++) {
            res[2ll*arr[i]] += mpp[arr[i]]>>1ll;
            for(int j = i+1; j<arr.size(); j++) {
                res[arr[i]+arr[j]] += min(mpp[arr[i]],mpp[arr[j]]);
            }
        }
        int ans = 0;
        for(auto &i: res) ans = max(ans,i.second);
        return ans;
    }
};