#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum capacity: ";
    cin >> W;

    vector<int> weights(n), values(n);

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j],
                               values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << "Maximum Profit: " << dp[n][W] << endl;

    vector<int> taken;
    int j = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            taken.push_back(i - 1);
            j -= weights[i - 1];
        }
    }

    cout << "Items taken (0-based index): ";
    for (int i = taken.size() - 1; i >= 0; i--)
        cout << taken[i] << " ";
    cout << endl;

    return 0;
}
