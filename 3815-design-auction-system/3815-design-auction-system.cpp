class AuctionSystem {
public:
    unordered_map<int,unordered_map<int,int>> st;
    map<int,set<vector<int>,greater<vector<int>>>> mpp;
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        updateBid(userId,itemId,bidAmount);
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        if(st[userId].find(itemId) != st[userId].end()) {
            int old = st[userId][itemId];
            mpp[itemId].erase({old,userId});
            st[userId][itemId] = newAmount;
            mpp[itemId].insert({newAmount,userId});
        }
        else {
            mpp[itemId].insert({newAmount,userId});
            st[userId][itemId] = newAmount;
        }
    }
    
    void removeBid(int userId, int itemId) {
        int old = st[userId][itemId];
        st[userId].erase(itemId);
        mpp[itemId].erase({old,userId});
    }
    
    int getHighestBidder(int itemId) {
        if(!mpp[itemId].empty()) {
            auto temp = *(mpp[itemId].begin());
            return temp[1];
        }
        return -1;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */