#pragma once

#include <utility>
#include "container.hh"

namespace ar
{
	template <typename TKey, typename TValue>
	using map = container< std::pair<TKey,TValue> >;
}
