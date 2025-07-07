class compare{
    public:
    bool operator ()(vector<int> &a,vector<int> &b) {
        if(a[1] < b[1]) return true;
        else if(a[1] > b[1]) return false;
        else if(a[0] < b[0]) return true;
        return false;
    }
};
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),compare());
        set<int> st;
        int cnt = 0;
        int maxi = 0;
        for(auto i: events) {
            maxi = max(maxi,i[1]);
        }
        for(int i = 1; i<=maxi; i++) {
            st.insert(i);
        }
        for(auto i: events) {
            auto x = st.lower_bound(i[0]);
            if(x == st.end()) continue;
            //cout<<i[0]<<" "<<i[1]<<" "<<*x<<endl;
            if(i[1] >= *x) {
                cnt++;
                st.erase(*x);
            }
        }
        return cnt;
    }
};