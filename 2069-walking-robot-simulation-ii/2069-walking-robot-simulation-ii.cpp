class Robot {
public: 
    int n,m;
    int d = 0;
    int x = 0,y = 0;
    Robot(int width, int height) {
        n = width;
        m = height;
    }
    void east(int num) {
        int total = (2*n)+(2*m)-4;
        num = num%total;
        if(num == 0 && x == 0 && y == 0) {
            d = 3;
            return;
        }
        int next = min(n-1,x+num);
        num -= next-x;
        x = next;
        if(num == 0) return;
        if(x == n-1) d = (d+1)%4;
        north(num);
    }
    void north(int num) {
        int next;
        int total = 2*n+2*m-4;
        num = num%total;
        if(num == 0 && x == n-1 && y == 0) {
            d = 0;
            return;
        }
        next = min(m-1,y+num);
        num -= next-y;
        y = next;
        if(num == 0) return;
        if(y == m-1) d = (d+1)%4;
        west(num);
    }
    void west(int num) {
        int next;
        int total = 2*n+2*m-4;
        num = num%total;
        if(num == 0 && x == n-1 && y == m-1) {
            d = 1;
            return;
        }
        next = max(0,x-num);
        num -= x-next;
        x = next;
        if(num == 0) return;
        if(x == 0) d = (d+1)%4;
        south(num);
    }
    void south(int num) {
        int next;
        int total = 2*n+2*m-4;
        num = num%total;
        if(num == 0 && x == 0 && y == m-1) {
            d = 2;
            return;
        }
        next = max(0,y-num);
        num -= y-next;
        y = next;
        if(num == 0) return;
        if(y == 0) d = (d+1)%4;
        east(num);
    }
    void step(int num) {
        //cout<<d<<endl;
        if(d == 0) return east(num);
        else if(d == 1) return north(num);
        else if(d == 2) return west(num);
        else south(num);
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(d == 0) return "East";
        else if(d == 1) return "North";
        else if(d == 2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */