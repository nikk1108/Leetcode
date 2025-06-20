class Solution {
 public:
  int maxDistance(string s, int k) {
    return max({
        computeMaxDistance(s, k, "NE"),
        computeMaxDistance(s, k, "NW"),
        computeMaxDistance(s, k, "SE"),
        computeMaxDistance(s, k, "SW")
    });
  }

 private:
  int computeMaxDistance(const string& moves, int maxChanges, const string& favoredDirections) {
    int maxDist = 0;
    int netMovement = 0;
    int unfavoredCount = 0;

    for (char move : moves) {
      if (favoredDirections.find(move) != string::npos) {
        ++netMovement;
      } else {
        --netMovement;
        ++unfavoredCount;
      }
      int possibleExtra = min(maxChanges, unfavoredCount);
      maxDist = max(maxDist, netMovement + 2 * possibleExtra);
    }

    return maxDist;
  }
};
