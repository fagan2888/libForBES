/* 
 * File:   SVDHelper.cpp
 * Author: Pantelis Sopasakis
 * 
 * Created on April 9, 2017, 12:23 PM
 */

#include "SVDHelper.h"

const int SVDHelper::SVD_SUCCESS = 0;

int SVDHelper::dsvd(const double* X, int m, int n, double* S, double* U, double* V) {
    double * A = new double[m * n];
    for (int i = 0; i < m * n; i++) {
        A[i] = X[i];
    }
    int lwork = -1;
    int info = -9;
    int lda = m;
    int ldu = m;
    int ldvt = n;
    double wkopt;
    double * work;
    char * all = const_cast<char*> ("all");
    LAPACK_dgesvd(all, all, &m, &n, A, &lda, S, U, &ldu, V, &ldvt, &wkopt, &lwork, &info);
    lwork = static_cast<int> (wkopt);
    work = new double[lwork];
    LAPACK_dgesvd(all, all, &m, &n, A, &lda, S, U, &ldu, V, &ldvt, work, &lwork, &info);
    delete[] work;
    delete[] A;
    return info;
}

int SVDHelper::nullspace(double* A, int m, int n, double*& nullSpace, int& nullspaceDim) {
    nullspaceDim = 0;
    nullSpace = NULL;
    const int s = MIN(m, n);
    double * S = new double[s];
    double * U = new double[m * m];
    double * V = new double[n * n];

    int info = dsvd(A, m, n, S, U, V);

    if (info > 0) {
        delete[] S;
        delete[] U;
        delete[] V;
        delete[] nullSpace;
        return info;
    }

    int *idx_v = new int[n];
    int rank_deficiency = (n > m) ? (n - m) : 0;
    int num_zero_sv = 0;
    int j = 0;
    for (int i = 0; i < s; ++i) {
        if (S[i] < SVD_TOLERANCE) {
            num_zero_sv++;
            idx_v[j] = i;
            j++;
        }
    }
    for (int i = 0; i < n - m; ++i, ++j) {
        idx_v[j] = m + i;
    }
    rank_deficiency += num_zero_sv;

    if (rank_deficiency == 0) {
        delete[] S;
        delete[] U;
        delete[] V;
        delete[] idx_v;
        return 0;
    }

    nullspaceDim = rank_deficiency;
    nullSpace = new double[nullspaceDim * n];

    for (int i = 0; i < j; i++) {
        for (int l = 0; l < n; ++l) {
            nullSpace[i * n + l] = V[n * l + idx_v[i]];
        }
    }

    delete[] S;
    delete[] U;
    delete[] V;
    delete[] idx_v;
    return SVDHelper::SVD_SUCCESS;
}



