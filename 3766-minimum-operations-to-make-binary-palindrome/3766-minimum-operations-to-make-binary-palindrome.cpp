class Solution {
public:
    bool tobinary(int n) {
        string temp = "";
        while(n) {
            if(n&1) temp += '1';
            else temp += '0';
            n >>= 1;
        }
        int l = 0,r = temp.size()-1;
        while(l<r) {
            if(temp[l] != temp[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++) {
            int l = nums[i],r = nums[i];
            while(l > 0 && !tobinary(l)) l--;
            while(!tobinary(r)) r++;
            //cout<<l<<" "<<r<<endl;
            ans[i] = min(abs(nums[i]-l),abs(nums[i]-r));
        }
        return ans;
    }
};