#include <iostream>
#include <iterator>
#include <omp.h>
#include <ostream>
#include <vector>

int main() {
  const int N = 10000000;
  std::vector<int> data(N, 1); // all ones

  for (int threads = 1; threads < 9; threads *= 2) {
    double sum = 0;

    double t0 = omp_get_wtime();
#pragma omp parallel for reduction(+ : sum) num_threads(threads)
    for (int i = 0; i < N; ++i) {
      sum += data[i];
    }
    double t1 = omp_get_wtime();
    std::cout << "# of threads: " << threads << std::endl << "Time: "  << t1-t0 << std::endl << "Sum: " << sum << std::endl;
  }
  return 0;
}