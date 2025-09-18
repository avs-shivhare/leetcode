class TaskManager {
public:
    unordered_map<int,vector<int>> mpp;
    map<pair<int,int>,int,greater<pair<int,int>>> mpp2;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &i: tasks) {
            mpp[i[1]] = {i[2],i[0]};
            mpp2[{i[2],i[1]}] = i[0];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mpp[taskId] = {priority,userId};
        mpp2[{priority,taskId}] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        int old = mpp[taskId][0];
        mpp[taskId][0] = newPriority;
        mpp2.erase({old,taskId});
        mpp2[{newPriority,taskId}] = mpp[taskId][1];
    }
    
    void rmv(int taskId) {
        mpp2.erase({mpp[taskId][0],taskId});
        mpp.erase(taskId);
    }
    
    int execTop() {
        if(mpp.empty()) return -1;
        auto x = *(mpp2.begin());
        int user = x.second;
        mpp.erase(x.first.second);
        mpp2.erase(x.first);
        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */