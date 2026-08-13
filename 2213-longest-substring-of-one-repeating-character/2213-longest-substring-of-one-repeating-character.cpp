#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    vector<int> longestRepeating(string s, string qs, vector<int>& qr) {
        tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> st,mpp;
        int n = s.size();
        int l = 0, r = 0;
        while(r<n) {
            l = r;
            while(r<n && s[l] == s[r]) r++;
            st.insert({r-1,l});
            mpp.insert({r-l,r-1});
        }
        vector<int> ans;
        n = qs.size();
        for(int i = 0; i<n; i++) {
            auto up = st.lower_bound({qr[i],-1});
            if(up->first-up->second+1 == 1) {
                s[qr[i]] = qs[i];
                mpp.erase({up->first-up->second+1,up->first});
                st.erase(up);
            }
            else if(up->second <= qr[i]-1 && qr[i]+1 <= up->first) {
                mpp.erase({up->first-up->second+1,up->first});
                st.insert({qr[i]-1,up->second});
                st.insert({up->first,qr[i]+1});
                mpp.insert({qr[i]-up->second,qr[i]-1});
                mpp.insert({up->first-qr[i],up->first});
                st.erase(up);
            }
            else if(up->second <= qr[i]-1 && qr[i] <= up->first) {
                mpp.erase({up->first-up->second+1,up->first});
                st.insert({qr[i]-1,up->second});
                mpp.insert({qr[i]-up->second,qr[i]-1});
                st.erase(up);
            }
            else {
                mpp.erase({up->first-up->second+1,up->first});
                st.insert({up->first,qr[i]+1});
                mpp.insert({up->first-qr[i],up->first});
                st.erase(up);
            }
            s[qr[i]] = qs[i];
            int total = 0;
            int l = qr[i], r = qr[i];
            if(qr[i] > 0 && s[qr[i]-1] == s[qr[i]]) {
                auto x = st.lower_bound({qr[i]-1,-1});
                l = x->second;
                mpp.erase({x->first-x->second+1,x->first});
                st.erase(x);
            }
            if(qr[i]+1 < s.size() && s[qr[i]+1] == s[qr[i]]) {
                //cout<<"done"<<endl;
                auto x = st.lower_bound({qr[i]+1,-1});
                r = x->first;
                mpp.erase({x->first-x->second+1,x->first});
                st.erase(x);
            }
            //cout<<l<<" "<<r<<endl;
            mpp.insert({r-l+1,r});
            st.insert({r,l});
            ans.push_back(prev(mpp.end())->first);
        }
        return ans;
    }
};