class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int,int>> temp;
        for(auto i: meetings) {
            temp.push_back({i[0],1});
            temp.push_back({i[1],-1});
        }
        sort(temp.begin(),temp.end());
        int ans = temp[0].first-1;
        int cnt = 0;
        for(int i = 0; i<temp.size(); i++) {
           // cout<<temp[i].first<<" "<<temp[i].second<<" "<<cnt<<endl;
            if(cnt == 0 && i > 0 && temp[i].first != temp[i-1].first) {
                ans += temp[i].first-temp[i-1].first-1;
            }
            if(temp[i].second == 1) cnt++;
            else cnt--;
        }
        //cout<<ans<<endl;
        ans += days-temp[temp.size()-1].first;
        return ans;
    }
};