class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        queue<vector<int>> q;
        set<vector<int>> st;
        q.push(nums1);
        st.insert(nums1);
        int cnt = 0;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto x = q.front();
                q.pop();
                if(x == nums2) return cnt;
                for(int l = 0; l<nums1.size(); l++) {
                    for(int r = l; r<nums1.size(); r++) {
                        vector<int> rem(x.begin()+l,x.begin()+r+1);
                        vector<int> nx;
                        nx.insert(nx.end(),x.begin(),x.begin()+l);
                        nx.insert(nx.end(),x.begin()+r+1,x.end());
                        for(int i = 0; i<nx.size(); i++) {
                            vector<int> newx = nx;
                            newx.insert(newx.begin()+i,rem.begin(),rem.end());
                            if(st.find(newx) == st.end()) {
                                q.push(newx);
                                st.insert(newx);
                            }
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};