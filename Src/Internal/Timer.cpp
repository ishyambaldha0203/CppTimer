/*************************************************************************************************
 * @file Timer.cpp
 *
 * @brief Concrete implementation of @ref Timer class.
 *************************************************************************************************/

#include "Internal/Timer.hpp"

#include "Exceptions/XArgumentNull.hpp"

// #region Namespace Symbols

using namespace CPP_TIMER_NS::Interfaces;
using namespace CPP_TIMER_NS::Exceptions;

// #endregion

BEGIN_CPP_TIMER_NS
namespace Internal
{
    // #region Construction/Destruction

    Timer::Timer() = default;

    Timer::~Timer() = default;

    // #endregion

    // #region Public Methods

    void Timer::Start()
    {
        try
        {
            std::cout << "**** Timer is started ****\n" << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cout << "Exception caught: " << ex.what() << std::endl;
        }
    }

    // #endregion

} // namespace Internal
END_CPP_TIMER_NS