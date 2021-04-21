#include <iostream>
#include <vector>

int main() {
    int w_max, n;
    std::cin >> w_max >> n;
    std::vector<std::vector<int>> items (n, std::vector<int>(2));
    std::vector<std::vector<int>> dp (n + 1, std::vector<int>(w_max + 1));

    for (int i = 0; i < n; ++ i)
        std::cin >> items[i][0];
    for (int i = 0; i < n; ++ i)
        std::cin >> items[i][1];
    for (int i = 0; i < w_max + 1; ++i)
        dp[0][i] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= w_max; ++j) {
            if (items[i][1] > j) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = std::max(dp[i][j], dp[i][j - items[i][1]] + items[i][0]);
            }
        }
    }
    std::cout << dp[n][w_max];
    return 0;
}
