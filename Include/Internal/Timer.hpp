/*************************************************************************************************
 * @file Timer.hpp
 *
 * @brief Declarations for the concrete class @ref Timer.
 * *************************************************************************************************/
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
        // #region Type Aliases

        using TimerConfig = Entities::TimerConfig;

        // #endregion

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

        void LoadConfiguration(const TimerConfig& config) override;

        void Start() override;

        void Stop() override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(Timer)

        // #region Private Members

        /**
         * @brief All the configuration required for timer to execute.
         */
        TimerConfig _config;

        /**
         * @brief Keeps track of timer status.
         */
        std::atomic<bool> _isRunning;

        /**
         * @brief To control the timer thread.
         */
        std::future<void> _future;

        // #endregion

        // #region Private Methods

        /**
         * @brief Execute timer in one shot mode.
         */
        void ExecuteInOneShotMode();

        /**
         * @brief Execute timer in periodic mode.
         */
        void ExecuteInPeriodicMode();

        // #endregion
    };
} // namespace Internal
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERNAL_Timer_HPP
