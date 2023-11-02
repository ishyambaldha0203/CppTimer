/*************************************************************************************************
 * @file XBaseException.hpp
 *
 * @brief A file contains concrete definition of XBaseException.
 *
 * @ref XBaseException is a runtime base exception for all the exceptions being implemented for the application.
 *
 *************************************************************************************************/
#ifndef _CPP_TIMER_EXCEPTIONS_XBASEEXCEPTION_HPP
#define _CPP_TIMER_EXCEPTIONS_XBASEEXCEPTION_HPP

#include "CommonConfig.hpp"

#include <stdexcept>

BEGIN_CPP_TIMER_NS
namespace Exceptions
{
    /**
     * @class XBaseException
     *
     * @brief A general runtime base exception for Timer demo application.
     */
    class XBaseException : public std::runtime_error
    {
    public:
        /**
         * @brief Use the std::runtime_error c'tor
         */
        using runtime_error::runtime_error;
    };
} // namespace Exceptions
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_EXCEPTIONS_XBASEEXCEPTION_HPP