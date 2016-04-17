/* 
 * File:   OpDCT3.h
 * Author: Pantelis Sopasakis
 *
 * Created on September 15, 2015, 6:40 PM
 * 
 * ForBES is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *  
 * ForBES is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with ForBES. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OPDCT3_H
#define	OPDCT3_H

#include "LinearOperator.h"

/**
 * \class OpDCT3
 * \brief The Discrete Cosine Transform Type III (DCT-III or IDCT)
 * \version 0.0-tentative
 * \author Pantelis Sopasakis
 * \date Created on September 15, 2015, 6:40 PM
 * 
 * \ingroup LinOp
 * 
 * The <a href="https://en.wikipedia.org/wiki/Discrete_cosine_transform#DCT-III">DCT-III transform</a> 
 * is a linear square transformation \f$T:\mathbb{R}^n \to \mathbb{R}^n\f$
 * given by
 * 
 * \f[
 * (T(x))_k = \frac{x_0}{2} + \sum_{i=1}^{n} x_i \cos \left[ \frac{\pi}{n}\left(i+\frac{1}{2}\right)k \right]
 * \f]
 * 
 * for \f$k=0,\ldots, n-1\f$.
 * 
 * Because it is the inverse of DCT-II (up to a scale factor), this form is sometimes 
 * simply referred to as "the inverse DCT" ("IDCT").
 *
 */
class OpDCT3 : public LinearOperator {
public:
    
    using LinearOperator::call;
    using LinearOperator::callAdjoint;
    
    /**
     * Constructs an instance of OpDCT3 with indeterminate dimension. 
     * It is advisable that you use #OpDCT3(2) instead.
     */
    OpDCT3();

    /**
     * Construct a new instance of OpDCT3 with a given input/output dimension
     * @param m_dimension
     */
    explicit OpDCT3(size_t m_dimension);

    /**
     * Default destructor
     */
    virtual ~OpDCT3();
    
    virtual int call(Matrix& y, double alpha, Matrix& x, double gamma);

    virtual int callAdjoint(Matrix& y, double alpha, Matrix& x, double gamma);

    virtual std::pair<size_t, size_t> dimensionIn();

    virtual std::pair<size_t, size_t> dimensionOut();

    virtual bool isSelfAdjoint();

private:

    std::pair<size_t, size_t> m_dimension;

};

#endif	/* OPDCT3_H */

