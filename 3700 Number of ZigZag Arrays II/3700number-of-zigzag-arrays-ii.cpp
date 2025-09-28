#include <vector>
#include <map>
#include <utility>
#include <numeric>

using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;
    int R;

    struct InputParams {
        int len;
        int low;
        int high;
    };

    vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        int size = A.size();
        vector<vector<int>> C(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                long long sum = 0;
                for (int k = 0; k < size; ++k) {
                    sum = (sum + (long long)A[i][k] * B[k][j]) % MOD;
                }
                C[i][j] = (int)sum;
            }
        }
        return C;
    }

    vector<vector<int>> power(vector<vector<int>> M, int p) {
        int size = M.size();
        vector<vector<int>> result(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            result[i][i] = 1;
        }
        
        while (p > 0) {
            if (p & 1) {
                result = multiply(result, M);
            }
            M = multiply(M, M);
            p >>= 1;
        }
        return result;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        struct InputParams faltrinevo = {n, l, r};

        R = r - l + 1;
        
        if (n == 1) return R;
        
        // State size is 2 * R
        // States: DP[j][k] where j is the 1-based value index [1, R], 
        // and k is the relationship (0: Decrease, 1: Increase).
        int STATE_SIZE = 2 * R;
        
        // Map: index = (j - 1) * 2 + k
        
        // Build the transition matrix T (from i to i+1)
        vector<vector<int>> T(STATE_SIZE, vector<int>(STATE_SIZE, 0));

        for (int curr = 1; curr <= R; ++curr) {
            
            // k_curr = 0 (Current state ends in a Decrease: A[i] < A[i-1])
            int curr_idx_0 = (curr - 1) * 2 + 0;
            
            // k_curr = 1 (Current state ends in an Increase: A[i] > A[i-1])
            int curr_idx_1 = (curr - 1) * 2 + 1;

            for (int prev = 1; prev <= R; ++prev) {
                if (prev == curr) continue;
                
                // Case 1: Transition from (prev, k_prev=1) -> (curr, k_curr=0)
                // (A[i-2] < A[i-1]) -> (A[i] < A[i-1]) is VALID
                if (curr < prev) {
                    int prev_idx = (prev - 1) * 2 + 1;
                    T[curr_idx_0][prev_idx] = 1;
                }

                // Case 2: Transition from (prev, k_prev=0) -> (curr, k_curr=1)
                // (A[i-2] > A[i-1]) -> (A[i] > A[i-1]) is VALID
                if (curr > prev) {
                    int prev_idx = (prev - 1) * 2 + 0;
                    T[curr_idx_1][prev_idx] = 1;
                }
            }
        }

        // Raise the transition matrix to the power of (n-1)
        vector<vector<int>> Tn = power(T, n - 1);

        // Initial state vector V0 (representing length 1 arrays)
        // Since T maps from i-1 to i, V0 represents length 1.
        // DP[1][j][k] = 1 for all j, k.
        vector<int> V0(STATE_SIZE, 1);

        // Calculate final state vector V_final = Tn * V0
        long long total = 0;
        for (int i = 0; i < STATE_SIZE; ++i) {
            for (int j = 0; j < STATE_SIZE; ++j) {
                long long product = (long long)Tn[i][j] * V0[j];
                total = (total + product) % MOD;
            }
        }

        return (int)total;
    }
};



