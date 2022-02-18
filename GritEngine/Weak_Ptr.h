#pragma once
#include "Log.h"
namespace GritEngine
{
	template <class T>
	class Smart_Ptr;
	template <class T>
	class Weak_Ptr
	{
	private:
	private:
		T* ptr;
		Counter* refcount;
	public:
		Weak_Ptr() { ptr = nullptr; refcount = nullptr; };
		template <class T>
		Weak_Ptr(Smart_Ptr<T>& other)
		{
			if (other.ptr)
			{
				ptr = other.ptr;
				refcount = other.refcount;
				(refcount->observercount)++;
			}
			else if (!(other.ptr))
			{
				ptr = nullptr;
				refcount = nullptr;
			}
			Log::print("Weak Pointer Assigned %d\n", refcount->get_observercount());
		}
		Weak_Ptr(const Weak_Ptr& other)
		{
			if (other.ptr)
			{
				ptr = other.ptr;
				refcount = other.refcount;
				(refcount->observercount)++;
			}
			else if (!(other.ptr))
			{
				ptr = nullptr;
				refcount = nullptr;
			}
			Log::print("Weak Pointer Assigned %d\n", refcount->get_observercount());
		}
		template <class U>
		Weak_Ptr(Weak_Ptr<U>& other)
		{
			if (other.ptr)
			{
				ptr = other.ptr;
				refcount = other.refcount;
				(refcount->observercount)++;
			}
			else if (!(other.ptr))
			{
				ptr = nullptr;
				refcount = nullptr;
			}
			Log::print("Weak Pointer Assigned %d\n", refcount->get_observercount());
		}
		~Weak_Ptr()
		{
			(refcount->observercount)--;
			Log::print("Weak Pointer Destroyed %d\n",  refcount->get_observercount());
			if (refcount->get_observercount() == 0)
			{
				if (refcount->get_ownercount() == 0)
				{
					delete refcount;
					Log::print("Reference count destroyed\n", 0);
				}
			}
		}
		template <class T>
		Weak_Ptr& operator=(Smart_Ptr<T>& other)
		{
			if (refcount && refcount->get_observercount() != 0)
			{
				(refcount->observercount)--;
			}
			ptr = other.ptr;
			refcount = (other.refcount);
			(refcount->observercount)++;
			return *this;
			Log::print("Weak Pointer Assigned %d\n", refcount->get_observercount());
		}
		//void operator=(Weak_Ptr& other)
		//{
		//	if (ptr == nullptr)
		//	{
		//		ptr = other.ptr;
		//		refcount = (other.refcount);
		//		(refcount->observercount)++;
		//	}
		//	else
		//	{
		//		(refcount->observercount)--;
		//		ptr = other.ptr;
		//		refcount = (other.refcount);
		//		(refcount->observercount)++;
		//	}
		//	Log::print("Weak Pointer Assigned %d\n", refcount->get_observercount());
		//}
		Weak_Ptr& operator=(const Weak_Ptr& other)
		{
			if (ptr == nullptr)
			{
				ptr = other.ptr;
				refcount = (other.refcount);
				(refcount->observercount)++;
			}
			else
			{
				(refcount->observercount)--;
				ptr = std::move(other.ptr);
				refcount = std::move(other.refcount);
				(refcount->observercount)++;
			}
			return *this;
			Log::print("Weak Pointer Assigned %d\n", refcount->get_observercount());
		}
		template<class U>
		Weak_Ptr& operator=(const Weak_Ptr<U>& other)
		{
			if (ptr == nullptr)
			{
				ptr = other.ptr;
				refcount = other.refcount;
				(refcount->observercount)++;
			}
			else
			{
				(refcount->observercount)--;
				ptr = other.ptr;
				refcount = other.refcount;
				(refcount->observercount)++;
			}
			return *this;
			Log::print("Weak Pointer Assigned %d\n", refcount->get_observercount());
		}
		Weak_Ptr& operator=(Weak_Ptr&& other)
		{
			if (ptr == nullptr)
			{
				ptr = other.ptr;
				refcount = (other.refcount);
				(refcount->observercount)++;
			}
			else
			{
				(refcount->observercount)--;
				ptr = std::move(other.ptr);
				refcount = std::move(other.refcount);
				(refcount->observercount)++;
			}
			return *this;
			Log::print("Weak Pointer Assigned %d\n", refcount->get_observercount());
		}
		template<class U>
		Weak_Ptr& operator=(Weak_Ptr<U>&& other)
		{
			if (ptr == nullptr)
			{
				ptr = other.ptr;
				refcount = other.refcount;
				(refcount->observercount)++;
			}
			else
			{
				(refcount->observercount)--;
				ptr = other.ptr;
				refcount = other.refcount;
				(refcount->observercount)++;
			}
			return *this;
			Log::print("Weak Pointer Assigned %d\n", refcount->get_observercount());
		}
		template <class T>
		friend class Smart_Ptr;
	};
}