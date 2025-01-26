class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),[&](auto a,auto b) {
            if(stoi(a[1]) == stoi(b[1])) {
                return a[0] == "OFFLINE";
            }
            return stoi(a[1])<stoi(b[1]);
        });
        vector<int> ans(n,0),active(n,0);
        for(auto i: events) {
            //cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
            if(i[0] == "OFFLINE") {
                int ind = stoi(i[2]);
                active[ind] = stoi(i[1])+60;
            }
            else {
                if(i[2] == "ALL") {
                    for(auto &j: ans) j++;
                }
                else if(i[2] == "HERE") {
                    for(int j = 0; j<n; j++) {
                        if(active[j] <= stoi(i[1])) ans[j]++;
                    }
                }
                else {
                    stringstream s(i[2]);
                    string t = "";
                    vector<int> temp;
                    while(s>>t) {
                        temp.push_back(stoi(t.substr(2)));
                    }
                    for(auto j: temp) ans[j]++;
                }
            }
        }
        return ans;
    }
};