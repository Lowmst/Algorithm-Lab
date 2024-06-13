#include<iostream>
#include<vector>
#include<ctime>
#define ll long long
#define N 100001

// 埃氏筛 O(lognlogn)
std::vector<ll> Eratosthenes(ll n) {
    std::vector<ll> prime;
    bool is_prime[N];
    for (ll i = 2; i <= n; ++i) is_prime[i] = true;
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            if ((ll)i * i > n) continue;
            for (ll j = i * i; j <= n; j += i)
                // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i 的倍数开始，提高了运行速度
                is_prime[j] = false;  // 是 i 的倍数的均不是素数
        }
    }
    return prime;
}

// 欧拉筛 O(n)
std::vector<ll> Euler(ll n) {
    std::vector<ll> prime;
    bool not_prime[N];
    for (ll i = 2; i <= n; ++i) not_prime[i] = false;
    for (ll i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
            prime.push_back(i);
        }
        for (ll pri_j : prime) {
            if (i * pri_j > n) break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) {
                // i % pri_j == 0
                // 换言之，i 之前被 pri_j 筛过了
                // 由于 pri 里面质数是从小到大的，所以 i 乘上其他的质数的结果一定会被 pri_j 的倍数筛掉，就不需要在这里先筛一次，所以这里直接 break 掉就好了
                break;
            }
        }
    }
    return prime;
}

int main(void) {
    
    double start = clock();
    auto a = Eratosthenes(N - 1);
    double end = clock();
    double last_a = end - start;
    
    start = clock();
    auto b = Euler(N - 1);
    end = clock();
    double last_b = end - start;

    std::cout << last_a << '\n' << last_b;
    
    //for (int i = 0; i < a.size(); i++) std::cout << a[i] << '\n';
    //for (int i = 0; i < b.size(); i++) std::cout << b[i] << '\n';

    return 0;
}