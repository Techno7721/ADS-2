// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double result = value;
    for (uint16_t i = 0; i < n-1; ++i) {
        result = result * value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

double calcItem(double x, uint16_t n) {
    double x1 = pown(x, n);
    uint64_t n1 = fact(n);
    double res = x1 / n1;
    return res;
}

double expn(double x, uint16_t count) {
    double res = 1;
    for (int i = 1; i < count; ++i) {
        res += calcItem(x, i);
    }
    return res;
}

double sinn(double x, uint16_t count) {
    double res = x;
    for (int i = 2; i < count; ++i) {
        res += pown(-1, (i - 1)) * calcItem(x, ((2 * i) - 1));
    }
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 1;
    for (int i = 2; i < count; ++i) {
        res += pown(-1, (i - 1)) * calcItem(x, ((2 * i) - 2));
    }
    return res;
}
