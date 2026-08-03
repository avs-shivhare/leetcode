#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>  
using namespace __gnu_pbds;

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        tree < pair<long long,long long> ,  null_type ,  less<pair<long long,long long>> ,  rb_tree_tag ,  tree_order_statistics_node_update > st;
        int n = nums.size();
        vector<long long> prefix(n,0);
        for(int i = 0; i<n; i++) {
            if(nums[i]&1) prefix[i] = -1ll*a;
            else prefix[i] = b;
        }
        for(int i = 1; i<n; i++) {
            prefix[i] += prefix[i-1];
        }
        st.insert({0,-1});
        long long ans = 0;
        for(int i = 0; i<n; i++) {
            long long temp = st.order_of_key({prefix[i],-2});
            ans += 1ll*st.size()-temp;
            //cout<<i<<" "<<temp<<endl;
            st.insert({prefix[i],i});
        }
        return ans;
    }
};