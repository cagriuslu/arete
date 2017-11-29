#pragma once

#include <cstdlib>

namespace ar
{
	template <typename T> class container
	{
	public:
		virtual ~container() { }

		virtual size_t capacity() const = 0;
		virtual size_t size() const = 0;
		virtual bool empty() const = 0;
		virtual bool full() const = 0;

		virtual bool push(const T &obj) = 0;
		virtual bool pull(T &obj) = 0;
		virtual bool peak(T &obj) const = 0;
	};
}
