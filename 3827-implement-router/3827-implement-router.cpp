class Router {
public:
    unordered_set<string> st;
    map<int,vector<int>> mpp;
    queue<vector<int>> q;
    int m = 0;
    Router(int n) {
        m = n;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        //cout<<source<<" * "<<destination<<" * "<<timestamp<<endl;
        string x = to_string(source)+"#";
        x += to_string(destination)+"#";
        x += to_string(timestamp);
        if(st.find(x) != st.end()) {
            //cout<<source<<" -> "<<destination<<" -> "<<timestamp<<endl;
            return false;
        }
        if(q.size() == m) {
            auto ans = q.front();
            string u = to_string(ans[0])+"#";
            u += to_string(ans[1])+"#";
            u += to_string(ans[2]);
            q.pop();
            st.erase(u);
            //cout<<u<<endl;
            auto p = lower_bound(mpp[ans[1]].begin(),mpp[ans[1]].end(),ans[2]);
            mpp[ans[1]].erase(p);
        }
        q.push({source,destination,timestamp});
        st.insert(x);
        auto p = upper_bound(mpp[destination].begin(),mpp[destination].end(),timestamp);
        mpp[destination].insert(p,timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        auto ans = q.front();
        string x = to_string(ans[0])+"#";
        x += to_string(ans[1])+"#";
        x += to_string(ans[2]);
        q.pop();
        st.erase(x);
        auto p = lower_bound(mpp[ans[1]].begin(),mpp[ans[1]].end(),ans[2]);
        mpp[ans[1]].erase(p);
        return ans;
    }
    
    int getCount(int d, int s, int e) {
        // cout<<d<<" -> "<<s<<" -> "<<e<<endl;
        // for(auto i: mpp[d]) cout<<i<<" ";
        // cout<<endl;
        int l = lower_bound(mpp[d].begin(),mpp[d].end(),s)-mpp[d].begin();
        int r = upper_bound(mpp[d].begin(),mpp[d].end(),e)-mpp[d].begin();
        //cout<<l<<" "<<r<<endl;
        if(l<r) return r-l;
        return 0;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */