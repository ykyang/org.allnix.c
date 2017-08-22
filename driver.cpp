#include <iostream>
#include <chrono>
#include <cstdio>
using namespace std;

int main() {
  int count = 1000;
  int n = 1000001;
  double *y = new double[n];
  double *x = new double[n];
  double a = 0.5;
  for ( int i = 0; i < n; i++) {
    x[i] = i;
    y[i] = 1.0;
  }
  
  
  auto t1 = std::chrono::high_resolution_clock::now();
  for (int j = 0; j < count; j++) {
    for (int i = 0; i < n; i++) {
      y[i] = a*x[i] + y[i];
    }
  }
  auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "time = "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";
  
  printf("y: %f\n", y[n-1]);
  cout << "y: " << y[n-1] << endl;
  return 0;
}
