#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // Untuk INT32_MAX

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    // Jenis-jenis bit yang tersedia
    vector<int> bits = { 3, 5, 7 };

    while (t--) {
        int n;
        cin >> n;
        // Inisialisasi DP array dengan nilai yang sangat besar
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;

        // Mengisi DP array
        for (int i = 1; i <= n; ++i) {
            for (auto bit : bits) {
                if (i >= bit && dp[i - bit] != INT32_MAX) {
                    dp[i] = min(dp[i], dp[i - bit] + 1);
                }
            }
        }

        // Menentukan hasil
        if (dp[n] != INT32_MAX) {
            cout << dp[n] << "\n";
        }
        else {
            cout << "TIDAK\n";
        }
    }

    return 0;
}
