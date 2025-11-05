#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<long long,long long> mpp;
        ordered_set<pair<long long,long long>> st;
        long long sum = 0;
        int l = 0, r= 0;
        vector<long long> ans;
        int n = nums.size();
        while(r<n) {
            while(l<r && r-l+1 > k) {
                int ind = st.order_of_key({mpp[nums[l]],nums[l]});
                int len = st.size();
                //cout<<len<<" "<<ind<<" "<<l<<" "<<r<<endl;
                if(ind < len-x) {
                    st.erase({mpp[nums[l]],nums[l]});
                }
                else {
                    //cout<<"done"<<endl;
                    sum -= mpp[nums[l]]*nums[l];
                    st.erase({mpp[nums[l]],nums[l]});
                    len = st.size();
                    if(len >= x) {
                        //cout<<"done2"<<endl;
                        auto t = st.find_by_order(len-x);
                        //cout<<st.size()<<endl;
                        //cout<<t->first<<" "<<t->second<<endl;
                        sum += t->first*t->second;
                    }
                }
                mpp[nums[l]]--;
                ind = st.order_of_key({mpp[nums[l]],nums[l]});
                len = st.size();
                //cout<<len<<" "<<ind<<" "<<sum<<endl;
                if(ind < len-x) {
                    st.insert({mpp[nums[l]],nums[l]});
                }
                else {
                    st.insert({mpp[nums[l]],nums[l]});
                    sum += mpp[nums[l]]*nums[l];
                    //cout<<mpp[nums[r]]<<" "<<nums[r]<<endl;
                    len = st.size();
                    if(len-x-1 >= 0) {
                        auto t = st.find_by_order(len-x-1);
                        //cout<<t->first<<" "<<t->second<<endl;
                        sum -= t->first*t->second;
                    }
                }
                l++;
            }
            int ind = st.order_of_key({mpp[nums[r]],nums[r]});
            if(mpp[nums[r]] > 0) {
                int len = st.size();
                //cout<<len-x<<" "<<len<<endl;
                if(ind < len-x) {
                    st.erase({mpp[nums[r]],nums[r]});
                }
                else {
                    sum -= mpp[nums[r]]*nums[r];
                    st.erase({mpp[nums[r]],nums[r]});
                    len = st.size();
                    //cout<<len<<endl;
                    if(len >=x) {
                        // cout<<len<<endl;
                        // cout<<"done"<<endl;
                        auto t = st.find_by_order(len-x);
                        //cout<<t->first<<" -> "<<t->second<<endl;
                        sum += t->first*t->second;
                    }
                    // else if(len) {
                    //     cout<<"done2"<<endl;
                    //     auto t = st.begin();
                    //     //cout<<t->first<<" -> "<<t->second<<" "<<l<<" "<<r<<endl;
                    //     sum += t->first*t->second;
                    // }
                }
            }
            mpp[nums[r]]++;
            ind = st.order_of_key({mpp[nums[r]],nums[r]});
            int len = st.size();
            //cout<<len<<" "<<ind<<" "<<sum<<endl;
            if(ind < len-x) {
                st.insert({mpp[nums[r]],nums[r]});
            }
            else {
                st.insert({mpp[nums[r]],nums[r]});
                sum += mpp[nums[r]]*nums[r];
                //cout<<mpp[nums[r]]<<" "<<nums[r]<<endl;
                len = st.size();
                if(len-x-1 >= 0) {
                    auto t = st.find_by_order(len-x-1);
                    //cout<<t->first<<" "<<t->second<<endl;
                    sum -= t->first*t->second;
                }
            }
            //cout<<l<<" "<<r<<" -> "<<sum<<endl;
            if(r-l+1 == k) {
                ans.push_back(sum);
            }
            r++;
        }
        return ans;
    }
};