class Solution {
public:
    int maxBottlesDrunk(int full, int ex) {
        int drank = full;
        int empty = full;
        while (empty >= ex) {
            empty = empty - ex + 1;
            ex++;
            drank++;
        }
        return drank;
    }
};
