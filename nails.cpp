#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> coords (n);
    std::vector<int> dp (n);

    for (int i = 0; i < n; ++i)
        std::cin >> coords[i];

    std::sort(coords.begin(), coords.end());

    dp[1] = coords[1] - coords[0];
    dp[2] = coords[2] - coords[0];
    for (int i = 3; i < n; ++i) {
        dp[i] = std::min(dp[i - 1], dp[i - 2]) + coords[i] - coords[i - 1];
    }

    std::cout << dp[n - 1];
    return 0;
}
