#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> st;
        unordered_map<int,int> mpp;
        int n = nums1.size();
        for(int i = 0; i<n; i++) {
            mpp[nums1[i]] = i;
        }
        long long ans = 0;
        for(int i = 0; i<n; i++) {
            int index = mpp[nums2[i]];
            long long left = st.order_of_key(index);
            long long right = (n-1-index)-(st.size()-left);
            ans += left*right;
            st.insert(index);
        }
        return ans;
    }
};