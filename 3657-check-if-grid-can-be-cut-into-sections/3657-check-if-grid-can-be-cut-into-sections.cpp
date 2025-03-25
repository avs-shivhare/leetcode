class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> temp,temp2;
        for(auto i: rectangles) {
            temp.push_back({i[0],1});
            temp2.push_back({i[1],1});
            temp.push_back({i[2],-1});
            temp2.push_back({i[3],-1});
        }
        sort(temp.begin(),temp.end());
        sort(temp2.begin(),temp2.end());
        int last = -1;
        int cnt = 0;
        for(int i = 0; i<temp.size(); i++) {
            if(temp[i].second == 1) cnt++;
            else cnt--;
            //cout<<cnt<<endl;
            if(cnt == 0) {
                //cout<<i<<endl;
                if(last == -1) last = i;
                else if(i != temp.size()-1) return true;
            }
        }
        last = -1;
        cnt = 0;
        for(int i = 0; i<temp2.size(); i++) {
            if(temp2[i].second == 1) cnt++;
            else cnt--;
            if(cnt == 0) {
                if(last == -1) last = i;
                else if(i != temp2.size()-1) return true;
            }
        }
        return false;
    }
};