class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> st;
        for(auto i: nums) {
            if(i<k) st.insert(i);
        }
        int cnt = 0;
        while(!st.empty()) {
            if(st.size() >=2) {
                auto x = *(st.begin());
                auto y = *(next(st.begin()));
                auto it = st.find(x);
                st.erase(it);
                it = st.find(y);
                st.erase(it);
                //cout<<st.size()<<endl;
                //cout<<x<<" "<<y<<endl;
                if((min(x,y)*2)+max(x,y) < k) st.insert((min(x,y)*2)+max(x,y));
                cnt++;
            }
            else {
                //cout<<"done"<<endl;
                cnt += st.size();
                break;
            }
        }
        return cnt;
    }
};