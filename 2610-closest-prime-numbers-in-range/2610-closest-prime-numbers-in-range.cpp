class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        bool prime[1000001];
        int n = 1e6+1;
        memset(prime,true,sizeof(prime));
        prime[0] = false,prime[1] = false;
        for(int i = 2; i*i<n; i++) {
            if(prime[i]) {
                for(int j = i*i; j<n; j += i) {
                    prime[j] = false;
                }
            }
        }
        vector<int> temp;
        int start = -1,end = -1;
        int diff = 1e9;
        for(int i = left; i<=right; i++) {
            if(prime[i]) {
                temp.push_back(i);
            }
        }
        n = temp.size();
        for(int i = 1; i<n; i++) {
            if(temp[i]-temp[i-1] < diff) {
                start = temp[i-1];
                end = temp[i];
                diff = temp[i]-temp[i-1];
            }
        }
        return {start,end};
    }
};