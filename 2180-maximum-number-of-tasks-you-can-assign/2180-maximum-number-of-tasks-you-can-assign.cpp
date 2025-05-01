class Solution {
public:
    bool check(vector<int> &ta,vector<int> &w,int p,int &st,int &mid) {
        deque<int> q;
        int ind = w.size()-1;
        for(int i = mid; i>=0; i--) {
            if(!q.empty() && q.front() >= ta[i]) {
                q.pop_front();
            }
            else if(ind >=0 && w[ind] >= ta[i]) {
                ind--;
            }
            else {
                while(ind >= 0 && w[ind]+st >= ta[i]) {
                    q.push_back(w[ind]);
                    ind--;
                }
                if(q.empty() || p <= 0) {
                    //cout<<ta[i]<<" "<<i<<" "<<p<<" "<<q.size()<<endl;
                    return false;
                }
                q.pop_back();
                p--;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& ta, vector<int>& w, int p, int st) {
        sort(ta.begin(),ta.end());
        sort(w.begin(),w.end());
        int l = 0,r = min(ta.size(),w.size())-1;
        int ans = 0;
        while(l<=r) {
            int mid = (l+r)>>1;
            //cout<<mid<<" ";
            if(check(ta,w,p,st,mid)) {
                //cout<<mid<<" true"<<endl;
                ans = mid+1;
                l = mid+1;
            }
            else {
                r = mid-1;
                //cout<<mid<<" false"<<endl;
            }
        }
        return ans;
    }
};