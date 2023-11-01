/*************************************************************************************************
 * @file Program.hpp
 *
 * @brief Declarations for the concrete class @ref Program.
 *
 *************************************************************************************************/
#ifndef _CPP_TIMER_INTERNAL_PROGRAM_HPP
#define _CPP_TIMER_INTERNAL_PROGRAM_HPP

#include "CommonConfig.hpp"

#include "Interfaces/IProgram.hpp"
#include "Interfaces/ITimer.hpp"

BEGIN_CPP_TIMER_NS
namespace Internal
{
    /**
     * @class Program
     *
     * @brief Concrete implementation of application start-up class Program.
     */
    class Program : public Interfaces::IProgram
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new Program object.
         *
         * @param[in] timer A reference of the Timer object.
         *
         * @throw XArgumentNull If input params are null.
         */
        explicit Program(std::shared_ptr<Interfaces::ITimer> timer);

        /**
         * @brief Destroy the Program object.
         */
        virtual ~Program() override;

        // #endregion

        // #region IProgram Implementation

        virtual int32_t Run() override;

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(Program)

        // #region Private Members

        /**
         * @brief A timer object to access all the features of timer.
         */
        std::shared_ptr<Interfaces::ITimer> _timer;

        // #endregion
    };
} // namespace Internal
END_CPP_TIMER_NS

#endif // !_CPP_TIMER_INTERNAL_PROGRAM_HPP
