class Solution {
public:
    int totalMoney(int n) {
        int A = n % 7;
        int B = (n-A)/7;
        return (2*B+A+1)*A/2+(B+7)*B*7/2;
    }
};