/* 
 * File:   OpReverseVector.h
 * Author: Pantelis Sopasakis
 *
 * Created on September 15, 2015, 12:57 PM
 */

#ifndef OPREVERSEVECTOR_H
#define	OPREVERSEVECTOR_H

#include "LinearOperator.h"
#include <algorithm>
#include <iterator>


/**
 * \class OpReverseVector
 * \brief A linear operator <code>T(x)</code> which reverses the order of elements in <code>x</code>
 * \version 0.0-tentative
 * \author Pantelis Sopasakis
 * \date Created on September 15, 2015, 12:57 PM
 * 
 * \ingroup LinOp
 */
class OpReverseVector : public LinearOperator {
public:
    OpReverseVector();

    OpReverseVector(size_t n);

    virtual ~OpReverseVector();


    virtual Matrix call(Matrix& x);

    virtual Matrix callAdjoint(Matrix& x);

    virtual size_t dimensionIn();

    virtual size_t dimensionOut();

    virtual bool isSelfAdjoint();


private:

    /**
     * Input and output dimension of this operator.
     */
    size_t m_vectorDim;
};

#endif	/* OPREVERSEVECTOR_H */
