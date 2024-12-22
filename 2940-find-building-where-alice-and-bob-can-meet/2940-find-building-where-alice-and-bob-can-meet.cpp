class sg{
    public:
    //int dp[190000];
    vector<int> s;
    int n;
    sg(int x) {
        s.resize(4*x+1);
        n = x;
        //memset(dp,-1,sizeof(dp));
    }
    void Build(int low,int high,vector<int> &arr,int ind) {
        if(low == high) {
            s[ind] = arr[low];
            return;
        }
        int mid = (low+high)>>1;
        Build(low,mid,arr,2*ind+1);
        Build(mid+1,high,arr,2*ind+2);
        s[ind] = max(s[2*ind+1],s[2*ind+2]);
        return;
    }
    int Query(int low,int high,int first,int ind,int idx) {
        if(low == high) {
            if(s[ind] > first && idx <= low) {
                //cout<<low<<" "<<s[ind]<<" "<<first<<endl;
                //cout<<"first"<<endl;
                return low;
            }
            if(s[ind] == first && low == idx) {
                //cout<<low<<" "<<s[ind]<<" "<<first<<endl;
                //cout<<"second"<<endl;
                return low;
            }
            return 1e9;
        }
        int mid = (low+high)>>1;
        if(s[ind] >= first ) {
            int x = Query(low,mid,first,2*ind+1,idx);
            if(x < 1e9) return x;
            int y = Query(mid+1,high,first,2*ind+2,idx);
            return min(x,y);
        }
        return 1e9;
    }
    void build(vector<int> &arr) {
        Build(0,n-1,arr,0);
        return;
    }
    int query(int first,int idx) {
        //if(dp[idx] != -1) return dp[idx];
        int temp = Query(0,n-1,first,0,idx);
        if(temp >= 1e9) return -1;
        return temp;
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& queries) {
        int n =h.size();
        sg s(n);
        s.build(h);
        vector<int> ans;
        for(auto i: queries) {
           // cout<<i[0]<<" "<<i[1]<<endl;
            if(i[0] == i[1]) {
                ans.push_back(i[0]);
                continue;
            }
            else if(h[i[0]] == h[i[1]]) ans.push_back(s.query(max(h[i[0]],h[i[1]]),max(i[0],i[1])+1));
            else ans.push_back(s.query(max(h[i[0]],h[i[1]]),max(i[0],i[1])));
        }
        return ans;
    }
};