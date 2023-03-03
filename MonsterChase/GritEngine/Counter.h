#pragma once
namespace GritEngine
{
	// A class to maintain the counters for smart and weak pointers
	class Counter
	{
	private:
		unsigned int ownercount = 0;
		unsigned int observercount = 0;
	public:
		Counter(const Counter&) = delete;
		Counter& operator=(const Counter&) = delete;
		Counter() { ownercount = 0; observercount = 0; }

		const unsigned int get_ownercount()
		{
			return ownercount;
		}
		const unsigned int get_observercount()
		{
			return observercount;
		}
		void operator++()
		{
			ownercount++;
		}
		void operator++(int)
		{
			ownercount++;
		}
		void operator--()
		{
			ownercount--;
		}
		void operator--(int)
		{
			ownercount--;
		}
		bool operator!=(int rhs)
		{
			if (ownercount != rhs)
			{
				return true;
			}
			else if (ownercount == rhs)
			{
				return false;
			}
		}
		template <class T>
		friend class Smart_Ptr;
		template <class T>
		friend class Weak_Ptr;
	};
}