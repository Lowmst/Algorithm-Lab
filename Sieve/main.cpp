#include<iostream>
#include<vector>
#include<ctime>
#define ll long long
#define N 100001

// ����ɸ O(lognlogn)
std::vector<ll> Eratosthenes(ll n) {
    std::vector<ll> prime;
    bool is_prime[N];
    for (ll i = 2; i <= n; ++i) is_prime[i] = true;
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            if ((ll)i * i > n) continue;
            for (ll j = i * i; j <= n; j += i)
                // ��Ϊ�� 2 �� i - 1 �ı�������֮ǰɸ���ˣ�����ֱ�Ӵ� i �ı�����ʼ������������ٶ�
                is_prime[j] = false;  // �� i �ı����ľ���������
        }
    }
    return prime;
}

// ŷ��ɸ O(n)
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
                // ����֮��i ֮ǰ�� pri_j ɸ����
                // ���� pri ���������Ǵ�С����ģ����� i ���������������Ľ��һ���ᱻ pri_j �ı���ɸ�����Ͳ���Ҫ��������ɸһ�Σ���������ֱ�� break ���ͺ���
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