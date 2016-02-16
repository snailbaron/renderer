#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <string>

class Exception
{
public:
    Exception(const std::string &file, unsigned long line, const std::string &msg) : m_file(file), m_line(line), m_msg(msg) {}
    Exception(const Exception &ex) : m_file(ex.m_file), m_line(ex.m_line), m_msg(ex.m_msg) {}
    virtual ~Exception() {}

    const std::string & Msg() const { return m_msg; }

protected:
    std::string m_file;
    unsigned long m_line;
    std::string m_msg;
};

#define THROW(EXCEPTION, ...) throw EXCEPTION(__FILE__, __LINE__, __VA_ARGS__)

#endif
