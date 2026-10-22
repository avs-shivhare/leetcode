class Solution {
public:
    int find(vector<int> &arr,int &m) {
        int n = arr.size();
        int l = 0;
        vector<int> kmp(n,0);
        for(int i = 1; i<n; i++) {
            while(l>0 && arr[l] != arr[i]) l = kmp[l-1];
            if(arr[l] == arr[i]) l++;
            kmp[i] = l;
        }
        for(int i = 0; i<n; i++) {
            ///cout<<kmp[i]<<" ";
            if(kmp[i] >= m) return i-2*m;
        }
        return 1e9;
    }
    int find2(vector<int> &nums) {
        int n = nums.size();
        auto temp = nums;
        auto temp2 = nums;
        sort(temp.begin(),temp.end());
        sort(temp2.begin(),temp2.end(),greater<int>());
        temp.push_back(1e9);
        temp2.push_back(1e9);
        for(int i = 0; i<2*n; i++) {
            temp.push_back(nums[i%n]);
            temp2.push_back(nums[i%n]);
        }
        return min(find(temp,n),find(temp2,n)+1);
    }
    int minOperations(vector<int>& nums) {
        int ans = find2(nums);
        reverse(nums.begin(),nums.end());
        ans = min(ans,find2(nums)+1);
        if(ans >= 1e9) return -1;
        return ans;
    }
};