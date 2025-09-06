class Solution {
public:
    long long find(long long &s, long long e, long long power) {
        long long p = 1;
        for(int i = 0; i<power; i++) p *= 4ll;
        long long mini = min(p-1,e);
        if(mini < s) return 0;
        long long ans = mini-s+1;
        s = mini+1;
        return ans*power;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long cnt = 0;
        for(auto &i: queries) {
            long long temp = 0;
            long long l = i[0];
            long long r = i[1];
            long long power = 1;
            while(l<=r) {
                //cout<<l<<" "<<r<<endl;
                temp += find(l,r,power);
                power++;
            }
            //cout<<temp<<" "<<i[0]<<" "<<i[1]<<endl;
            cnt += ceil((double)temp/2.0);
        }
        //cout<<cnt<<endl;
        return cnt;
    }
};