class Solution {
public:
    unordered_set<string> st;
    int ans = 0;
    void find(int i,string &s,string temp) {
        if(i == s.size()) {
            if(st.count(temp) == 0 && !temp.empty()) {
                st.insert(temp);
                ans= max(ans,(int)st.size());
                st.erase(temp);
                return;
            }
            ans= max(ans,(int)st.size());
            return;
        }
        temp+= s[i];
        if(st.count(temp) == 0) {
            st.insert(temp);
            find(i+1,s,"");
            st.erase(temp);
        }
        find(i+1,s,temp);
        return;
    }
    int maxUniqueSplit(string s) {
        // string temp = "";
        // for(auto i: s) {
        //     temp += i;
        //     if(st.count(temp) == 0) {
        //         cout<<temp<<endl;
        //         st.insert(temp);
        //         temp = "";
        //     }
        // }
        // return st.size();

        find(0,s,"");
        return ans;
    }
};