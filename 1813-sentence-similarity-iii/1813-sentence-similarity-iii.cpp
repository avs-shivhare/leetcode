class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size() < s2.size()) return areSentencesSimilar(s2,s1);
        stringstream ss1(s1);
        stringstream ss2(s2);
        vector<string> temp1,temp2;
        string t = "";
        unordered_map<string,int> st;
        while(ss1>>t) {
            st[t]++;
            temp1.push_back(t);
        }
        while(ss2>>t) {
            if(st.count(t) == 0) return false;
            else {
                st[t]--;
                if(st[t] == 0) {
                    st.erase(t);
                }
            }
            temp2.push_back(t);
        }
        bool flag = true;
        int n = temp1.size();
        int m = temp2.size();
        int i =0;
        int j = 0;
        while(i<n && j<m) {
            if(temp1[i] != temp2[j]) {
                break;
            }
            i++;
            j++;
        }
        int x = n-1,y = m-1;
        while(x>=i && y>=j) {
            if(temp1[x] != temp2[y]) break;
            x--;
            y--;
        }
        cout<<i<<" "<<j<<" "<<x<<" "<<y<<endl;
        while(i<=x && j<=y) {
            if(temp1[i] == temp2[j]) {
                flag = false;
                break;
            }
            i++;
        }
        if(flag) return true;
        return false;
    }
};