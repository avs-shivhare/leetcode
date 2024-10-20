class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        for(auto i: exp) {
            if(i == ',') continue;
            else if(i == ')') {
                int t =0,f = 0;
                while(!st.empty() && st.top() != '(') {
                    if(st.top() == 't') t++;
                    else f++;
                    //cout<<st.top()<<endl;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                if(!st.empty()) {
                    if(st.top() == '&') {
                        st.pop();
                        if(f == 0) st.push('t');
                        else st.push('f');
                    }
                    else if(st.top() == '|') {
                        st.pop();
                        if(t > 0) st.push('t');
                        else st.push('f');
                    }
                    else {
                        st.pop();
                        if(t > 0) st.push('f');
                        else st.push('t');
                    }
                }
                //cout<<t<<" "<<f<<endl;
            }
            else {
                st.push(i);
            }
        }
        if(!st.empty() && st.top() == 't') return true;
        return false;
    }
};