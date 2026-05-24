class Solution {
public:
    long long find(vector<int> &arr,int k,int rem) {
        long long ans = 0;
        for(auto &i: arr) {
            if(i%k == rem) continue;
            else if(i%k > rem) {
                ans += min((i%k)-rem,k-(i%k)+rem);
            }
            else {
                ans += min(rem-(i%k),(i%k)+k-rem);
            }
        }
        return ans;
    }
    int minOperations(vector<int>& nums, int k) {
        vector<int> odd,even;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(i&1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        long long ans = LLONG_MAX;
        for(int i = 0; i<k; i++) {
            for(int j = 0; j<k; j++) {
                if(i == j) continue;
                ans = min(ans,find(odd,k,i)+find(even,k,j));
            }
        }
        return ans;
    }
};