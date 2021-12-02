#include <iostream>
#include <vector>
#include <string.h>

#define HASH_NUMBER 3

using namespace std;

vector<long long> p_pow(19);

int main(void) {
    

    p_pow[0] = 1;
    for (size_t i = 1; i < p_pow.size(); ++i)
        p_pow[i] = p_pow[i - 1] * HASH_NUMBER;

    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


}