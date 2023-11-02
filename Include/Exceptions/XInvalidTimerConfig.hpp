/*************************************************************************************************
 * @file XInvalidTimerConfig.hpp
 *
 * @brief A file contains concrete definition of XInvalidTimerConfig.
 *************************************************************************************************/

#ifndef _CPP_TIMER_EXCEPTIONS_XINVALIDTIMERCONFIG_HPP
#define _CPP_TIMER_EXCEPTIONS_XINVALIDTIMERCONFIG_HPP

#include "CommonConfig.hpp"

#include "Exceptions/XBaseException.hpp"

BEGIN_CPP_TIMER_NS
namespace Exceptions
{
    /**
     * @class XInvalidTimerConfig
     *
     * @brief Exception for invalid timer configuration.
     */
    class XInvalidTimerConfig : public XBaseException
    {
    public:
        /**
         * @brief Use the XBaseException c'tor
         */
        using XBaseException::XBaseException;
    };
} // namespace Exceptions
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_EXCEPTIONS_XINVALIDTIMERCONFIG_HPP