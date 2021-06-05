#include <iostream>
#include <vector>
using namespace std;
int isboy(vector<int>&A,vector<int>&B,int Ai,int Bm)
{
    int boyA=0,boyB=0;
    for(int i=0;i<3;i++)
    {
        if(i!=Ai)
            boyA+=A[i];
        if(i!=Bm)
            boyB+=B[i];
    }
    if(boyA<boyB)
        return 1;
    return 0;
}
int isgirl(vector<int>&A,vector<int>&B,int Ai,int Bm)
{
    int girlA=0,girlB=0;
    for(int i=3;i<6;i++)
    {
        if(i!=Ai)
            girlA+=A[i];
        if(i!=Bm)
            girlB+=B[i];
    }
    if(girlA<girlB)
        return 1;
    return 0;
}
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        //输入A
        int ret = 0;
        int A1,A2,A3,A4,A5,A6;
        cin>>A1>>A2>>A3>>A4>>A5>>A6;
        vector<int> A;
        A.push_back(A1);A.push_back(A2);
        A.push_back(A3);A.push_back(A4);
        A.push_back(A5);A.push_back(A6);
        //输入B
        int B1,B2,B3,B4,B5,B6;
        cin>>B1>>B2>>B3>>B4>>B5>>B6;
        vector<int> B;
        B.push_back(B1);B.push_back(B2);
        B.push_back(B3);B.push_back(B4);
        B.push_back(B5);B.push_back(B6);
        for(int i=0;i<3;i++)
        {
            //选择A的男
            //int count = 0;
            int A_boy = A[i];
            for(int j=3;j<6;j++)
            {
                int A_girl = A[j];
                for(int m=0;m<3;m++)
                {
                    int B_boy = B[m];
                    for(int n=3;n<6;n++)
                    {
                        int B_girl = B[n];
                        int count = 0;
                        if(A_boy+A_girl<B_boy+B_girl)
                            count++;
                        count+=isboy(A,B,i,m);
                        count+=isgirl(A,B,j,n);
                        if(count>=2)
                            ret++;
                    }
                }
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}