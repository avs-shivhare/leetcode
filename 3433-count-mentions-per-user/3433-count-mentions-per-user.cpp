class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& ev) {
        sort(ev.begin(),ev.end(),[&](auto a,auto b){
            int x = stoi(a[1]);
            int y = stoi(b[1]);
            if(x == y) {
                if(a[0] == "OFFLINE" && b[0] == "MESSAGE") return true;
                else if(b[0] == "OFFLINE" && a[0] == "MESSAGE") return false;
                return false;
            }
            return x < y;
        });
        vector<int> ans(n,0);
        unordered_set<int> online;
        for(int i = 0; i<n; i++) online.insert(i);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        for(auto i: ev) {
            //cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
            int ti = stoi(i[1]);
            while(!q.empty() && ti >= q.top()[0]) {
                online.insert(q.top()[1]);
                q.pop();
            }
            if(i[0] == "MESSAGE") {
                if(i[2] == "ALL") {
                    for(int j = 0; j<n; j++) ans[j]++;
                }
                else if(i[2] == "HERE") {
                    // cout<<"done"<<endl;
                    for(auto j: online) {
                        //cout<<j<<endl;
                        ans[j]++;
                    }
                }
                else {
                    stringstream s(i[2]);
                    string temp = "";
                    while(s>>temp) {
                        int id = stoi(temp.substr(2));
                        ans[id]++;
                    }
                }
            }
            else {
                int time = stoi(i[1]);
                int id = stoi(i[2]);
                if(online.find(id) != online.end()) {
                    //cout<<id<<endl;
                    online.erase(id);
                    q.push({time+60,id});
                }
                // for(auto j: online) {
                //     cout<<j<<endl;
                // }
            }
        }
        return ans;
    }
};