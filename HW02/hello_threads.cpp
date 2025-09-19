#include <cstdio>
#include <thread>
#include <vector>

void say_hello(int thread, int total_threads) {
  printf("Hello from thread %i of %i\n", thread, total_threads);
}

int main() {

  const int total_threads = 5;
  std::vector<std::thread> threads;
  threads.reserve (total_threads) ;

  for (int thread = 0; thread < total_threads; thread++) {
    threads.emplace_back(say_hello , thread , total_threads );
  }

  for ( auto & t : threads ) t . join () ;
  
  return 0;
}