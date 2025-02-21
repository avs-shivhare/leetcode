class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end());
        int n = pizzas.size();
        int day = n/4;
        int odd = ceil((double)day/2.0);
        long long ans = 0;
        int even = day/2;
        while(odd--) {
            ans += (long long)pizzas.back();
            //cout<<ans<<endl;
            pizzas.pop_back();
        }
        while(even--) {
            pizzas.pop_back();
            ans += (long long)pizzas.back();
            pizzas.pop_back();
        }
        return ans;
    }
};