/* 
 * File:   ForBESUtils.h
 * Author: Pantelis Sopasakis
 *
 * Created on July 24, 2015, 5:17 PM
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

#ifndef FORBESUTILS_H
#define	FORBESUTILS_H

#define _FORBES_OK_MIN 0
#define _FORBES_OK_MAX 100
#define _FORBES_WARNING_MIN 200
#define _FORBES_WARNING_MAX 400
#define _FORBES_ERROR_MIN 500
#define _FORBES_ERROR_MAX 1000

#include <stdexcept>

/**
 * \brief ForBES utilities such as status codes.
 */
class ForBESUtils {
public:

    /**
     * Method has succeeded.
     */
    const static int STATUS_OK;

    /**
     * The method has succeeded, but there was necessary to allocate some memory
     * using new[].
     */
    const static int STATUS_HAD_TO_REALLOC;
    
    /**
     * Result was cached, so it was not re-computed.
     */
    const static int STATUS_CACHED_ALREADY;

    /**
     * Method is undefined.
     */
    const static int STATUS_UNDEFINED_FUNCTION;

    /**
     * The result is unreliable, or could not be computed because
     * of numerical errors.
     */
    const static int STATUS_NUMERICAL_PROBLEMS;
    /**
     * The maximum number of iterations was reached. 
     * Solution may be unreliable.
     */
    const static int STATUS_MAX_ITERATIONS_REACHED;
    /**
     * No direction has been cached yet. Use FBCache::set_direction first.
     */
    const static int STATUS_CACHE_NO_DIRECTION;
    /**
     * No quadratic function \c f1 is provided
     */
    const static int STATUS_CACHE_NO_QUADRATIC;

    /**
     * Checks whether a status code is merely informative and the call has 
     * succeeded
     * @param status status code
     * @return \c true iff status code is OK
     */
    static bool is_status_ok(int status);
    /**
     * Returns true if the status code corresponds to a warning
     * @param status status code
     * @return \c true iff status code is a warning
     */
    static bool is_status_warning(int status);
    /**
     * Checks whether a status code corresponds to an error
     * @param status status code
     * @return  \c true iff status code is an error
     */
    static bool is_status_error(int status);
    /**
     * Fails by throwing a \c logic_error exception if the status code corresponds 
     * to an error
     * 
     * @param status status code
     */
    static void fail_on_error(int status);



private:

    ForBESUtils();
    virtual ~ForBESUtils();

};

#endif	/* FORBESUTILS_H */

