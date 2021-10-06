// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B) {
    // write your code in C++14 (g++ 6.2.0)
    if(A==B)
    {
        if(A==1)
            return 0;
        else 
            return A/2;
    }
    else 
    {
        if(A>B)
            ;
        else 
        {
            int tmp =A;
            A = B;
            B = tmp;
        }
    }
    if(A/4>=B)
    {
        return A/4;
    }
    else 
    {
        //A/4<B
        if(A/3>=B)
        {
            return B;
        }
        else 
        {
           if(A/2>=B)
           {
               return A/3;
           }
           else 
           {
               if(3*B>2*A)
               {
                   return B/2;
               }    
               else
               {
                   return A/3;
               }
           }
        }
    }
}
