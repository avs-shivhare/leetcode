class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> fre(maxi+1,0);
        for(auto &i: nums) {
            fre[i]++;
        }
        vector<long long> prefix(maxi+1,0);
        for(int i = maxi; i>0; i--) {
            for(int j = i; j<=maxi; j+=i) {
                prefix[i] += fre[j];
            }
            prefix[i] = (prefix[i]*(prefix[i]-1))>>1ll;
            for(int j = 2*i; j<=maxi; j+=i) {
                prefix[i] -= prefix[j];
            }
        }
        for(int i = 1; i<=maxi; i++) {
            prefix[i] += prefix[i-1];
        }
        // for(auto &i: prefix) cout<<i<<" ";
        // cout<<endl;
        vector<int> ans;
        for(auto &i: queries) {
            ans.push_back(lower_bound(prefix.begin(),prefix.end(),i+1)-prefix.begin());
        }
        return ans;
    }
};