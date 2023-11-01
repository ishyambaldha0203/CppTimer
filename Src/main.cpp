/*************************************************************************************************
 * @file main.cpp
 *
 * @brief Starting point of Timer demo application.
 *************************************************************************************************/

#include "Internal/ObjectFactory.hpp"

// #region Namespace Symbols

using namespace CPP_TIMER_NS::Internal;
using namespace CPP_TIMER_NS::FactoryInterfaces;

// #endregion

/**
 * @brief Entry-point function for the Timer demo applications.
 *
 * @return 0 if the service application exited normally. Otherwise, a non-zero error code will be returned.
 */
int main()
{
    // Creat the common object factory that own all the objects created for the application.
    std::shared_ptr<ObjectFactory> commonObjectFactory = std::make_shared<ObjectFactory>();

    // Create the program.
    IProgramFactory::InterfaceSharedPointer program;
    commonObjectFactory->Create(program);

    // It's blocking call.
    return program->Run();
}