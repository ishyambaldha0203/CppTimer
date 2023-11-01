/*************************************************************************************************
 * @file TimerModes.hpp
 *
 * @brief Enum to represent various modes supported by timer.
 *************************************************************************************************/

#ifndef _CPP_TIMER_INTERNAL_ENUMS_TIMERMODES_HPP
#define _CPP_TIMER_INTERNAL_ENUMS_TIMERMODES_HPP

#include "CommonConfig.hpp"

BEGIN_CPP_TIMER_NS
namespace Enums
{
    /**
     * @enum TimerMode
     *
     * @brief Represent the mode supported by the timer.
     */
    enum class TimerMode
    {
        None = -1,
        OneShot,
        Periodic,
        InvalidMode
    };
} // namespace Enums
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERNAL_ENUMS_TIMERMODES_HPP