class Solution {
public:
    vector<bool> prime;
    void find() {
        int n = 100003;
        prime.resize(n+1,true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 2; i*i<=n; i++) {
            if(prime[i]) {
                for(int j = i*i; j<=n; j+=i) {
                    prime[j] = false;
                }
            }
        }
        return;
    }
    int minOperations(vector<int>& nums) {
        find();
        int n = nums.size();
        vector<int> temp;
        for(int i = 2; i<=1e5+3; i++) {
            if(prime[i]) temp.push_back(i);
        }
        int ans = 0;
        for(int i = 0; i<n; i++) {
            if(i&1) {
                if(nums[i] == 2) ans += 2;
                else if(prime[nums[i]]) ans++;
            }
            else {
                //cout<<i<<" "<<nums[i]<<" "<<prime[nums[i]]<<endl;
                if(!prime[nums[i]]) {
                    int next = upper_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                    int maxi = 1e9;
                    if(next < temp.size()) maxi = min(maxi,temp[next]-nums[i]);
                    ans += maxi;
                }
            }
        }
        return ans;
    }
};