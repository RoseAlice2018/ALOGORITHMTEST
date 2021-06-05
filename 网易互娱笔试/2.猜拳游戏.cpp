#include <iostream>
#include <set>
using namespace std;
bool compare(char A, char B)
{
    //win
    if ((A == 'R' && B == 'S') || (A == 'S' && B == 'C') || (A == 'C' && B == 'R'))
        return true;
    //lose
    else if ((A == 'R' && B == 'C') || (A == 'S' && B == 'R') || (A == 'C' && B == 'S'))
        return false;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        string test;
        cin >> test;
        int max_leaft = 0;
        for (int i = 0; i < N; i++)
        {
            int begin = i;
            int next = i + 1 >= N ? 0 : i + 1;
            int temp_M = M;
            int temp_N = N;
            set<int> del;
            while (temp_M--)
            {
                //平手
                if (test[begin] == test[next])
                {
                    begin = next;
                    next = begin + 1 >= N ? 0 : begin + 1;
                }
                else
                {
                    if (compare(test[begin], test[next]))
                    {
                        //win
                        temp_N--; //淘汰一个
                        del.insert(next);
                        next = next + 1 >= N ? 0 : next + 1;
                    }
                    else
                    {
                        //lose
                        temp_N--; //淘汰一个
                        del.insert(begin);
                        //cout<<begin<<endl;
                        begin = next;
                        next = begin + 1 >= N ? 0 : begin + 1;
                    }
                }
                if (temp_N <= max_leaft)
                    break;
                while (del.count(next))
                {
                    next = next + 1 >= N ? 0 : next + 1;
                }
            }
            if (temp_N > max_leaft)
                max_leaft = temp_N;
        }
        cout << max_leaft << endl;
    }
    return 0;
}