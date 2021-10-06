

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int hundred = 0;
    int ten = 0;
    int one = 0;
    while(N>0)
    {
        if(N>=100)
        {
            int tmp = (N-N%100)/100;
            hundred = tmp;
            N=N%100;
        }
        else if(N>=10)
        {
            int tmp = (N-N%10)/10;
            ten = tmp;
            N=N%10;
        }
        else 
        {
            one = N;
            N=0;
        }
    }
    int res = 0;
    while(K>0)
    {
        if(hundred<9)
        {
            int tmp = 9-hundred;
            if(tmp<K)
            {
                K-=tmp;
                hundred=9;
            }
            else 
            {
                hundred+=K;
                K=0;
            }
        }
        else if(ten<9)
        {
            int tmp = 9-ten;
            if(tmp<K)
            {
                K-=tmp;
                ten=9;
            }
            else 
            {
                
                ten+=K;K=0;
            }           
        }
        else if(one<9)
        {
            int tmp = 9-one;
            if(tmp<K)
            {
                K-=tmp;
                one=9;
            }
            else 
            {
                
                one+=K;K=0;
            }
        }
        else{
            K=0;
        }
    }
    res = hundred*100+ten*10+one;
    return res;
}
