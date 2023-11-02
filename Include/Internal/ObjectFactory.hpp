/*************************************************************************************************
 * @file ObjectFactory.hpp
 *
 * @brief Declarations for the concrete class @ref ObjectFactory.
 *************************************************************************************************/

#ifndef _CPP_TIMER_INTERNAL_OBJECTFACTORY_HPP
#define _CPP_TIMER_INTERNAL_OBJECTFACTORY_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Factories/IObjectFactories.hpp"

BEGIN_CPP_TIMER_NS
namespace Internal
{
    /**
     * @class ObjectFactory
     *
     * @brief Concrete implementation of main object factory.
     */
    class ObjectFactory : public FactoryInterfaces::IProgramFactory,
                          public FactoryInterfaces::ITimerFactory,
                          public std::enable_shared_from_this<ObjectFactory>
    {
        // #region Type Aliases

        using ProgramFactoryInterfacePtr = FactoryInterfaces::IProgramFactory::InterfaceSharedPointer;
        using TimerFactoryInterfacePtr = FactoryInterfaces::ITimerFactory::InterfaceSharedPointer;

        // #endregion

    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new Factory object
         */
        ObjectFactory();

        /**
         * @brief Destroy the Object Factory object
         */
        virtual ~ObjectFactory() override;

        // #endregion

        // #region Implementation of Factories

        virtual void Create(ProgramFactoryInterfacePtr &objectPtr) override;
        virtual void Create(TimerFactoryInterfacePtr &objectPtr) override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(ObjectFactory)

        // #region Private Members

        /**
         * @brief This is to inject the common factory through constructor of all the other required classes.
         *
         * @return The shared pointer of ObjectFactory itself.
         */
        std::shared_ptr<ObjectFactory> Self();

        // #endregion
    };
} // namespace Internal
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERNAL_OBJECTFACTORY_HPP
