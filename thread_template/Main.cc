#include"Thread.hpp"
#include<unistd.h>
using namespace ThreadModlue;

// class ThreadData{
//     public:
//     pthread_t tid;
//     std::string name;
// };

// void Count(ThreadData td){
//     while(true){
//             std::cout<<"我是一个新线程"<<std::endl;
//             sleep(1);
//     }
// }



int main(){
    // ThreadData td;
    // Thread<ThreadData> t(Count,td);
    // t.Start();
    // t.Join();




    // Thread t([](){
    //     while(true){
    //         std::cout<<"我是一个新线程"<<std::endl;
    //         sleep(1);
    //     }
    // });
    // t.Start();
    // sleep(5);
    // t.Stop();
    // sleep(5);
    // t.Detach();
    // t.Join();

}