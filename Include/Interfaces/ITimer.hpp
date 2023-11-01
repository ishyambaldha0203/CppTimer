/*************************************************************************************************
 * @file ITimer.hpp
 *
 * @brief Interface to define member contracts for start-up class of application.
 *************************************************************************************************/

#ifndef _CPP_TIMER_INTERFACES_ITIMER_HPP
#define _CPP_TIMER_INTERFACES_ITIMER_HPP

#include "CommonConfig.hpp"

BEGIN_CPP_TIMER_NS
namespace Interfaces
{
    /**
     * @interface ITimer
     *
     * @brief Interface that represents a timer object.
     */
    interface ITimer
    {
        DECLARE_INTERFACE_DEFAULTS(ITimer)

        /**
         * @brief Start the timer.
         */
        virtual void Start() = 0;
    };
} // namespace Interfaces
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERFACES_ITIMER_HPP
