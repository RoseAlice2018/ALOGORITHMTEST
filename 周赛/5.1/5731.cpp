#include<vector>
#include<stack>
#include<set>
using namespace std;
class SeatManager {
public:
    SeatManager(int n) {
        for(int i=n;i>=1;i--)
            seats.push(i);
    }
    
    int reserve() {
        int ret = seats.top();
        seats.pop();
        return ret;
    }
    
    void unreserve(int seatNumber) {
       stack<int> temp;
       if(seats.empty())
       {
           seats.push(seatNumber);
           return;
       }
       if(seatNumber<seats.top())
       {
           seats.push(seatNumber);
           return;
       }
       else 
       {
           while(!seats.empty()&&seats.top()<seatNumber)
           {
               int t = seats.top();
               temp.push(t);
               seats.pop();
           }
           seats.push(seatNumber);
           while(!temp.empty())
           {
               seats.push(temp.top());
               temp.pop();
           }
           return;         
       }
    }
private:
    stack<int> seats;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

class SeatManager {
public:
    SeatManager(int n) {
        for(int i=n;i>=1;i--)
            seats.insert(i);
    }
    
    int reserve() {
        int ret = *seats.begin();
        seats.erase(ret);
        return ret;
    }
    
    void unreserve(int seatNumber) {
      seats.insert(seatNumber);
    }
private:
    set<int> seats;
};