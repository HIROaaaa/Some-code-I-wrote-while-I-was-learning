#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

const int gdefaultid = -1;
const int gsize = 4096;
const std::string pathname = ".";
const int projid = 0x66;

#define ERR_EXIT(m)         \
    do                      \
    {                       \
        perror(m);          \
        exit(EXIT_FAILURE); \
    } while (0)

class Shm
{
public:
    Shm() : _shmid(gdefaultid), _size(gsize)
    {
    }
    // 创建的一定要是一个全新的共享内存
    void Create()
    {
        key_t k = ftok(pathname.c_str(), projid);
        if (k < 0)
        {
            ERR_EXIT("ftok");
        }
        printf("key: 0x%x", k);
        _shmid = shmget(k, _size, IPC_CREAT | IPC_EXCL);
        if(_shmid < 0)
        {
            ERR_EXIT("shmget");
        }
        printf("shmid: %d", _shmid);
    }
    ~Shm()
    {
    }

private:
    int _shmid;
    int _size;
};