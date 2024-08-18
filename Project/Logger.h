#pragma once

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <memory>

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// CLASSES/STRUCTURES ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class Logger
{
    public:
        enum class ELogLevel : uint8_t
        {
            None,
            Error,
            Warning,
            Info,
            Debug,
            Verbose
        };

        static Logger * GetInst (void) { return NULL; }

        template <class DERIVED_TYPE, typename... ARGS>
        constexpr void Log (const ELogLevel vLogLevel,
                            std::string     vModule,
                            std::string     vMsg,
                            ARGS &&...      vArgs)
        {
            static_cast <DERIVED_TYPE &>(* this).Log (vLogLevel, vModule, vMsg, vArgs...);
        }
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
