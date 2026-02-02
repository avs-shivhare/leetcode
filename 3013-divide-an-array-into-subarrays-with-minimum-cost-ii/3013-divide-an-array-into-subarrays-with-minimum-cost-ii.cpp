class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<pair<long long,int>> st,st2;
        int l = 1,r = 1;
        k--;
        long long sum = nums[0];
        long long ans = 1e18;
        while(r<n) {
            if(st.size() < k) {
                sum += nums[r];
                st.insert({nums[r],r});
            }
            else if(prev(st.end())->first > nums[r]) {
                auto x = *prev(st.end());
                sum -= x.first;
                st.erase(x);
                sum += nums[r];
                st.insert({nums[r],r});
                st2.insert(x);
            }
            else st2.insert({nums[r],r});
            while(l<r && r-l > dist) {
                if(st.find({nums[l],l}) != st.end()) {
                    sum -= nums[l];
                    st.erase({nums[l],l});
                }
                else st2.erase({nums[l],l});
                l++;
            }
            while(st.size() < k && st2.size()) {
                auto x = *st2.begin();
                sum += x.first;
                st2.erase(x);
                st.insert(x);
                //cout<<st.size()<<" "<<st2.size()<<endl;
            }
            if(r-l <= dist && st.size() == k) {
                ans = min(ans,sum);
            }
            r++;
        }
        return ans;
    }
};