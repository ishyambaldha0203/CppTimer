/*************************************************************************************************
 * @file IObjectFactories.hpp
 *
 * @brief Provides abstract factory for all the classes to create a concrete class instance.
 *************************************************************************************************/

#ifndef _CPP_TIMER_INTERFACES_FACTORIES_IOBJECTFACTORIES_HPP
#define _CPP_TIMER_INTERFACES_FACTORIES_IOBJECTFACTORIES_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Factories/IGenericObjectFactoryT.hpp"

#include "Interfaces/IProgram.hpp"
#include "Interfaces/ITimer.hpp"


BEGIN_CPP_TIMER_NS
namespace FactoryInterfaces
{
    // #region Functional Classes Factories

    /**
     * @interface IProgramFactory
     *
     * @brief Factory interface for concrete classes that implements @ref IProgram.
     */
    using IProgramFactory = IGenericObjectFactoryT<Interfaces::IProgram>;

    /**
     * @interface ITimerFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ITimer.
     */
    using ITimerFactory = IGenericObjectFactoryT<Interfaces::ITimer>;

    // #endregion

} // namespace FactoryInterfaces
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERFACES_FACTORIES_IOBJECTFACTORIES_HPP
