#pragma once
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "Comm.hpp"
#define FILENAME "fifo"
#define PATH "."

class NamedFifo
{
public:
    NamedFifo(const std::string &path, const std::string &name)
        : _path(path), _name(name)
    {
        _fifoname = _path + "/" + _name;
        umask(0);
        int n = mkfifo(_fifoname.c_str(), 0666);
        if (n < 0)
        {
            std::cerr << "mkfifo error" << std::endl;
            ERR_EXIT("mkfifo");
        }
    }
    ~NamedFifo()
    {
        int n = unlink(_fifoname.c_str());
        if (n == 0)
        {
            // ERR_EXIT("unlink");
        }
        else
        {
            std::cout << "close fifo success" << std::endl;
        }
    }

private:
    std::string _path;
    std::string _name;
    std::string _fifoname;
};

class FileOper
{
private:
    std::string _path;
    std::string _name;
    std::string _fifoname;
    int _fd;

public:
    FileOper(const std::string &path, const std::string &name)
        : _path(path), _name(name), _fd(-1)
    {
        _fifoname = _path + "/" + _name;
    }
    ~FileOper()
    {
    }
    void OpenForRead()
    {
        _fd = open(_fifoname.c_str(), O_RDONLY);
        if (_fd < 0)
        {
            std::cerr << "open fifo error" << std::endl;
        }
        std::cout << "open fifo success" << std::endl;
    }
    void OpenForWrite()
    {
        _fd = open(_fifoname.c_str(), O_WRONLY);
        if (_fd < 0)
        {
            std::cerr << "open fifo error" << std::endl;
        }
        std::cout << "open fifo success" << std::endl;
    }
    void Wakeup()
    {
        char c = 'c';
        int num = write(_fd, &c, 1);
    }
    bool Wait()
    {
        char c;
        int num = read(_fd, &c, 1);
        if (num > 0)
        {
            return true;
        }
        return false;
    }
    void Close()
    {
        if (_fd > 0)
        {
            close(_fd);
        }
    }
};
