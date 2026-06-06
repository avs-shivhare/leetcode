class Solution {
public:
    long long minEnergy(int n, int br, vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>> temp;
        for(auto &i: in) {
            if(temp.empty() || temp.back()[1] < i[0]) {
                temp.push_back(i);
            }
            else temp.back()[1] = max(temp.back()[1],i[1]);
        }
        long long ans = 0;
        long long req = (1ll*br+2)/3ll;
        for(auto &i: temp) {
            //cout<<i[0]<<" "<<i[1]<<endl;
            ans += (1ll*i[1]-i[0]+1)*req;
        }
        return ans;
    }
};