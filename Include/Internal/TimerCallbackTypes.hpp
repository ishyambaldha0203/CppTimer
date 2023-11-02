/*************************************************************************************************
 * @file TimerCallbackTypes.hpp
 *
 * @brief Type declarations for a the timer callback function.
 *************************************************************************************************/

#ifndef _CPP_TIMER_INTERNAL_TIMERCALLBACKTYPES_HPP
#define _CPP_TIMER_INTERNAL_TIMERCALLBACKTYPES_HPP

#include "CommonConfig.hpp"

#include <functional>

BEGIN_CPP_TIMER_NS
namespace Internal
{
    using TimerCallback = std::function<void()>;
} // namespace Internal
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERNAL_TIMERCALLBACKTYPES_HPP