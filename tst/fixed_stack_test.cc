#define CATCH_CONFIG_MAIN
#include "dep/Catch-1.10.0/catch.hpp"

#include <arete/fixed_stack.hh>
#include <string>

TEST_CASE("fixed_stack", "[container]")
{
	ar::fixed_stack<int> stack(5);
	int item;

	REQUIRE(stack.capacity() == 5);
	REQUIRE(stack.size() == 0);
	REQUIRE(stack.empty() == true);
	REQUIRE(stack.full() == false);
	REQUIRE(stack.pull(item) == false);
	REQUIRE(stack.peak(item) == false);

	item = 0;
	REQUIRE(stack.push(item) == true);
	item = 1;
	REQUIRE(stack.push(item) == true);
	item = 2;
	REQUIRE(stack.push(item) == true);
	item = 3;
	REQUIRE(stack.push(item) == true);
	item = 4;
	REQUIRE(stack.push(item) == true);
	item = 5;
	REQUIRE(stack.push(item) == false);

	REQUIRE(stack.capacity() == 5);
	REQUIRE(stack.size() == 5);
	REQUIRE(stack.empty() == false);
	REQUIRE(stack.full() == true);

	REQUIRE(stack.pull(item) == true);
	REQUIRE(item == 4);

	REQUIRE(stack.capacity() == 5);
	REQUIRE(stack.size() == 4);
	REQUIRE(stack.empty() == false);
	REQUIRE(stack.full() == false);

	REQUIRE(stack.pull(item) == true);
	REQUIRE(item == 3);
	REQUIRE(stack.pull(item) == true);
	REQUIRE(item == 2);
	REQUIRE(stack.pull(item) == true);
	REQUIRE(item == 1);
	REQUIRE(stack.pull(item) == true);
	REQUIRE(item == 0);

	REQUIRE(stack.capacity() == 5);
	REQUIRE(stack.size() == 0);
	REQUIRE(stack.empty() == true);
	REQUIRE(stack.full() == false);
}
