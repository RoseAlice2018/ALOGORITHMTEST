#include <iostream>
#include <cstdlib>
#include <set>
#include <stdio.h>
using namespace std;

int main()
{
    int begin,end;
    set<int> alreadyexist;
    cout<<"请输入随机数范围：a-b 格式如 1 30"<<endl;
    cin>> begin>>end;
    while(1)
    {
        int tmp = rand()%(end+1);
        if(tmp==0)
            continue;
        if(alreadyexist.count(tmp))
        {
            continue;
        }
        else 
        {
            alreadyexist.insert(tmp);
            cout << "本期的幸运数字是  "<<tmp<< " "<<endl;
        }
        cout<<"是否结束？y/n\n";
        char t;
        cin>>t;
        if(t=='n')
        {
            continue;
        }
        else
        {
            printf("bye");
            break;
        }
    }
    return 0;
}