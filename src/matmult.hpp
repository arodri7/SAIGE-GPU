#ifndef MATMULT_HPP
#define MATMULT_HPP
#pragma once


#include "gemm.hpp"
//#include "mat.hpp"


template <typename float>
arma::fmat matmult(const bool transx, const bool transy, const float alpha,
  const arma::fmat &x, const arma::fcolvec &y, arma::fmat &ret)
{
  len_t m, n, k;
  const len_t mx = x.nrows();
  const len_t my = y.nrows();

  matmult_params(transx, transy, mx, x.ncols(), my, y.ncols(), &m, &n, &k);

  if (m != ret.nrows() || n != ret.ncols())
    ret.resize(m, n);

  const char ctransx = transx ? 'T' : 'N';
  const char ctransy = transy ? 'T' : 'N';

  gemm(ctransx, ctransy, m, n, k, alpha, x.data_ptr(), mx, y.data_ptr(), my,
    (float)0, ret.data_ptr(), m);
}


#endif
