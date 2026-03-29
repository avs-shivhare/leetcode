class Solution {
public:
    bool check(vector<int> &nums,int l,int r) {
        if(r-l+1 == 1) return true;
        int cnt = 0;
        for(int i = l+1; i<=r; i++) {
            if(nums[i-1] > nums[i]) cnt++;
        }
        if(nums[r] > nums[l]) cnt++;
        return cnt <= 1;
    }
    int sortableIntegers(vector<int>& nums) {
        vector<int> div;
        int n = nums.size();
        for(int i = 1; i*i<=n; i++) {
            if(n%i == 0) {
                div.push_back(i);
                if(i != n/i) div.push_back(n/i);
            }
        }
        int ans = 0;
        sort(div.begin(),div.end());
        for(auto &i: div) {
            int last = 0;
            bool f = true;
            for(int j = 0; j<n; j+=i) {
                int temp = 0;
                if(check(nums,j,j+i-1)) {
                    bool flag = true;
                    for(int k = j; k<j+i; k++) {
                        temp = max(nums[k],temp);
                        if(last > nums[k]) {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) {
                        f = false;
                    }
                }
                else f = false;
                last = temp;
                if(!f) break;
            }
            if(f) ans += i;
        }
        return ans;
    }
};