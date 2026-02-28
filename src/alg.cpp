// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) {
    return false;
  }

  if (value == 2) {
    return true;
  }

  if (value % 2 == 0) {
    return false;
  }

  for (uint64_t i = 3; i <= value / i; i += 2) {
    if (value % i == 0) {
      return false;
    }
  }

  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) {
    return 0;
  }

  uint64_t count = 0;
  uint64_t current = 1;

  while (count < n) {
    current++;

    if (checkPrime(current)) {
      count++;
    }
  }

  return current;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t current = value + 1;

  while (true) {
    if (checkPrime(current)) {
      return current;
    }
    current++;
  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;

  for (uint64_t i = 2; i < hbound; ++i) {
    if (checkPrime(i)) {
      sum += i;
    }
  }

  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound < 3) {
    return 0;
  }

  uint64_t count = 0;
  uint64_t start = lbound;

  if (start < 3) {
    start = 3;
  }

  for (uint64_t i = start; i + 2 < hbound; ++i) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      count++;
    }
  }

  return count;
}
