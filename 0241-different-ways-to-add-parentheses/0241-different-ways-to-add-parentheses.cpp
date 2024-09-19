class Solution {
public:
    vector<int> find(string in) {
        vector<int> res;
        int n = in.size();
        for(int i =0; i<n; i++) {
            if(in[i] == '+' || in[i] == '-' || in[i] == '*') {
                char c = in[i];
                string a = in.substr(0,i);
                string b = in.substr(i+1);
                auto x = find(a);
                auto y = find(b);
                for(auto p : x) {
                    for(auto q: y) {
                        if(c == '+') res.push_back(p+q);
                        else if(c == '-') res.push_back(p-q);
                        else res.push_back(p*q);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(in));
        return res;
    }
    vector<int> diffWaysToCompute(string exp) {
        auto ans = find(exp);
        return ans;
    }
};