class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        set<int,greater<int>> st;
        string x = to_string(n);
        for(int i = 0; i<x.size(); i++) {
            string temp = "";
            temp += x[i];
            for(int j = i+1; j<x.size(); j++) {
                temp += '0';
            }
            st.insert(stoi(temp));
        }
        vector<int> ans;
        for(auto i: st) {
            if(i != 0) ans.push_back(i);
        }
        return ans;
    }
};