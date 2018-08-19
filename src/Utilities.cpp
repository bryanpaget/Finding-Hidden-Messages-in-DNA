unsigned int random(unsigned int n) {
  if (n == 1) {
    uniform_int_distribution<int> distribution(0, 1);
    return distribution(rng);
  } else {
    uniform_int_distribution<int> distribution(0, n-1);
    return distribution(rng);
  }
}

