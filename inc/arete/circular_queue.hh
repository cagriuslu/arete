#pragma once

#include "container.hh"
#include <vector>
#include <stdexcept>

namespace ar
{
	template <typename T> class circular_queue : public container<T>
	{
		std::vector<T> m_buffer;
		size_t m_size;
		size_t m_begin;
		size_t m_end;
		bool m_isWrapped;

	public:
		circular_queue(size_t capacity);

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
template <typename T> ar::circular_queue<T>::circular_queue(size_t capacity)
{
	if (capacity < 1)
		throw std::invalid_argument("Capacity is given as 0 (zero)");

	m_buffer.resize(capacity);
	m_size = capacity;
	m_begin = 0;
	m_end = 0;
	m_isWrapped = false;
}

template <typename T> size_t ar::circular_queue<T>::capacity() const
{
	return m_size;
}

template <typename T> size_t ar::circular_queue<T>::size() const
{
	if (m_isWrapped)
		return m_size;
	else if (m_begin <= m_end)
		return m_end - m_begin;
	else // (m_end < m_begin)
		return m_end + m_size - m_begin;
}

template <typename T> bool ar::circular_queue<T>::empty() const
{
	return (m_begin == m_end && m_isWrapped == false);
}

template <typename T> bool ar::circular_queue<T>::full() const
{
	return m_isWrapped;
}

template <typename T> bool ar::circular_queue<T>::push(const T &obj)
{
	if (m_isWrapped)
		return false;

	m_buffer[m_end] = obj;
	m_end = (m_end + 1) % m_size;

	if (m_end == m_begin)
		m_isWrapped = true;

	return true;
}

template <typename T> bool ar::circular_queue<T>::pull(T &obj)
{
	if (peak(obj))
	{
		m_buffer[m_begin] = T();
		m_begin = (m_begin + 1) % m_size;
		m_isWrapped = false;
		return true;
	}
	else
		return false;
}

template <typename T> bool ar::circular_queue<T>::peak(T &obj) const
{
	if (empty())
		return false;

	obj = m_buffer[m_begin];
	return true;
}
