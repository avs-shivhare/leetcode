class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> q;
        if(a != 0) q.push({a,'a'});
        if(b !=0) q.push({b,'b'});
        if(c !=  0) q.push({c,'c'});
        string ans = "";
        while(!q.empty()) {
            auto x = q.top();
            q.pop();
            if(ans.size() >= 2 && ans.back() == x.second && ans[ans.size()-2] == x.second) {
                if(q.empty()) break;
                auto y = q.top();
                q.pop();
                ans += y.second;
                y.first--;
                if(y.first > 0) q.push(y);
                q.push(x);
            }
            else {
                ans += x.second;
                x.first--;
                if(x.first > 0) q.push(x);
            }
        }
        return ans;
    }
};