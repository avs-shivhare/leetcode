class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n = tasks.size();
        unordered_map<char,int> mpp;
        for(int i =0; i<n; i++) {
            mpp[tasks[i]]++;
        }
        priority_queue<int> q;
        for(auto i: mpp) {
            q.push(i.second);
        }
        int result = 0;
        while(!q.empty()) {
            int time =0;
            vector<int> temp;
            for(int i =0; i<=k; i++) {
                if(q.empty()) break;
                temp.push_back(q.top()-1);
                q.pop();
                time++;
            }
            for(auto i: temp) {
                if(i) q.push(i);
            }
            if(q.empty()) {
                result += time;
            }
            else result += k+1;
        }
        return result;
    }
};