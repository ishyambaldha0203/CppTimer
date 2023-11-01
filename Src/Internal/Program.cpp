/*************************************************************************************************
 * @file Program.cpp
 *
 * @brief Concrete implementation of @ref Program class.
 *
 * It handles Timer demo application's start-up rituals.
 *************************************************************************************************/

#include "Internal/Program.hpp"

#include "Exceptions/XArgumentNull.hpp"

// #region Namespace Symbols

using namespace CPP_TIMER_NS::Interfaces;
using namespace CPP_TIMER_NS::Exceptions;

// #endregion

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
            _timer->Start();
        }
        catch (const std::exception &ex)
        {
            std::cout << "Exception caught: " << ex.what() << std::endl;

            return -1;
        }

        return 0;
    }

    // #endregion

} // namespace Internal
END_CPP_TIMER_NS