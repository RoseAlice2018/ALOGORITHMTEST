#include <vector>
using namespace std;

class Solution {
public:
	//到家的最少跳跃次数
	struct point {
		int back;
		int pos;
		int step;
		point(int back, int pos, int step) {
			this->back = back;
			this->pos = pos;
			this->step = step;
		}
	};
	int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
		//不能跳到负整数位置 和 forbidden 位置
		//不能连续往后跳两次
		unordered_set<int> uset;
		for (auto k : forbidden) uset.insert(k);
		queue<point> q;
		q.push(point(0, 0, 0));
		while (!q.empty()) {
			point p = q.front();
			q.pop();
			if (p.pos == x) return p.step;
			//前
			if (uset.count(p.pos + a) == 0 && p.pos + a <= 4000) {
				q.push(point(0, p.pos + a, p.step + 1));
				uset.insert(p.pos + a); //加入队列就标记为访问过
			}
			//后
			if (p.pos - b >= 0 && uset.count(p.pos - b) == 0 && p.back == 0) {
				q.push(point(1, p.pos - b, p.step + 1));
				//向后不需要标记为访问过
			}
		}
		return -1;
	}
};