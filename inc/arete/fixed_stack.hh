#pragma once

#include "container.hh"
#include <vector>
#include <stdexcept>

namespace ar
{
	template <typename T> class fixed_stack : public container<T>
	{
		std::vector<T> m_buffer;
		size_t m_size;
		size_t m_sp;

	public:
		fixed_stack(size_t capacity);

		size_t capacity() const;
		size_t size() const;
		bool empty() const;
		bool full() const;

		bool push(const T &obj);
		bool pull(T &obj);
		bool peak(T &obj) const;
	};
}

// implementations
template <typename T> ar::fixed_stack<T>::fixed_stack(size_t capacity)
{
	if (capacity < 1)
		throw std::invalid_argument("Capacity is given as 0 (zero)");

	m_buffer.resize(capacity);
	m_size = capacity;
	m_sp = 0;
}

template <typename T> size_t ar::fixed_stack<T>::capacity() const
{
	return m_size;
}

template <typename T> size_t ar::fixed_stack<T>::size() const
{
	return m_sp;
}

template <typename T> bool ar::fixed_stack<T>::empty() const
{
	return (m_sp == 0);
}

template <typename T> bool ar::fixed_stack<T>::full() const
{
	return (m_sp == m_size);
}

template <typename T> bool ar::fixed_stack<T>::push(const T &obj)
{
	if (full())
		return false;

	m_buffer[m_sp++] = obj;
	return true;
}

template <typename T> bool ar::fixed_stack<T>::pull(T &obj)
{
	if (peak(obj))
	{
		m_buffer[--m_sp] = T();
		return true;
	}
	else
		return false;
}

template <typename T> bool ar::fixed_stack<T>::peak(T &obj) const
{
	if (empty())
		return false;

	obj = m_buffer[m_sp - 1];
	return true;
}
