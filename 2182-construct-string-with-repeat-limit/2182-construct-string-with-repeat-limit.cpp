class Solution {
public:
    string repeatLimitedString(string s, int rep) {
        priority_queue<pair<char,int>> q;
        unordered_map<char,int> mpp;
        for(auto i: s) {
            mpp[i]++;
        }
        for(auto i: mpp) {
            q.push({i.first,i.second});
        }
        string ans = "";
        int cnt = 0;
        char tt = '1';
        while(!q.empty()) {
            int t = q.top().second;
            char c = q.top().first;
            //cout<<t<<" "<<c<<endl;
            q.pop();
            if(cnt == rep && c == tt) {
                if(q.empty()) return ans;
                auto x = q.top();
                q.pop();
                ans += x.first;
                x.second--;
                tt = x.first;
                cnt = 1;
                if(x.second > 0) q.push(x);
                q.push({c,t});
            }
            else {
                if(c == tt) {
                    cnt++;
                }
                else {
                    cnt = 1;
                    tt = c;
                }
                ans += c;
                t--;
                if(t > 0) q.push({c,t});
            }
        }
        return ans;
    }
};