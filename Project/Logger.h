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
            eNone,
            eError,
            eWarning,
            eInfo,
            eDebug,
            eVerbose
        };

        static Logger * GetInstance (void) { return NULL; }

        template <class DERIVED_TYPE, typename... ARGS>
        void Log (const ELogLevel      v_eLogLevel,
                  const std::string && v_module,
                  const std::string && v_msg,
                  ARGS &&...           v_args)
        {
            static_cast <DERIVED_TYPE &>(* this).Log (v_eLogLevel, std::move (v_module), std::move (v_msg), v_args...);
        }
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
