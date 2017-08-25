#include <iostream>
#include <chrono>
#include <cstdio>
using namespace std;

void axpy(int n, double a, double *x, double* y) {
    for (int i = 0; i < n; i++) {
        y[i] = a*x[i] + y[i];
    }
}

void test_axpy() {
    int count = 1000;
    int n = 1000000;
    double * x = new double[n];
    double * y = new double[n];
    double a = 0.5;
    
    for (int i = 0; i < n; i++) {
        x[i] = i;
        y[i] = 1.0;
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < count; j++) {
        axpy(n, a, x, y);    
//        for (int i = 0; i < n; i++) {
//          y[i] = a*x[i] + y[i];
//        }
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    
     std::chrono::duration<double> fp_s = t2 - t1;
    
    std::cout << "test_axpy: " << fp_s.count()
              << ", y = " << y[n-1] << endl;
    printf("y: %f\n", y[n-1]);
    delete [] x;
    delete [] y;
}

int main() {
    test_axpy();
    
//  int count = 1000;
//  int n = 1000000;
//  double *y = new double[n];
//  double *x = new double[n];
//  double a = 0.5;
//  for ( int i = 0; i < n; i++) {
//    x[i] = i;
//    y[i] = 1.0;
//  }
//  
//  
//  auto t1 = std::chrono::high_resolution_clock::now();
//  for (int j = 0; j < count; j++) {
//    for (int i = 0; i < n; i++) {
//      y[i] = a*x[i] + y[i];
//    }
//  }
//  auto t2 = std::chrono::high_resolution_clock::now();
//    std::cout << "time = "
//              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
//              << " milliseconds\n";
//  
//  printf("y: %f\n", y[n-1]);
//  cout << "y: " << y[n-1] << endl;
  return 0;
}
