#ifndef PRIMES_H
#define PRIMES_H

// returns pointer to array of first m primes (caller must free)
// if m == 0 returns NULL
int* first_m_primes(int m);

// counts number of pairs (i<j) among first m primes whose xor is outside [l,r]
long long count_pairs_outside_range(int m, int l, int r);

#endif // PRIMES_H
