#include <iostream>
#define INF 1000000007

int main() {
    int s, n;
    std::cin >> s >> n;
    int* a = new int[n];
    int* d = new int[s + 1];

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    d[0] = 0;

    for (int i = 1; i <= s; ++i) {
        d[i] = INF;
        for (int j = 0; j < n; ++j) {
            if (i - a[j] >= 0) {
                d[i] = std::min(d[i], d[i - a[j]] + 1);
            }
        }
    }

    if (d[s] == INF) {
        std::cout << "Can't change";
    } else {
        std::cout << d[s];
    }
    return 0;
}
