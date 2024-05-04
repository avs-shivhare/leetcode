class Solution {
public:
    class compare {
        public:
            bool operator()(pair<int,string> t1, pair<int,string> t2) {
                if(t1.first > t2.first) return true;
                else if(t1.first < t2.first) return false;
                else if(t1.second.compare(t2.second) < 0) return true;
                return false;
            }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int temp = k;
        unordered_map<string,int> mpp;
        for(string i : words) {
            mpp[i]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> q;
        for(auto i: mpp) {
            //cout<<"d"<<endl;
            if(k) {
                q.push({i.second,i.first});
                k--;
            }
            else if(q.top().first < i.second) {
                q.pop();
                q.push({i.second,i.first});
            }
            else if(q.top().first == i.second) {
                if(q.top().second.compare(i.first) > 0) {
                    q.pop();
                    q.push({i.second,i.first});
                }
            }
        }
        k = temp;
        vector<string> ans(k,"");
        for(int i = k-1; i>=0 && !q.empty(); i--) {
            //cout<<"d"<<endl;
            ans[i] = q.top().second;
            q.pop();
        }
        //cout<<q.size()<<endl;
        //sort(ans.begin(),ans.end());
        return ans;
    }
};