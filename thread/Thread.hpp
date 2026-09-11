#pragma once

#include<iostream>
#include<string>
#include<pthread.h>
#include<cstring>
#include<cstdio>
#include<functional>

namespace ThreadModlue{
        static u_int32_t number = 1;
    class Thread{
        using func_t =std::function<void()>;
        public:
        Thread(func_t func)
        :_tid(0)
        ,_isdetach(false)
        ,_isrunning(false)
        ,_func(func)
        {
            _name = "thread-"+std::to_string(number++);
        }
        ~Thread(){}
        
        void Detach(){
            if(_isdetach){
                return;
            }
            if(_isrunning){
                pthread_detach(_tid);
            }
            EnableDetach();
        }

        void EnableRunning(){
            _isrunning = true;
        }

        static void* Routine(void* args){
            Thread *self = static_cast<Thread*>(args);
            self->EnableRunning();
            if(self->_isdetach){
                self->Detach();
            }
             self->_func();

             return nullptr;
        }

        bool Start(){
            if(_isrunning){
                std::cerr<<"thread is already started "<<std::endl;
                return false;
            }
            int n= pthread_create(&_tid,nullptr,Routine,this);
            if(n!=0){
                std::cerr<<"create therad error: "<<strerror(n)<<std::endl;
                return false;
            }else{
                std::cout<<_name<<" start success"<<std::endl;
                return true;
            }
            
           
        }

        bool Stop(){
            if(_isrunning){
                int n=pthread_cancel(_tid);
                if(n!=0){
                std::cerr<<"create therad error: "<<strerror(n)<<std::endl;
                    return false;
                }else{
                    _isrunning = false;
                    std::cout<<_name<<" stop"<<std::endl;
                    return true;
                }
            }
            return false;
        }

        bool Join(){
            if(_isdetach){
                std::cerr<<"thread is detached can't join"<<std::endl;
                return false;
            }
            int n = pthread_join(_tid,&res);
            if(n!=0){
                std::cerr<<"create therad error: "<<strerror(n)<<std::endl;
                return false;
            }else{
                std::cout<<"join success"<<std::endl;
                return true;
            }
        }

        private:
        
        pthread_t _tid;
        std::string _name;
        bool _isdetach; 
        bool _isrunning;
        void* res;
        func_t _func;

        void EnableDetach(){
            _isdetach =true;
        }
    };
}