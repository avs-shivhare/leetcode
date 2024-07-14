class Solution {
public:
    string countOfAtoms(string fo) {
        map<string,int> mpp;
        stack<string> st;
        int i =0;
        int n = fo.size();
        while(i<n) {
            if(fo[i] == '(') {
                string temp= "";
                temp += fo[i];
                //cout<<temp<<endl;
                st.push(temp);
                i++;
            }
            else if('A' <= fo[i] && fo[i] <= 'Z') {
                string temp = "";
                temp += fo[i];
                i++;
                while(i<n && 'a' <= fo[i] && fo[i] <= 'z') {
                    temp += fo[i];
                    i++;
                }
                //cout<<temp<<endl;
                st.push(temp);
            }
            else if('0' <= fo[i] && fo[i] <= '9') {
                string temp = "";
                temp += fo[i];
                i++;
                while(i<n && '0' <= fo[i] && fo[i] <= '9') {
                    temp += fo[i];
                    i++;
                }
                st.push(temp);
                //cout<<temp<<endl;
            }
            else {
                string temp = "";
                //temp += fo[i];
                i++;
                while(i<n && '0' <= fo[i] && fo[i] <= '9') {
                    temp += fo[i];
                    i++;
                }
                int x = 1;
                if(!temp.empty()) x = stoi(temp);
                stack<string> t;
                while(!st.empty() && st.top() != "(") {
                    if('A' <= st.top()[0] && st.top()[0] <= 'Z') {
                        t.push(to_string(x));
                        t.push(st.top());
                        st.pop();
                    }
                    else {
                        auto t1 = stoi(st.top());
                        //cout<<st.top()<<endl;
                        st.pop();
                        t.push(to_string(t1*x));
                        t.push(st.top());
                        st.pop();
                    }
                }
                if(!st.empty()) st.pop();
                while(!t.empty()) {
                    st.push(t.top());
                    t.pop();
                }
            }
        }
        while(!st.empty()) {
            //cout<<st.top()<<endl;
            if('A' <= st.top()[0] && st.top()[0] <= 'Z') {
                mpp[st.top()]++;
                st.pop();
            }
            else {
                auto t1 = stoi(st.top());
                st.pop();
                mpp[st.top()] += t1;
                st.pop();
            }
        }
        string ans = "";
        for(auto i: mpp) {
            ans += i.first;
            if(i.second != 1) ans += to_string(i.second);
        }
        return ans;
    }
};