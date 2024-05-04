class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int left = 0,right = n-1;
        int cnt = 0;
        sort(people.begin(),people.end());
        while(left <= right) {
            if(people[right] >= limit)  {
                cnt++;
                right--;
            }
            else if(people[right]+people[left] <= limit) {
                cnt++;
                right--;
                left++;
            }
            else {
                cnt++;
                right--;
            }
        }
        return cnt;
    }
};