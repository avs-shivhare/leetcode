class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int sq = sqrt(n);
        vector<array<int,3>> temp;
        for(int i = 0; i<queries.size(); i++) {
            temp.push_back({queries[i][0],queries[i][1],i});
        }
        sort(temp.begin(),temp.end(),[&](auto &a,auto &b){
            if(a[0]/sq == b[0]/sq) return a[1] < b[1];
            return a[0]/sq < b[0]/sq;
        });
        int ql = 0,qr = -1;
        vector<int> fre(1e5+1,0);
        int odd = 0,cnt = 0;
        vector<bool> ans((int)queries.size(),false);
        for(auto &i: temp) {
            int l = i[0];
            int r = i[1];
            while(ql > l) {
                ql--;
                fre[nums[ql]]++;
                if(fre[nums[ql]] == 1) cnt++;
                if(fre[nums[ql]]%2 == 0) odd--;
                else odd++;
            }
            while(ql < l) {
                fre[nums[ql]]--;
                if(fre[nums[ql]] == 0) cnt--;
                if(fre[nums[ql]]%2 == 0) odd--;
                else odd++;
                ql++;
            }
            while(qr < r) {
                qr++;
                fre[nums[qr]]++;
                if(fre[nums[qr]] == 1) cnt++;
                if(fre[nums[qr]]%2 == 0) odd--;
                else odd++;
            }
            while(qr > r) {
                fre[nums[qr]]--;
                if(fre[nums[qr]] == 0) cnt--;
                if(fre[nums[qr]]%2 == 0) odd--;
                else odd++;
                qr--;
            }
            // cout<<l<<" "<<r<<" "<<ql<<" "<<qr<<endl;
            // cout<<cnt<<" "<<odd<<endl;
            if(cnt == k && odd == 0) ans[i[2]] = true;
        }
        return ans;
    }
};