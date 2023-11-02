/*************************************************************************************************
 * @file Program.cpp
 *
 * @brief Concrete implementation of @ref Program class.
 *
 * It handles Timer demo application's start-up rituals.
 *************************************************************************************************/

#include "Internal/Program.hpp"

#include <thread>

#include "Exceptions/XArgumentNull.hpp"

// #region Namespace Symbols

using namespace CPP_TIMER_NS::Interfaces;
using namespace CPP_TIMER_NS::Enums;
using namespace CPP_TIMER_NS::Entities;
using namespace CPP_TIMER_NS::Exceptions;

// #endregion

namespace
{
    namespace chrono = std::chrono;

    // #region Utility methods

    void TimerCallbackFunction()
    {
        std::cout << "Timer callback is executed!" << std::endl;
    }

    // #endregion
}

BEGIN_CPP_TIMER_NS
namespace Internal
{
    // #region Construction/Destruction

    Program::Program(std::shared_ptr<ITimer> timer)
        : _timer(timer)
    {
        if (nullptr == _timer)
        {
            throw XArgumentNull("Program::timer");
        }
    }

    Program::~Program() = default;

    // #endregion

    // #region Public Methods

    int32_t Program::Run()
    {
        std::cout << "**** Timer demo is in progress ****\n" << std::endl;

        try
        {
            // Note: Uncomment appropriate line according to the timer mode you want to test.

            //LoadOneShotTimerConfig();
            LoadPeriodicTimerConfig();

            // Start the timer.
            _timer->Start();
            _timer->Start();

            // Wait for the callback to execute a few times.
            std::this_thread::sleep_for(chrono::seconds(10));

            // Stop the timer.
            _timer->Stop();
        }
        catch (const std::exception &ex)
        {
            std::cout << "Exception caught: " << ex.what() << std::endl;

            _timer->Stop();

            return -1;
        }

        return 0;
    }

    // #endregion

    // #region Private Methods

    void Program::LoadOneShotTimerConfig()
    {
        // Create a callback function.
        TimerCallback callback = [] {
            std::cout << "Callback lambda is executed!" << std::endl;
        };

        // Load the configuration for one shot timer.
        TimerConfig config;

        config.Delay = chrono::seconds(1);
        config.Period = chrono::seconds(5);
        config.Mode = TimerMode::OneShot;
        config.Callback = callback;
        
        _timer->LoadConfiguration(config);
    }

    void Program::LoadPeriodicTimerConfig()
    {
        // Load the configuration for Periodic timer.
        TimerConfig config;

        config.Delay = chrono::seconds(1);
        config.Period = chrono::seconds(2);
        config.Mode = TimerMode::Periodic;
        config.Callback = TimerCallbackFunction;
        
        _timer->LoadConfiguration(config);
    }

    // #endregion

} // namespace Internal
END_CPP_TIMER_NS