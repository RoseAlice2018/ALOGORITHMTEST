#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void split(string s,vector<string>& res,char delimiter,int delimitercnt)
    {

    }
    bool checkIPV4(string IP)
    {
        string temp;
        int count=0;
        for(int i=0;i<IP.size();i++)
        {
            if(IP[i]=='0')
            {
                count++;
            }           
            else if(IP[i]=='.') 
            {
                count++;
            } 

        }       
    }
    bool checkIPV6(string IP)
    {

    }
    string validIPAddress(string IP) {
        if(IP.size()<4)
        {
            return "Neither";
        }
        else 
        {
            for(int i=0;i<IP.size();i++)
            {
                if(IP[i]=='.')
                {
                    if(checkIPV4(IP))
                        return "IPV4";
                    else 
                        return "Neither";
                }
                else if(IP[i]==':')
                {
                    if(checkIPV6(IP))
                        return "IPV6";
                    else 
                        return "Neither";
                }
            }
        }
    }
};