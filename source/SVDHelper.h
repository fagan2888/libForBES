/* 
 * File:   SVDHelper.h
 * Author: chung
 *
 * Created on April 9, 2017, 12:23 PM
 */

#ifndef SVDHELPER_H
#define SVDHELPER_H

#include <iostream>
#include <lapacke.h>
#include <stdio.h>
#include <math.h>

#ifndef SVD_TOLERANCE
#define SVD_TOLERANCE 1e-6
#endif


#ifndef MIN
#define MIN(x,y) (x<y) ? x : y;
#endif

class SVDHelper {
public:

    const static int SVD_SUCCESS;

    /**
     * 
     * @param X An m-by-n matrix provided in column-major order
     * @param m number of rows of X
     * @param n number of columns of X
     * @param S singular values of X (vector)
     * @param U m-by-n matrix 
     * @param V n-by-n matrix
     * @return status code - returns 0 if the SVD algorithm has converged.
     */
    static int dsvd(
            const double* X,
            int m,
            int n,
            double * S,
            double * U,
            double * V);

    /**
     * Computes the nullspace of a given matrix. This function computes and return the
     * dimension of the nullspace, \c nullspaceDim. If \c nullspaceDim is \c 0, no 
     * memory is allocated for \c nullSpace and \c nullSpace is the pointer \c NULL.
     * Otherwise, this function allocates memory for \c nullSpace. 
     * 
     * @param A m-by-n matrix in column-major order
     * @param m number of rows of A
     * @param n number of columns of A
     * @param nullSpace A matrix whose columns spans the nullspace of A
     * @param nullspaceDim Dimension of the nullspace.
     * 
     * @return \c ::SVD_SUCCESS if the SVD algorithm has converged.
     */
    static int nullspace(
            double * A,
            int m,
            int n,
            double *& nullSpace,
            int & nullspaceDim);

private:

};

#endif /* SVDHELPER_H */

