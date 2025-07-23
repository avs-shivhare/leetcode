class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        string temp = "ab";
        int ans = 0;
        if(x < y) reverse(temp.begin(),temp.end());
        for(auto i: s) {
            if(st.empty()) st.push(i);
            else if(st.top() == temp[0] && i == temp[1]) {
                //cout<<"first "<<st.top()<<" "<<i<<endl;
                ans += (temp == "ab" ? x: y);
                //cout<<ans<<endl;
                st.pop();
            }
            else st.push(i);
        }
        reverse(temp.begin(),temp.end());
        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        for(auto i: s) {
            if(st.empty()) st.push(i);
            else if(st.top() == temp[0] && i == temp[1]) {
                //cout<<"first "<<st.top()<<" "<<i<<endl;
                ans += (temp == "ab" ? x: y);
                //cout<<ans<<endl;
                st.pop();
            }
            else st.push(i);
        }
        return ans;
    }
};