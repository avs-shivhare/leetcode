class Solution {
public:
    int lower(vector<int> &arr,int st) {
        if(arr.empty()) return 0;
        int l =0,r = arr.size()-1;
        int ans = arr.size();
        while(l<=r) {
            int mid = (l+r)>>1;
            if(arr[mid] >= st) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    int intersectionSizeTwo(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),[&](auto a,auto b) {
            if(a[1] < b[1]) return true;
            else if(a[1] > b[1]) return false;
            if(a[0] < b[0]) return true;
            return false;
        });
        vector<int> temp;
        unordered_set<int> st;
        int ans = 0;
        for(auto i: in) {
            int val = lower(temp,i[0]);;
            int diff = temp.size()-lower(temp,i[0]);
            // for(auto j: temp) cout<<j<<" ";
            // cout<<endl;
            // cout<<val<<endl;
            // cout<<diff<<" -> "<<i[0]<<" "<<i[1]<<endl;
            if(diff == 0) {
                temp.push_back(i[1]-1);
                temp.push_back(i[1]);
                st.insert(i[1]-1);
                st.insert(i[1]);
                ans += 2;
            } 
            else if(diff == 1) {
                while(st.find(i[1]) != st.end()) i[1]--;
                auto x = upper_bound(temp.begin(),temp.end(),i[1]);
                temp.insert(x,i[1]);
                st.insert(i[1]);
                ans++;
            }
        }
        return ans;
    }
};