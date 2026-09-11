#include "Shm.hpp"
#include "Fifo.hpp"
int main()
{
    NamedFifo fifo(PATH, FILENAME);

    FileOper readerfile(PATH, FILENAME);
    readerfile.OpenForRead();

    Shm shm(pathname, projid, CREATER);
    char *mem = (char *)shm.VirtualAddr();
    while (true)
    {
        if (readerfile.Wait())
        {
            printf("%s\n", mem);
        }
        else
        {
            break;
        }
    }
    readerfile.Close();

    return 0;
}