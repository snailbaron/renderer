#include <SDL2/SDL.h>
#include "sdl_exception.hpp"

SdlException::SdlException(const std::string &file, unsigned long line) :
    Exception(file, line, "")
{
    m_msg = SDL_GetError();
}

SdlException::SdlException(const SdlException &ex) :
    Exception(ex)
{
}
