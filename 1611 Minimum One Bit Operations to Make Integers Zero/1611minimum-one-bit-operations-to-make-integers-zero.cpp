class Solution {
public:
    int minimumOneBitOperations(int num) {
        if (num == 0)
            return 0;
        
        int highestPower = 1;
        while (highestPower * 2 <= num)
            highestPower <<= 1;
        
        return minimumOneBitOperations(num ^ (highestPower | (highestPower >> 1))) + highestPower;
    }
};
