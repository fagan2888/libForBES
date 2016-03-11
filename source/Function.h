/* 
 * File:   Function.h
 * Author: Pantelis Sopasakis
 *
 * Created on July 9, 2015, 3:35 AM
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


#ifndef FUNCTION_H
#define	FUNCTION_H

#include "Matrix.h"
#include "ForBESUtils.h"
#include "FunctionOntologicalClass.h"
#include "FunctionOntologyRegistry.h"
#include "LinearOperator.h"

/**
 * \class Function
 * \brief A ForBES function.
 * \version version 0.2
 * \ingroup Functions
 * \date Created on July 9, 2015, 3:35 AM
 * \author Pantelis Sopasakis
 * 
 * 
 * This is a generic API for ForBES functions. Constructors for this class are
 * protected. Instances of this class can be created using any of its subclasses
 * a list of which can be found \ref Functions "here".
 * 
 * ForBES functions are all assumed to follow be \f$f:X \to \mathbb{R}\cup \{+\infty\}\f$,
 * where \f$X\f$ is a vector space, typically either \f$\mathbb{R}^n\f$ or
 * \f$\mathbb{R}^{n\times m}\f$.
 * 
 * In general, a %Function in libforbes is a tuple
 * \f$(f(\cdot),\nabla f, f^*(\cdot), \nabla f^*(\cdot), \mathrm{prox}_{\gamma f}(\cdot), f(\mathrm{prox}_{\gamma f}(\cdot)))\f$
 * where some of these components are available and implemented.
 * 
 * Certain functions furhter allow Hessian-vector products, i.e., computation of
 * terms of the form \f$\langle \nabla^2 f(x), z\rangle\f$ and/or with the gradient
 * of their conjugate \f$\langle \nabla^2 f(x), z\rangle\f$.
 * 
 * 
 * Input and output arguments to %Function calls are instances of Matrix.
 * 
 * For example, in Quadratic, which is a subclass of Function, the first four of these
 * components are available, namely \f$(f(\cdot),\nabla f, f^*(\cdot), \nabla f^*(\cdot))\f$.
 * 
 * In ElasticNet, only the triplet \f$(f(\cdot),\mathrm{prox}_{\gamma f}(\cdot), f(\mathrm{prox}_{\gamma f}(\cdot)))\f$
 * is available.
 * 
 * \sa \ref doc-functs "Introduction to the Function API"
 * \sa \ref Functions "List of functions"
 * \sa Matrix
 * \sa LinearOperator
 */
class Function {
public:

    /**
     * Destructor for this class.
     */
    virtual ~Function();

    /**
     * Ontological categorization of the function.
     * 
     * The category of a %Function defines which methods are implemented, that is,
     * it specifies whether one can compute 
     * 
     *  1. \f$f(x)\f$, 
     *  2. \f$f^*(x)\f$, 
     *  3. \f$\nabla f(x)\f$, 
     *  4. \f$\nabla f^*(x)\f$, 
     *  5. \f$\mathrm{prox}_{\gamma f}(v)\f$ and \f$f(\mathrm{prox}_{\gamma f}(v))\f$
     *  6. \f$\langle \nabla^2 f(x), z\rangle\f$ and 
     *  7. \f$\langle \nabla^2 f^*(x), z\rangle,\f$.
     * 
     * @return \link FunctionOntologicalClass Ontological class\endlink of the 
     * current \c%Function object.
     */
    virtual FunctionOntologicalClass category() = 0;

    /**
     * Returns the value of function f.
     * 
     * @param x The vector or matrix \f$x\f$ where \f$f(x)\f$ should be computed.
     * 
     * @param f The computed value of  \f$f(x)\f$
     * 
     * @return
     * status code which is equal to <code>STATUS_OK</code> if the computation
     * has succeeded without any problems, <code>STATUS_UNDEFINED_FUNCTION</code> if
     * this function is not defined by the derived class and <code>STATUS_NUMERICAL_PROBLEMS</code>
     * if some numerical problems prevented the computation of a reliable result. 
     * Custom implementations are allowed to return other non-zero error/warning
     * status codes.
     * 
     * \exception std::invalid_argument an <code>invalid_argument</code> exception
     * is thrown in case the input %Matrix is of incompatible dimensions.
     * 
     */
    virtual int call(Matrix& x, double& f);

    /**
     * Same as <code>call(const Matrix& x, double& f)</code>, but this function returns
     * also the gradient \f$\nabla f(x)\f$.
     * 
     * @param x The vector or matrix \f$x\f$ where \f$f(x)\f$ should be computed.
     * 
     * @param f The computed value of \f$f(x)\f$
     * 
     * @param grad The gradient of f at x, \f$\nabla f(x)\f$
     * 
     * @return 
     * status code which is equal to <code>STATUS_OK=0</code> if the computation
     * has succeeded without any problems, <code>STATUS_UNDEFINED_FUNCTION=2</code> if
     * this function is not defined by the derived class and <code>STATUS_NUMERICAL_PROBLEMS=1</code>
     * if some numerical problems prevented the computation of a reliable result. 
     * Custom implementations are allowed to return other non-zero error/warning
     * status codes.
     * 
     * \exception std::invalid_argument an <code>invalid_argument</code> exception
     * is thrown in case the input %Matrix is of incompatible dimensions.
     */
    virtual int call(Matrix& x, double& f, Matrix& grad); // returns also the gradient



    /**
     * Method \c hessianProduct computes the inner product 
     * \f$\langle \nabla^2 f(x), z\rangle,\f$
     * between a vector \f$z\f$ and the Hessian of \f$f\f$ computed at a point 
     * \f$x\f$.
     * 
     * If this method is not implemented in the derived class of Function, then 
     * an approximation is return based on the finite difference scheme
     * 
     * \f[
     *  \langle \nabla^2 f(x), z\rangle \simeq \frac{1}{\epsilon}[\nabla f(x+\epsilon z) - \nabla f(x)],
     * \f]
     * 
     * where $\epsilon=10^{-8}\f$ (a small tolerance).
     * 
     * If the gradient of \f$f\f$ is not available, or it fails to be computed,
     * then, an appropriate status code will be returned.
     * 
     * 
     * @param x point where the Hessian \f$\nabla^2 f(x)\f$ is computed
     * @param z vector with which the product is computed
     * @param Hz The result
     * 
     * @return
     * status code which is equal to <code>STATUS_OK=0</code> if the computation
     * has succeeded without any problems, <code>STATUS_UNDEFINED_FUNCTION=2</code> if
     * this function is not defined by the derived class and <code>STATUS_NUMERICAL_PROBLEMS=1</code>
     * if some numerical problems prevented the computation of a reliable result. 
     * Custom implementations are allowed to return other non-zero error/warning
     * status codes.
     * 
     */
    virtual int hessianProduct(Matrix& x, Matrix& z, Matrix& Hz);

    /**
     * Computes the proximal of this function at a point <code>x</code> with 
     * parameter <code>gamma</code>.
     * 
     * @param x The vector x where \f$\mathrm{prox}_{\gamma f}(x)\f$ should be computed.
     * @param gamma The parameter \f$\gamma\f$ of \f$\mathrm{prox}_{\gamma f}\f$
     * @param prox The result of this operation
     * @return 
     * status code which is equal to <code>STATUS_OK=0</code> if the computation
     * has succeeded without any problems, <code>STATUS_UNDEFINED_FUNCTION=2</code> if
     * this function is not defined by the derived class and <code>STATUS_NUMERICAL_PROBLEMS=1</code>
     * if some numerical problems prevented the computation of a reliable result. 
     * Custom implementations are allowed to return other non-zero error/warning
     * status codes.
     * 
     * \exception std::invalid_argument an <code>invalid_argument</code> exception
     * is thrown in case the function argument <code>x</code> and/or <code>prox</code>
     * are of incompatible dimensions.
     */
    virtual int callProx(Matrix& x, double gamma, Matrix& prox); // returns the value of prox_{gamma f}

    /**     
     * 
     * @param x The vector x where \f$\mathrm{prox}_{\gamma f}(x)\f$ should be computed.
     * @param gamma The parameter \f$\gamma\f$ of \f$\mathrm{prox}_{\gamma f}\f$
     * @param prox The result of this operation
     * @param f_at_prox Value of this function at the proximal operator \f$f(\mathrm{prox}_{\gamma f}(x))\f$
     * 
     * @return 
     * status code which is equal to <code>STATUS_OK=0</code> if the computation
     * has succeeded without any problems, <code>STATUS_UNDEFINED_FUNCTION=2</code> if
     * this function is not defined by the derived class and <code>STATUS_NUMERICAL_PROBLEMS=1</code>
     * if some numerical problems prevented the computation of a reliable result. 
     * Custom implementations are allowed to return other non-zero error/warning
     * status codes.
     * 
     * \exception std::invalid_argument an <code>invalid_argument</code> exception
     * is thrown in case the function argument <code>x</code> and/or <code>prox</code>
     * are of incompatible dimensions.
     */
    virtual int callProx(Matrix& x, double gamma, Matrix& prox, double& f_at_prox); // prox_{gamma f} and value-at-prox

    /**
     * Computes the conjugate of this function at a point <code>x</code>.
     * 
     * @param x The vector x where \f$f^*(x)\f$ should be computed.
     * @param f_star the computed value \f$f^*(x)\f$
     * @return 
     * status code which is equal to <code>STATUS_OK=0</code> if the computation
     * has succeeded without any problems, <code>STATUS_UNDEFINED_FUNCTION=2</code> if
     * this function is not defined by the derived class and <code>STATUS_NUMERICAL_PROBLEMS=1</code>
     * if some numerical problems prevented the computation of a reliable result. 
     * Custom implementations are allowed to return other non-zero error/warning
     * status codes.
     * 
     * \todo Implement a dummy callConj which used its counterpart 
     * \link Function::callConj(Matrix&, double&, Matrix&) callConj(3)\endlink
     * to compute f_star and discard grad.
     * 
     * \exception std::invalid_argument an <code>invalid_argument</code> exception
     * is thrown in case the input %Matrix <code>x</code> is of incompatible dimensions.
     */
    virtual int callConj(Matrix& x, double& f_star); // conjugate of f at x: f*(x)

    /**
     * Computes the conjugate of this function at a point <code>x</code> as well 
     * as the corresponding gradient.
     * 
     * @param x The vector x where \f$f^*(x)\f$ should be computed.
     * @param f_star the computed value \f$f^*(x)\f$
     * @param grad the gradient of the conjugate function \f$\nabla f^*(x)\f$
     * @return 
     * status code which is equal to <code>STATUS_OK=0</code> if the computation
     * has succeeded without any problems, <code>STATUS_UNDEFINED_FUNCTION=2</code> if
     * this function is not defined by the derived class and <code>STATUS_NUMERICAL_PROBLEMS=1</code>
     * if some numerical problems prevented the computation of a reliable result. 
     * Custom implementations are allowed to return other non-zero error/warning
     * status codes.
     * 
     * \exception std::invalid_argument an <code>invalid_argument</code> exception
     * is thrown in case the input %Matrix <code>x</code> or <code>grad</code> 
     * is of incompatible dimensions.
     */
    virtual int callConj(Matrix& x, double& f_star, Matrix& grad); // Nabla f*(x)


    /**
     * Method \c hessianProduct computes the inner product 
     * \f$\langle \nabla^2 f^*(x), z\rangle,\f$
     * between a vector \f$z\f$ and the Hessian of \f$f^*\f$ computed at a point 
     * \f$x\f$.
     * 
     * @param x point where the conjugate Hessian \f$\nabla^2 f^*(x)\f$ is computed
     * @param z vector with which the product is computed
     * @param Hz The result
     * 
     * @return
     * status code which is equal to <code>STATUS_OK=0</code> if the computation
     * has succeeded without any problems, <code>STATUS_UNDEFINED_FUNCTION=2</code> if
     * this function is not defined by the derived class and <code>STATUS_NUMERICAL_PROBLEMS=1</code>
     * if some numerical problems prevented the computation of a reliable result. 
     * Custom implementations are allowed to return other non-zero error/warning
     * status codes.
     * 
     */
    virtual int hessianProductConj(Matrix& x, Matrix& z, Matrix& Hz);

    /**
     * Assignment operator throws a logic_error whenever it is invoked. The assignment
     * operator is not supported and is not allowed on such objects.
     * 
     * @param right right-hand side
     * @return Does not return anything
     * @throws logic_error when it is invoked
     */
    Function& operator=(const Function& right);

private:



protected:
    /*
     * Constructors are protected.
     * It is not allowed to instantiate objects of this class directly.
     * Use its subclasses/implementations.
     */

    Function(); /**< Default constructor */



};

#endif	/* FUNCTION_H */

