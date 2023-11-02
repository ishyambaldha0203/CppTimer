/*************************************************************************************************
 * @file Timer.cpp
 *
 * @brief Concrete implementation of @ref Timer class.
 *************************************************************************************************/

#include "Internal/Timer.hpp"

#include <functional>
#include <thread>
#include <unordered_map>

#include "Exceptions/XArgumentNull.hpp"
#include "Exceptions/XBaseException.hpp"
#include "Exceptions/XInvalidOperation.hpp"
#include "Exceptions/XInvalidTimerConfig.hpp"

// #region Namespace Symbols

using namespace CPP_TIMER_NS::Interfaces;
using namespace CPP_TIMER_NS::Enums;
using namespace CPP_TIMER_NS::Entities;
using namespace CPP_TIMER_NS::Exceptions;

// #endregion

namespace
{
    bool IsValidTimerConfig(const TimerConfig& config)
    {
        return config.Delay.count() > 0
                && config.Period.count() > 0
                && config.Mode != TimerMode::None
                && config.Callback != nullptr;
    }
}

BEGIN_CPP_TIMER_NS
namespace Internal
{
    // #region Construction/Destruction

    Timer::Timer()
    {
        _isRunning = false;
    }

    Timer::~Timer() = default;

    // #endregion

    // #region Public Methods

    void Timer::LoadConfiguration(const TimerConfig& config)
    {
        if(!IsValidTimerConfig(config))
        {
            throw XInvalidTimerConfig("Invalid timer configurations.");
        }

        this->_config = config;
    }

    void Timer::Start()
    {
        if (_isRunning)
        {
            throw XInvalidOperation("Timer is already running.");
        }

        if(!IsValidTimerConfig(_config))
        {
            throw XInvalidTimerConfig("Timer can not start due to invalid configurations.");
        }

        _isRunning = true;

        std::this_thread::sleep_for(_config.Delay);

        switch (_config.Mode)
        {
            case TimerMode::OneShot:
                {
                    std::cout << "Timer is started in oneshot mode!" << std::endl;

                    ExecuteInOneShotMode();
                }
                break;
            case TimerMode::Periodic:
                {
                    std::cout << "Timer is started in periodic mode!" << std::endl;

                    ExecuteInPeriodicMode();
                }
                break;
            default:
                throw XBaseException("Invalid timer mode.");
        }
    }

    void Timer::Stop()
    {
        if (!_isRunning)
        {
            throw XInvalidOperation("Timer is not running.");
        }

        _isRunning = false;

        if (_future.valid())
        {
            // The `wait_for` method blocks the calling thread until the shared state is ready or
            // for zero seconds, returning immediately in this case.
            std::future_status status = _future.wait_for(std::chrono::seconds(0));
            if (status == std::future_status::ready)
            {
                _future.get();
            }
        }
    }

    // #endregion

    // #region Private Methods

    void Timer::ExecuteInOneShotMode()
    {
        _future = std::async(std::launch::async,
                            [this] ()
                            {
                                std::this_thread::sleep_for(_config.Period);
                                _config.Callback();
                            });
    }

    void Timer::ExecuteInPeriodicMode()
    {
        _future = std::async(std::launch::async,
                            [this] ()
                            {
                                while (_isRunning)
                                {
                                    std::this_thread::sleep_for(_config.Period);
                                    _config.Callback();
                                }
                            });
    }

    // #endregion

} // namespace Internal
END_CPP_TIMER_NS