/*************************************************************************************************
 * @file ObjectFactory.cpp
 *
 * @brief Concrete implementation of a common object factory.
 *
 * It manages creation and lifespan of all the higher level object of the Timer demo application.
 *************************************************************************************************/

#include "Internal/ObjectFactory.hpp"

#include "Internal/Program.hpp"
#include "Internal/Timer.hpp"


// #region Namespace Symbols

using namespace CPP_TIMER_NS::FactoryInterfaces;

// #endregion

BEGIN_CPP_TIMER_NS
namespace Internal
{
    // #region Construction/Destruction

    ObjectFactory::ObjectFactory() = default;

    ObjectFactory::~ObjectFactory() = default;

    // #endregion

    // #region Public Methods

    void ObjectFactory::Create(IProgramFactory::InterfaceSharedPointer &objectPtr)
    {
        ITimerFactory::InterfaceSharedPointer Timer;
        Create(Timer);

        objectPtr = std::make_shared<Program>(Timer);
    }

    void ObjectFactory::Create(ITimerFactory::InterfaceSharedPointer &objectPtr)
    {
        objectPtr = std::make_shared<Timer>();
    }

    // #endregion

    // #region Private Methods

    std::shared_ptr<ObjectFactory> ObjectFactory::Self()
    {
        return std::enable_shared_from_this<ObjectFactory>::shared_from_this();
    }

    // #endregion
} // namespace Internal
END_CPP_TIMER_NS
