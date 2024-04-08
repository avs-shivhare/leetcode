class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sn) {
        int cnt =0;
        while(st.size() && sn.size()) {
            if(*(st.begin()) == *(sn.begin())) {
                st.erase(st.begin());
                sn.erase(sn.begin());
                cnt = 0;
            }
            else {
                st.push_back(*(st.begin()));
                st.erase(st.begin());
                cnt++;
            }
            if(cnt >= st.size()) break;
        }
        return st.size();
    }
};