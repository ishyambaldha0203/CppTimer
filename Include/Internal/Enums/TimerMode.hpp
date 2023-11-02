/*************************************************************************************************
 * @file TimerMode .hpp
 *
 * @brief Enum to represent various modes supported by timer.
 *************************************************************************************************/

#ifndef _CPP_TIMER_INTERNAL_ENUMS_TIMERMODE_HPP
#define _CPP_TIMER_INTERNAL_ENUMS_TIMERMODE_HPP

#include "CommonConfig.hpp"

BEGIN_CPP_TIMER_NS
namespace Enums
{
    /**
     * @enum TimerMode
     *
     * @brief Represents the modes supported by the timer.
     */
    enum class TimerMode
    {
        None = -1,  ///< Timer is not in any mode.
        OneShot,    ///< Timer mode where it runs once and then stops.
        Periodic,   ///< Timer mode where it runs periodically at regular intervals.
        InvalidMode ///< Represents an invalid or unrecognized timer mode.
    };
} // namespace Enums
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERNAL_ENUMS_TIMERMODE_HPP