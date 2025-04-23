class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mpp;
        for(int i = 1; i<=n; i++) {
            int sum = 0;
            int x = i;
            while(x) {
                sum += x%10;
                x /= 10;
            }
            mpp[sum]++;
        }
        int cnt = 0,si = 0;
        for(auto i: mpp) {
            //cout<<i.first<<" "<<i.second<<endl;
            if(si < i.second) {
                cnt = 1;
                si = i.second;
            }
            else if(si == i.second) cnt++;
        }
        return cnt;
    }
};