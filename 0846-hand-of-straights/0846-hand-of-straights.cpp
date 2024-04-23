class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        priority_queue<int> q;
        if(hand.size()%k != 0) return false;
        sort(hand.begin(),hand.end());
        while(hand.size()) {
            int i =0;
            while(i<hand.size() && q.size() < k) {
                if(q.empty() || q.top()+1 == hand[i] || q.top()-1 == hand[i]) {
                    q.push(hand[i]);
                    hand.erase(hand.begin()+i);
                }
                else i++;
            }
            if(q.size() != k) return false;
            while(!q.empty()) q.pop();
        }
        return true;
    }
};