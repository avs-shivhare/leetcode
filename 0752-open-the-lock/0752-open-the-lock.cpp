class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());
        if(dead.find("0000") != dead.end() || dead.find(target) != dead.end()) return -1;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        unordered_set<string> visited;
        visited.insert("0000");
        while(!q.empty()) {
            string str = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(str == target) return cnt;
            for(int i =0; i<4; i++) {
                string temp1 = str;
                string temp2 = str;
                temp1[i]++;
                if(temp1[i] > '9') temp1[i] = '0';
                temp2[i]--;
                if(temp2[i] < '0') temp2[i] = '9';
                if(dead.find(temp1) == dead.end() && visited.find(temp1) == visited.end()) {
                    q.push({temp1,cnt+1});
                    visited.insert(temp1);
                }
                if(dead.find(temp2) == dead.end() && visited.find(temp2) == visited.end()) {
                    q.push({temp2,cnt+1});
                    visited.insert(temp2);
                }
            }
        }
        return -1;
    }
};