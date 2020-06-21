#pragma once

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////// INCLUDES /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <string>

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// MACROS/DEFINITIONS ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#define SET_LOGGER_INST(INSTANCE) Logger::SetInstance (INSTANCE);

///////////////////////////////////////////////////////////////////////////////
/////////////////////////// CLASSES/STRUCTURES ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

class Logger
{
    private:
        static Logger * instance;

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

        static void     SetInstance (Logger * v_instance) { instance = v_instance; }
        static Logger * GetInstance (void)                { return instance; }

        template <class DERIVED_TYPE, typename... ARGS>
        void Log (const ELogLevel      v_eLogLevel,
                  const std::string && v_module,
                  const std::string && v_msg,
                  ARGS &&...           v_args)
        {
            static_cast <DERIVED_TYPE &>(* this).Log (v_eLogLevel, std::move (v_module), std ::move (v_msg), v_args...);
        }
};

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// END OF FILE ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
