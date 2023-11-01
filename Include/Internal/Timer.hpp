/*************************************************************************************************
 * @file Timer.hpp
 *
 * @brief Declarations for the concrete class @ref Timer.
 *
 *************************************************************************************************/
#ifndef _CPP_TIMER_INTERNAL_Timer_HPP
#define _CPP_TIMER_INTERNAL_Timer_HPP

#include "CommonConfig.hpp"

#include <future>
#include <atomic>

#include "Interfaces/ITimer.hpp"

BEGIN_CPP_TIMER_NS
namespace Internal
{
    /**
     * @class Timer
     *
     * @brief Concrete implementation of the Timer.
     */
    class Timer : public Interfaces::ITimer
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief  Construct a new timer object.
         */
        Timer();

        /**
         * @brief Destroy the timer object.
         */
        virtual ~Timer() override;

        // #endregion

        // #region ITimer Implementation

        virtual void Start() override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(Timer)

        // #region Private Members

        /**
         * @brief Keeps track of timer status.
         */
        std::atomic<bool> _isRunning;

        /**
         * @brief To control the timer thread.
         */
        std::future<void> _future;

        // #endregion
    };
} // namespace Internal
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERNAL_Timer_HPP
