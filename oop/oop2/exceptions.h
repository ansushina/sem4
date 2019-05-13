#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>

class base_exception : public std::exception
{
public:
    base_exception(std::string filename, std::string classname, int line, const char *time, std::string info)
    {
        err_info = "filename: " + filename + "\nclass name: " + classname + "\nline: " + std::to_string(line)
                   + "\ntime: " + time + "\ninfo: " + info;
    }
    virtual std::string what(void) {return this->err_info;}
protected:
    std::string err_info;
};

class list_index_out_exception : public base_exception
{
public:
    list_index_out_exception(std::string filename, std::string classname, int line, const char *time, std::string info)
    : base_exception(filename, classname, line, time, info) {}
    std::string what(void) {return this->err_info;}
};

class memory_allocate_exception : public base_exception
{
public:
    memory_allocate_exception(std::string filename, std::string classname, int line, const char *time, std::string info)
    : base_exception(filename, classname, line, time, info) {}
    std::string what(void) {return this->err_info;}
};

class iterator_exception : public base_exception
{
public:
    iterator_exception(std::string filename, std::string classname, int line, const char *time, std::string info)
            : base_exception(filename, classname, line, time, info) {}
    std::string what(void) {return this->err_info;}
};

#endif // EXCEPTIONS_H
