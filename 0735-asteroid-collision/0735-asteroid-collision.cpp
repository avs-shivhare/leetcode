class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for(int i : ast) {
            if(i > 0) st.push(i);
            else {
                while(!st.empty() && i != 0 && st.top() > 0) {
                    if(st.top() == abs(i)) {
                        st.pop();
                        i =0;
                        break;
                    }
                    else if(abs(i) < st.top()) {
                        i = 0;
                        break;
                    }
                    else {
                        st.pop();
                    }
                }
                if(i != 0) st.push(i);
            }

        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};