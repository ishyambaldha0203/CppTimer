/*************************************************************************************************
 * @file ITimer.hpp
 *
 * @brief Interface to define member contracts for timer class.
 *************************************************************************************************/

#ifndef _CPP_TIMER_INTERFACES_ITIMER_HPP
#define _CPP_TIMER_INTERFACES_ITIMER_HPP

#include "CommonConfig.hpp"

#include "Internal/Entities/TimerConfig.hpp"

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
         * @brief Sets the configuration required to execute the timer.
         *
         * @param config The configuration settings for the timer.
         */
        virtual void LoadConfiguration(const Entities::TimerConfig& config) = 0;

        /**
         * @brief Starts the timer.
         *
         * @throw XInvalidOperation If this method is called on a timer that is already running.
         */
        virtual void Start() = 0;

        /**
         * @brief Stops the running timer.
         *
         * @throw XInvalidOperation If timer is already stopped.
         */
        virtual void Stop() = 0;

    };
} // namespace Interfaces
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERFACES_ITIMER_HPP
