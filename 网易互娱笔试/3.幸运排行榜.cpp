#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        map<int,int> dic;
        set<int> getPrize;
        while(N--)
        {
            int P,S;
            cin>>P>>S;
            if(dic.count(P)&&dic[P]<S)
            {
                //更新
                dic[P]=S;
                int mid = dic.size()/2;
                if(dic.size()%2!=0)
                {
                    auto iter = dic.begin();
                    while(mid>0)
                    {
                        iter++;
                        mid--;
                    }
                   
                    getPrize.insert(iter->first);
                }
                else 
                {
                    auto iter = dic.begin();
                    int mid = dic.size()/2 -1;
                    while(mid > 0)
                    {
                        iter++;
                        mid--;
                    }
                    int t1 = iter->second,t3 = iter->first;
                    iter++;
                    int t2 = iter->second,t4  = iter->first;
                    if(t1 == t2)
                    {
                        getPrize.insert(t3);
                        getPrize.insert(t4);
                    }
                }
            }
            else if(!dic.count(P))
            {
                //更新
                dic[P]=S;
                int mid = dic.size()/2;
                if(dic.size()%2!=0)
                {
                    auto iter = dic.begin();
                    while(mid>0)
                    {
                        iter++;
                        mid--;
                    }
                   
                    getPrize.insert(iter->first);
                }
                else 
                {
                    auto iter = dic.begin();
                    int mid = dic.size()/2 -1;
                    while(mid > 0)
                    {
                        iter++;
                        mid--;
                    }
                    int t1 = iter->second,t3 = iter->first;
                    iter++;
                    int t2 = iter->second,t4  = iter->first;
                    if(t1 == t2)
                    {
                        getPrize.insert(t3);
                        getPrize.insert(t4);
                    }
                }
            }
        }
        cout<<getPrize.size();
    }
    return 0;
}