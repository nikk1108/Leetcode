class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dx = abs(x - z);
        int dy = abs(y - z);

        if (dx < dy) return 1;
        if (dx > dy) return 2;
        return 0; 
    }
};
