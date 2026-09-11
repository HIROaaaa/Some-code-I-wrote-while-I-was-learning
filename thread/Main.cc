#include"Thread.hpp"
#include<unistd.h>
using namespace ThreadModlue;

int main(){
    Thread t([](){
        while(true){
            std::cout<<"我是一个新线程"<<std::endl;
            sleep(1);
        }
    });
    t.Start();
    sleep(5);
    t.Stop();
    sleep(5);
    t.Detach();
    t.Join();

}