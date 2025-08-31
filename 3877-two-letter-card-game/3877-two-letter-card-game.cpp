class Solution {
public:
    int score(vector<string>& cards, char x) {
        unordered_map<char,int> mpp,mpp2;
        int cnt = 0;
        for(auto i: cards) {
            if(i[0] == i[1] && i[0] == x) cnt++;
            else if(i[0] == x) mpp[i[1]]++;
            else if(i[1] == x) mpp2[i[0]]++;
        }
        priority_queue<int> l,r;
        for(auto i: mpp) {
            l.push(i.second);
        }
        for(auto i: mpp2) {
            r.push(i.second);
        }
        int ans = 0;
        while(l.size() > 1) {
            int first = l.top();
            l.pop();
            int second = l.top();
            l.pop();
            ans++;
            first--;
            second--;
            if(first) l.push(first);
            if(second) l.push(second);
        }
        while(r.size() > 1) {
            int first = r.top();
            r.pop();
            int second = r.top();
            r.pop();
            ans++;
            first--;
            second--;
            if(first) r.push(first);
            if(second) r.push(second);
        }
        int left = 0,right = 0;
        while(!l.empty()) {
            left += l.top();
            l.pop();
        }
        while(!r.empty()) {
            right += r.top();
            r.pop();
        }
        int temp = ans;
        int c = min(cnt,left);
        ans += c;
        cnt -= c;
        if(cnt > 0) {
            c = min(cnt,right);
            ans += c;
            cnt -= c;
        }
        if(cnt > 0) {
            ans += min(temp,cnt/2);
        }
        return ans;
    }
};