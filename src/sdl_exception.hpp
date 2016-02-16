#ifndef SDL_EXCEPTION_HPP
#define SDL_EXCEPTION_HPP

#include "exception.hpp"

class SdlException : public Exception
{
public:
    SdlException(const std::string &file, unsigned long line);
    SdlException(const SdlException &ex);
    virtual ~SdlException() {}
};

#endif
