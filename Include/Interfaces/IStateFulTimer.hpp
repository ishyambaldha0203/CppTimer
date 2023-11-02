/*************************************************************************************************
 * @file IStateFulTimer.hpp
 *
 * @brief Interface to define member contracts for stateful timer class.
 *************************************************************************************************/

#ifndef _CPP_TIMER_INTERFACES_ISTATEFULTIMER_HPP
#define _CPP_TIMER_INTERFACES_ISTATEFULTIMER_HPP

#include "CommonConfig.hpp"

#include "Internal/Entities/TimerConfig.hpp"

BEGIN_CPP_TIMER_NS
namespace Interfaces
{
    /**
     * @interface IStateFulTimer
     *
     * @brief Interface that represents a stateful timer object.
     */
    interface IStateFulTimer
    {
        DECLARE_INTERFACE_DEFAULTS(IStateFulTimer)

        /**
         * @brief Sets the configuration required to execute the timer.
         *
         * @param config The configuration settings for the timer.
         */
        virtual void LoadConfiguration(const Entities::TimerConfig& config) = 0;

        /**
         * @brief Starts the timer.
         *
         * @throw XInvalidOperation If this method is called on a timer that is already paused or running.
         */
        virtual void Start() = 0;

        /**
         * @brief Pauses the recurrent execution of the timer. 
         * 
         * @throw XInvalidOperation If this method is called on a timer that is already stopped.
         *
         * @note If the timer is running and is not stopped or paused, this method will just prevent
         *       the start of the next interval until resumed.
         */
        virtual void Pause() = 0;
        
        /**
         * @brief Resumes a paused timer. 
         *
         * If the timer hasn't been paused with Pause(), this function doesn't do anything. 
         * 
         * @throw XInvalidOperation If this method is called on a timer that is already stopped.
         */
        virtual void Resume() = 0;

        /**
         * @brief Stops a paused or running timer.
         */
        virtual void Stop() = 0;

    };
} // namespace Interfaces
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERFACES_ISTATEFULTIMER_HPP
