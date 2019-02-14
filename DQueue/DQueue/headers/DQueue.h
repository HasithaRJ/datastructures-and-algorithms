#pragma once
#include <algorithm>
#include <exception>
namespace datastructures
{
template <typename Ty>
class Dqueue
{
public:
	Dqueue();
	~Dqueue();
	void push(const Ty& value);
	Ty pop();
	const Ty& front() const;

private:
	char* m_container;
	size_t m_capacity;
	//size_t m_size;
	Ty* m_begin;
	Ty* m_end;
	Ty* m_front;
	Ty* m_back;

	void reserve();
	const size_t size() const;
};

template <typename Ty>
Dqueue<Ty>::Dqueue() : m_capacity(8), m_container(new char[m_capacity * sizeof(Ty)]), m_begin(reinterpret_cast<Ty*>(m_container))
	,m_end(reinterpret_cast<Ty*>(m_container + m_capacity)), m_front(m_begin), m_back(m_begin)
{
	
}
template <typename Ty>
Dqueue<Ty>::~Dqueue()
{
	if(m_container)
	{
		delete [] m_container;
		m_container = 0;
	}
}

template <typename Ty>
void Dqueue<Ty>::push(const Ty& value)
{
	reserve();
	*m_back = value;
	++m_back;
}

template <typename Ty>
void Dqueue<Ty>::reserve()
{
	if(size() >= m_capacity)
	{
        char* newArray = NULL;
		size_t newSize = m_capacity + m_capacity/2;

		try 
		{
			if(size() == m_capacity/2)
			{
				std::copy(m_front, m_back, m_begin);
			}
			else
			{
				newArray = new char[newSize * sizeof(Ty)];
				Ty* newContainer = reinterpret_cast<Ty*>(newArray);
				std::copy(m_front, m_back, newContainer);
				delete [] m_container;
				m_container = newArray;
				newArray = 0;
				m_begin = newContainer;
				m_end = newContainer + m_capacity;
			}

		
			m_back = m_begin + size();
			m_front = m_begin;
			m_capacity = newSize;
		} 
		catch(const std::exception& /*e*/)
		{
			throw "DQueue Exception: Container resize failed";
		}

	}
}

template <typename Ty>
Ty Dqueue<Ty>::pop()
{
	return *m_front++;
}

template <typename Ty>
const Ty& Dqueue<Ty>::front() const
{
	return *m_front;
}

template <typename Ty>
const size_t Dqueue<Ty>::size() const
{
	return m_back - m_front;
}
}