class Robot{
    public:
    int ind,pos,health,dir;
};
class Solution {
public:
    static bool compare(Robot &t1,Robot &t2) {
        return t1.pos < t2.pos;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n =positions.size();
        vector<Robot> temp;
        for(int i =0; i<n; i++) {
            Robot t1;
            t1.ind =i;
            t1.pos = positions[i];
            t1.health = healths[i];
            t1.dir = (directions[i] == 'R'?1:0);
            temp.push_back(t1);
        }
        sort(temp.begin(),temp.end(),compare);
        stack<Robot> st;
        //for(auto i: temp) cout<<i.pos<<endl;
        for(auto &i: temp) {
            if(i.dir == 1) st.push(i);
            else {
                while(!st.empty() && st.top().dir == 1 && st.top().health < i.health) {
                    st.pop();
                    i.health--;
                }
                if(!st.empty() && st.top().dir == 1 &&  st.top().health == i.health) {
                    st.pop();
                }
                else if(!st.empty() && st.top().dir == 1 && st.top().health > i.health) {
                    auto x = st.top();
                    st.pop();
                    x.health--;
                    if(x.health != 0) st.push(x);
                }
                else if(i.health != 0) st.push(i);
            }
        }
        vector<int> ans(n,0);
        while(!st.empty()) {
            ans[st.top().ind] = st.top().health;
            st.pop();
        }
        // delete all element those are zero
        // int i =0;
        // while(i< ans.size()) {
        //     if(ans[i] == 0) {
        //         ans.erase(ans.begin()+i);
        //     }
        //     else i++;
        // }

        //taking another array rather than delete element which take O(n) time complexity
        vector<int> t;
        for(int i: ans) {
            if(i != 0) t.push_back(i);
        }
        return t;
    }
};