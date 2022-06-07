#ifndef _ZIPF_H_
#define _ZIPF_H_

#include <iostream>
#include <climits>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime>


class Zipf {
public:
    Zipf() {}
    ~Zipf() {}
    void Init(long max, double  theta = 0.999);
    long Next();
private:
    double theta, alpha, zetan, zeta2theta, eta;
    long max_n;
};



void Zipf::Init(long max, double t) {
    srand(time(NULL));
    max_n = max;
    theta = t;
    alpha = 1.0 / (1.0 - theta);

    zetan = 0.0;
    for (int i = 0; i < max_n; i++) {
        zetan += 1.0 / pow((double) (i + 1), theta);
    }

    zeta2theta = 0.0;
    for (int i = 0; i < 2; i++) {
        zeta2theta += 1.0 / pow((double) (i + 1), theta);
    }

    eta = (1.0 - pow(2.0 / max_n, 1.0 - theta)) / (1.0 - zeta2theta / zetan);
}

long Zipf::Next() {
    double u = (double) rand() / RAND_MAX; // Uniform random number (0 < z < 1)
    double uz = u * zetan;

    if (uz < 1.0) {
        return 0L;
    } else if (uz < 1.0 + pow(0.5, theta)) {
        return 1L;
    } else {
        return (long) (max_n * pow(eta * u - eta + 1, alpha));
    }
}

#endif