#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "primes.h"

// estimate upper bound for m-th prime using p_m < m (log m + log log m) for m >= 6
static long long estimate_upper_bound(int m) {
    if (m < 6) return 15; // small safe bound
    double dm = (double)m;
    double bound = dm * (log(dm) + log(log(dm)));
    // add a modest safety margin
    bound += 3.0 * dm;
    long long ibound = (long long)ceil(bound);
    // guard against overflow or too small
    if (ibound < 100) ibound = 100;
    if (ibound > (long long)INT_MAX - 10) ibound = INT_MAX - 10;
    return ibound;
}

// generate first m primes using sieve of eratosthenes
int* first_m_primes(int m) {
    if (m <= 0) return NULL;
    long long bound = estimate_upper_bound(m);
    int n = (int)bound;

    //sieve[i] = 0 means “i is not prime”, 1 means “i is possibly prime”
    unsigned char* sieve = (unsigned char*)malloc((size_t)(n + 1));
    if (!sieve) return NULL;
    for (int i = 0; i <= n; ++i) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    //everything greater than 2 is marked true

    int limit = (int)floor(sqrt((double)n));
    for (int p = 2; p <= limit; ++p) {
        if (sieve[p]) {
            for (long long q = (long long)p * p; q <= n; q += p) sieve[q] = 0; //for evrey number multiples (p*p, p*p+p, p*p+2p, …) as not prime (=0).
        }
    }

    int* primes = (int*)malloc(sizeof(int) * m);
    if (!primes) {
        free(sieve);
        return NULL;
    }

    int found = 0;
    for (int i = 2; i <= n && found < m; ++i) {
        if (sieve[i]) primes[found++] = i; //collect the primes fouund
    }

    // if we didn't find enough primes (very unlikely with the bound) but as a safety
    if (found < m) {
        int candidate = n + 1;
        while (found < m) {
            int isprime = 1;
            int up = (int)floor(sqrt((double)candidate));
            for (int d = 2; d <= up; ++d) {
                if (candidate % d == 0) { isprime = 0; break; }
            }
            if (isprime) primes[found++] = candidate;
            candidate++;
        }
    }

    free(sieve);
    return primes;
}

// counts pairs with xor outside [l,r]
// uses long long for count since pairs can be large
long long count_pairs_outside_range(int m, int l, int r) {
    if (m <= 1) return 0;
    int* p = first_m_primes(m);
    if (!p) return 0;
    long long cnt = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            int x = p[i] ^ p[j];
            if (x < l || x > r) cnt++;
        }
    }
    free(p);
    return cnt;
}
