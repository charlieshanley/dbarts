#ifndef EXTERNAL_LINEAR_ALGEBRA_H
#define EXTERNAL_LINEAR_ALGEBRA_H

#include "stddef.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
  
  // y := alpha * x + y
  void ext_addVectorsInPlace(const double* x, ext_size_t length, double alpha, double* y);
  // z = alpha * x + y; z must be distinct from x and y
  void ext_addVectors(const double* restrict x, ext_size_t length, double alpha, const double* restrict y, double* restrict z);
  
  // x := alpha * x
  void ext_scalarMultiplyVectorInPlace(double* x, ext_size_t length, double alpha);
  // y = alpha * x; y must be distinct from x
  void ext_scalarMultiplyVector(const double* restrict x, ext_size_t length, double alpha, double* restrict y);
  
  // z = x .* y; z must be distinct from x and y
  void ext_hadamardMultiplyVectors(const double* restrict x, ext_size_t length, const double* restrict y, double* restrict z);
  
  // b = Ax
  void ext_leftMultiplyMatrixAndVector(const double* A, ext_size_t n, ext_size_t p, const double* x, double* b);
  
  double ext_sumVectorElements(const double* x, ext_size_t length);
  double ext_sumSquaresOfVectorElements(const double* x, ext_size_t length);
  
  // least squares solution to Xb = y
  // suggested tolerance: 1.0e-7
  // if residuals or message are NULL, are not used
  int ext_findLeastSquaresFit(const double* y, ext_size_t n, const double* x, ext_size_t p, double* b,
                              double tolerance, double* residuals, char** message);
  int ext_findLeastSquaresFitInPlace(double* y, ext_size_t n, double* x, ext_size_t p, double* b,
                                     double tolerance, double* residuals, char** message);
  
  
  void ext_setVectorToConstant(double* x, ext_size_t length, double alpha);

#ifdef __cplusplus
}
#endif
  
#endif // EXTERNAL_LINEAR_ALGEBRA_H
