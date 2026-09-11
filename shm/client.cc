#include "Shm.hpp"
#include "Fifo.hpp"

int main()
{
    FileOper writerfile(PATH, FILENAME);
    writerfile.OpenForWrite();

    Shm shm(pathname, projid, USER);
    char *mem = (char *)shm.VirtualAddr();

    int index = 0;
    for (char c = 'A'; c <= 'Z'; c++, index += 2)
    {
        sleep(1);

        mem[index] = c;
        mem[index + 1] = c;
        sleep(1);
        mem[index + 2] = 0;
        writerfile.Wakeup();
    }
    writerfile.Close();
    return 0;
}