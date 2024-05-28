class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n = customers.size();
        int wait = 0;
        int maxi = 0;
        int profit = 0;
        int round = 0;
        int board = 0;
        int ans = 0;
        int i = 0;
        while(i<n) {
            wait += customers[i];
            if(wait >= 4) {
                board += 4;
                wait -= 4;
                round++;
                profit = (board*boardingCost)-(round*runningCost);
                if(maxi < profit) {
                    maxi = profit;
                    ans = round;
                }
            }
            else {
                board += wait;
                wait = 0;
                round++;
                profit = (board*boardingCost)-(round*runningCost);
                if(maxi < profit) {
                    maxi = profit;
                    ans = round;
                }
            }
            i++;
        }
        while(wait > 0) {
            if(wait >= 4) {
                board += 4;
                wait -= 4;
                round++;
                profit = (board*boardingCost)-(round*runningCost);
                if(maxi < profit) {
                    maxi = profit;
                    ans = round;
                }
            }
            else {
                board += wait;
                wait = 0;
                round++;
                profit = (board*boardingCost)-(round*runningCost);
                if(maxi < profit) {
                    maxi = profit;
                    ans = round;
                }
            }
        }
        if(maxi == 0) return -1;
        return ans;
    }
};