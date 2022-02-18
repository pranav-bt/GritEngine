#pragma once
#include <iostream>
#include "Counter.h"
#include "interface.h"
#include <Windows.h>
#include "Weak_Ptr.h"
//#include <memory>
//std::shared_ptr<int> a;
namespace GritEngine
{
    template <class T >
	class Smart_Ptr
	{
    private:
        T* ptr; 
        Counter* refcount;
     public:
         Smart_Ptr() { ptr = nullptr; refcount = nullptr; };
         explicit Smart_Ptr(T* p) { ptr = p;  refcount = new Counter(); if (ptr) (refcount->ownercount)++; 
         registerGO(this);}
         template <class T>
         Smart_Ptr(Smart_Ptr<T>& other)
         {
             ptr = other.ptr; 
             refcount = (other.refcount); 
             (refcount->ownercount)++;
             Log::print("Smart Pointer Assigned %d\n",  refcount->get_ownercount());
         }
         template <class T>
         Smart_Ptr(Smart_Ptr<T>&& other)
         {
             ptr = other.ptr;
             refcount = (other.refcount);
             (refcount->ownercount)++;
             Log::print("Smart Pointer Assigned %d\n", refcount->get_ownercount());
         }
         template <class T>
         Smart_Ptr(Weak_Ptr<T>& other)
         {
             if (other.refcount->ownercount == 0)
             {
                 return;
             }
             ptr = other.ptr;
             refcount = (other.refcount);
             (refcount->ownercount)++;
             Log::print("Smart Pointer Assigned %d\n",  refcount->get_ownercount());
         }
         ~Smart_Ptr() 
         {
             (refcount->ownercount)--;
             Log::print("Smart Pointer Destroyed %d\n",  refcount->ownercount);
             if (refcount->get_ownercount() == 0)
             {
                 delete (ptr);
                 Log::print("Game Pointer destroyed\n", 0);
                 if (refcount->get_observercount() == 0)
                 {
                     delete refcount;
                     Log::print("Reference count destroyed\n", 0);
                 }
             }
         }

        T& operator*() { return *ptr; }

        T* operator->() { return ptr; }
        template <class T2>
        Smart_Ptr<T>& operator=(const Smart_Ptr<T2>& other)
        {
            if (refcount && refcount->get_ownercount() != 0)
            {
                (refcount->ownercount)--;
            }
            ptr = other.ptr;
            refcount = (other.refcount);
            (refcount->ownercount)++;
            Log::print("Smart Pointer Assigned %d\n", refcount->get_ownercount());
        }
        template <class T2>
        Smart_Ptr<T2>& operator=(const Smart_Ptr<T2>&& other)
        {
            if (refcount && refcount->get_ownercount() != 0)
            {
                (refcount->ownercount)--;
            }
            ptr = other.ptr;
            refcount = (other.refcount);
            (refcount->ownercount)++;
            return *this;
            Log::print("Smart Pointer Assigned %d\n", refcount->get_ownercount());
        }
        template <class T>
        bool operator==(const Smart_Ptr<T> other) const
        {
            if (ptr == other.ptr)
            {
                return true;
            }
            else
                return false;
        }
        T* getptr()
        {
            return ptr;
        }
        template <class T>
        friend class Weak_Ptr;
	};
}