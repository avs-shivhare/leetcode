class Solution {
public:
    int smallestChair(vector<vector<int>>& t, int target) {
        priority_queue<int,vector<int>,greater<int>> q1,q2;
        unordered_map<int,int> mpp;
        int ans = 0;
        unordered_map<int,vector<int>> mpp2;
        int n = t.size();
        for(int i =0; i<n; i++) {
            mpp[t[i][0]] = i;
        }
        sort(t.begin(),t.end());
        for(int i =0; i<n; i++) q2.push(i);
        for(auto i: t) {
            while(!q1.empty() && q1.top() <= i[0]) {
                q2.push(mpp2[q1.top()].back());
                mpp2[q1.top()].pop_back();
                if(mpp2[q1.top()].size() == 0) mpp2.erase(q1.top());
                q1.pop();
            }
            q1.push(i[1]);
            mpp2[i[1]].push_back(q2.top());
            //cout<<i[0]<<" "<<q2.top()<<endl;
            if(mpp[i[0]] == target) {
                //cout<<"done"<<endl;
                ans = q2.top();
            }
            q2.pop();
        }
        return ans;
    }
};