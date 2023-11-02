/*************************************************************************************************
 * @file TimerTests.cpp
 *
 * @brief Contains unit tests for the @ref Timer class.
 *************************************************************************************************/

#include "CommonTestsConfig.hpp"

#include "Internal/Timer.hpp"

#include "Exceptions/XArgumentNull.hpp"
#include "Exceptions/XBaseException.hpp"
#include "Exceptions/XInvalidOperation.hpp"
#include "Exceptions/XInvalidTimerConfig.hpp"

// #region Namespace Symbols

using namespace CPP_TIMER_NS::Interfaces;
using namespace CPP_TIMER_NS::Internal;
using namespace CPP_TIMER_NS::Enums;
using namespace CPP_TIMER_NS::Entities;
using namespace CPP_TIMER_NS::Exceptions;

// #endregion

namespace
{
    namespace chrono = std::chrono;

    // #region Unit Tests

    class TimerTestFixture : public ::testing::Test
    {
    protected:
        std::unique_ptr<ITimer> timer;

        void SetUp() override
        {
            timer = std::make_unique<Timer>();
        }
    };

    TEST_F(TimerTestFixture, StartAndStopSuccessful)
    {
        // Create a callback function
        TimerCallback callback = [] () { std::cout << ""; };

        // Load the configuration
        TimerConfig config;
        config.Delay = chrono::milliseconds(100);
        config.Period = chrono::milliseconds(200);
        config.Mode = TimerMode::Periodic;
        config.Callback = callback;

        timer->LoadConfiguration(config);

        // Start the timer
        EXPECT_NO_THROW(timer->Start());

        // Stop the timer
        EXPECT_NO_THROW(timer->Stop());
    }

    TEST_F(TimerTestFixture, StopFromAnotherThreadSuccessful)
    {
        // Create a callback function
        TimerCallback callback = [] () { std::cout << ""; };

        // Load the configuration
        TimerConfig config;
        config.Delay = chrono::milliseconds(100);
        config.Period = chrono::milliseconds(1000);
        config.Mode = TimerMode::OneShot;
        config.Callback = callback;

        timer->LoadConfiguration(config);

        // Start the timer
        EXPECT_NO_THROW(timer->Start());
        
        // Try to stop the timer from a different thread
        std::thread t([this] () {
                                EXPECT_NO_THROW(timer->Stop());
                             });

        t.join();
    }

    TEST_F(TimerTestFixture, LoadInvalidConfigurationFailure)
    {
        // Create an invalid configuration.
        TimerConfig config;
        config.Delay = chrono::milliseconds(0);  // Invalid delay
        config.Period = chrono::milliseconds(100);
        config.Mode = TimerMode::Periodic;
        config.Callback = [] () { std::cout << "" << std::endl; };

        // Try to load the invalid configuration.
        EXPECT_THROW(timer->LoadConfiguration(config), XInvalidTimerConfig);
    }

    TEST_F(TimerTestFixture, StartWithInvalidConfigFailure)
    {
        // Start the timer
        EXPECT_THROW(timer->Start(), XInvalidTimerConfig);
    }

    TEST_F(TimerTestFixture, StartWhenRunningFailure)
    {
        // Create a callback function
        TimerCallback callback = [] () { std::cout << "" << std::endl;};

        // Load the configuration
        TimerConfig config;
        config.Delay = chrono::milliseconds(100);
        config.Period = chrono::milliseconds(100);
        config.Mode = TimerMode::Periodic;
        config.Callback = callback;

        timer->LoadConfiguration(config);

        // Start the timer
        timer->Start();
        
        // Try to start the timer again from a different thread
        std::thread t([this] () {
                                EXPECT_THROW(timer->Start(), XInvalidOperation);
                             });

        t.join();

        EXPECT_NO_THROW(timer->Stop());
    }

    TEST_F(TimerTestFixture, StopWhenNotRunningFailure)
    {
        // Try to stop the timer before it's started.
        ASSERT_THROW(timer->Stop(), XInvalidOperation);
    }

    // #endregion
} // Anonymous namespace