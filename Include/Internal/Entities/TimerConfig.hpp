/*************************************************************************************************
 * @file TimerConfig.hpp
 *
 * @brief Data entity to store all the timer related configurations.
 * 
 * It's a Pure POCO/POJO data entity to hold timer configuration.
 *************************************************************************************************/

#ifndef _CPP_TIMER_INTERNAL_ENTITIES_TIMERCONFIG_HPP
#define _CPP_TIMER_INTERNAL_ENTITIES_TIMERCONFIG_HPP

#include "CommonConfig.hpp"

#include <chrono>

#include "Internal/TimerCallbackTypes.hpp"
#include "Internal/Enums/TimerMode.hpp"

BEGIN_CPP_TIMER_NS
namespace Entities
{
    /**
     * @struct TimerConfig
     * 
     * @brief Plain data entity to store all the timer related configurations.
     */
    struct TimerConfig
    {
        std::chrono::milliseconds Delay;  ///< Delay before timer starts.
        std::chrono::milliseconds Period; ///< Recurrent time period to load timer again.
        Enums::TimerMode Mode;                  ///< Mode to run timer recurrently or one shot.
        Internal::TimerCallback Callback;           ///< Action to do on timer expiration in form of callback function.
    };
} // namespace Entities
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERNAL_ENTITIES_TIMERCONFIG_HPP