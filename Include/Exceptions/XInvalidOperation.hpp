/*************************************************************************************************
 * @file XInvalidOperation.hpp
 *
 * @brief A file contains concrete definition of XInvalidOperation.
 *************************************************************************************************/

#ifndef _CPP_TIMER_EXCEPTIONS_XINVALIDOPERATION_HPP
#define _CPP_TIMER_EXCEPTIONS_XINVALIDOPERATION_HPP

#include "CommonConfig.hpp"

#include "Exceptions/XBaseException.hpp"

BEGIN_CPP_TIMER_NS
namespace Exceptions
{
    /**
     * @class XInvalidOperation
     *
     * @brief Exception for invalid operations.
     */
    class XInvalidOperation : public XBaseException
    {
    public:
        /**
         * @brief Use the XBaseException c'tor
         */
        using XBaseException::XBaseException;
    };
} // namespace Exceptions
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_EXCEPTIONS_XINVALIDOPERATION_HPP