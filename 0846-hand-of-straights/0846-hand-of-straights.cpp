class Solution {
public:
    // bool isNStraightHand(vector<int>& hand, int k) {
    //     priority_queue<int> q;
    //     if(hand.size()%k != 0) return false;
    //     sort(hand.begin(),hand.end());
    //     while(hand.size()) {
    //         int i =0;
    //         while(i<hand.size() && q.size() < k) {
    //             if(q.empty() || q.top()+1 == hand[i] || q.top()-1 == hand[i]) {
    //                 q.push(hand[i]);
    //                 hand.erase(hand.begin()+i);
    //             }
    //             else i++;
    //         }
    //         if(q.size() != k) return false;
    //         while(!q.empty()) q.pop();
    //     }
    //     return true;
    // }

    // bool isNStraightHand(vector<int>& hand, int k) {
    //     vector<int> q;
    //     if(hand.size()%k != 0) return false;
    //     sort(hand.begin(),hand.end());
    //     while(hand.size()) {
    //         int i =0;
    //         while(i<hand.size() && q.size() < k) {
    //             if(q.empty() || q.back()+1 == hand[i] || q.back()-1 == hand[i]) {
    //                 q.push_back(hand[i]);
    //                 hand.erase(hand.begin()+i);
    //             }
    //             else i++;
    //         }
    //         if(q.size() != k) return false;
    //         q.clear();
    //     }
    //     return true;
    // }

    // bool isNStraightHand(vector<int>& hand, int k) {
    //     if(hand.size()%k != 0) return false;
    //     sort(hand.begin(),hand.end());
    //     while(!hand.empty()) {
    //         vector<int> temp;
    //         int i =0;
    //         while(i<hand.size() && temp.size() != k) {
    //             if(temp.empty() || temp.back() +1 == hand[i]) {
    //                 temp.push_back(hand[i]);
    //                 hand.erase(hand.begin()+i);
    //             }
    //             else i++;
    //         }
    //         if(temp.size() != k) return false;
    //     }
    //     return true;
    // }

    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size()%k != 0) return false;
        sort(hand.begin(),hand.end());
        int n = hand.size();
        vector<bool> vis(n,false);
        while(n >0) {
            int i =0;
            vector<int> temp;
            while(i<hand.size() && temp.size() != k) {
                if(vis[i]) {
                    i++;
                    continue;
                }
                else if(temp.empty() || temp.back() +1 == hand[i]) {
                    vis[i] = true;
                    temp.push_back(hand[i]);
                    n--;
                }
                i++;
            }
            if(temp.size() != k) return false;
        }
        return true;
    }
};