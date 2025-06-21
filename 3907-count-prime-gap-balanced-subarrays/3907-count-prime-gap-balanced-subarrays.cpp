class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxi;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mini;
        int n = nums.size();
        int x = 1e5+1;
        vector<bool> prime(x,true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 2; i*i<x; i++) {
            if(prime[i]) {
                for(int j = i*i; j<x; j+= i) {
                    prime[j] = false;
                }
            }
        }
        int cnt = 0;
        int ans = 0;
        int r = 0,l = 0;
        deque<int> q;
        while(r<n) {
            if(prime[nums[r]]) {
                q.push_back(r);
                maxi.push({nums[r],r});
                mini.push({nums[r],r});
            }
            int m = 0,mm = 0;
            if(r+1<n && !mini.empty()) {
                m = max(maxi.top().first,(prime[nums[r+1]]?nums[r+1]:0));
                mm = min(mini.top().first,(int)(prime[nums[r+1]]?nums[r+1]:1e9));
            }
            while(r+1<n && !mini.empty() && m-mm <= k) {
                if(prime[nums[r+1]]) {
                    q.push_back(r+1);
                    maxi.push({nums[r+1],r+1});
                    mini.push({nums[r+1],r+1});
                }
                r++;
                if(r+1<n && !mini.empty()) {
                    m = max(maxi.top().first,(prime[nums[r+1]]?nums[r+1]:0));
                    mm = min(mini.top().first,(int)(prime[nums[r+1]]?nums[r+1]:1e9));
                }
            }
            while(!maxi.empty() && maxi.top().second < l) maxi.pop();
            while(!mini.empty() && mini.top().second < l) mini.pop();
            while(l<=r && q.size() >= 2 && maxi.top().first-mini.top().first > k) {
                if(prime[nums[l]]) q.pop_front();
                l++;
                while(!maxi.empty() && maxi.top().second < l) maxi.pop();
                while(!mini.empty() && mini.top().second < l) mini.pop();
            }
            while(l<=r && q.size() >= 2 && maxi.top().first-mini.top().first <= k) {               
                //cout<<r<<" "<<l<<endl;
                int x = q.front();
                q.pop_front();
                ans += r-q.front()+1;
                q.push_front(x);
                if(prime[nums[l]]) q.pop_front();
                l++;
                //int m = 0,mm = 0;
                while(!maxi.empty() && maxi.top().second < l) maxi.pop();
                while(!mini.empty() && mini.top().second < l) mini.pop();
                if(r+1<n && !mini.empty()) {
                    m = max(maxi.top().first,(prime[nums[r+1]]?nums[r+1]:0));
                    mm = min(mini.top().first,(int)(prime[nums[r+1]]?nums[r+1]:1e9));
                }
                while(r+1<n && !mini.empty() && m-mm <= k) {
                    if(prime[nums[r+1]]) {
                        q.push_back(r+1);
                        maxi.push({nums[r+1],r+1});
                        mini.push({nums[r+1],r+1});
                    }
                    r++;
                    if(r+1<n && !mini.empty()) {
                        m = max(maxi.top().first,(prime[nums[r+1]]?nums[r+1]:0));
                        mm = min(mini.top().first,(int)(prime[nums[r+1]]?nums[r+1]:1e9));
                    }
                }
            }
            //cout<<r<<" "<<l<<endl;
            r++;
        }
        for(auto i: nums) {
            if(prime[i]) cout<<i<<endl;
        }
        return ans;
    }
};