class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        vector<vector<int>> temp;
        int n = p.size();
        for(int i = 0; i<n; i++) {
            temp.push_back({p[i],h[i],i,(d[i] == 'L'? 1: 0)});
        }
        sort(temp.begin(),temp.end());
        map<int,int> mpp;
        stack<vector<int>> st;
        for(auto &i: temp) {
            if(i[3] == 0) {
                st.push(i);
            }
            else {
                int ch = i[1];
                while(!st.empty() && ch) {
                    if(ch > st.top()[1]) {
                        st.pop();
                        ch--;
                    }
                    else if(ch == st.top()[1]) {
                        st.pop();
                        ch = 0;
                        break;
                    }
                    else {
                        st.top()[1]--;
                        if(st.top()[1] == 0) st.pop();
                        ch = 0;
                        break;
                    }
                }
                if(ch) mpp[i[2]] = ch;
            }
        }
        while(!st.empty()) {
            mpp[st.top()[2]] = st.top()[1];
            st.pop();
        }
        vector<int> ans;
        for(auto &i: mpp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};