#ifndef GEMM_HPP
#define GEMM_HPP
#pragma once


extern "C" {
extern void sgemm_(const char *transa, const char *transb, const int *m,
  const int *n, const int *k, const float *alpha,
  const float *a, const int *lda, const float *b,
  const int *ldb, const float *beta, float *c, const int *ldc);

extern void dgemm_(const char *transa, const char *transb, const int *m,
  const int *n, const int *k, const double *alpha,
  const double *a, const int *lda, const double *b,
  const int *ldb, const double *beta, double *c, const int *ldc);
}


namespace
{
  inline void gemm(const char transa, const char transb, const int m,
    const int n, const int k, const float alpha,
    const float *a, const int lda, const float *b,
    const int ldb, const float beta, float *c, const int ldc)
  {
    sgemm_(&transa, &transb, &m, &n, &k, &alpha, a, &lda, b, &ldb, &beta, c,
      &ldc);
  }

  inline void gemm(const char transa, const char transb, const int m,
    const int n, const int k, const double alpha,
    const double *a, const int lda, const double *b,
    const int ldb, const double beta, double *c, const int ldc)
  {
    dgemm_(&transa, &transb, &m, &n, &k, &alpha, a, &lda, b, &ldb, &beta, c,
      &ldc);
  }



  inline void matmult_params(const bool transx, const bool transy,
    const len_t mx, const len_t nx, const len_t my, const len_t ny, len_t *m,
    len_t *n, len_t *k)
  {
    if (!transx && !transy)
    {
      if (nx != my)
        throw std::runtime_error("non-conformable arguments");
    }
    else if (transx && transy)
    {
      if (mx != ny)
        throw std::runtime_error("non-conformable arguments");
    }
    else if (transx && !transy)
    {
      if (mx != my)
        throw std::runtime_error("non-conformable arguments");
    }
    else if (!transx && transy)
    {
      if (nx != ny)
        throw std::runtime_error("non-conformable arguments");
    }

    if (transx)
    {
      *m = nx;
      *k = mx;
    }
    else
    {
      *m = mx;
      *k = nx;
    }

    *n = transy ? my : ny;
  }
}


#endif
