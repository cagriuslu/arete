#define CATCH_CONFIG_MAIN
#include "dep/Catch-1.10.0/catch.hpp"

#include <arete/circular_queue.hh>
#include <string>

TEST_CASE("circular_queue", "[container]")
{
	ar::circular_queue<int> queue(5);
	int item;

	REQUIRE(queue.capacity() == 5);
	REQUIRE(queue.size() == 0);
	REQUIRE(queue.empty() == true);
	REQUIRE(queue.full() == false);
	REQUIRE(queue.pull(item) == false);
	REQUIRE(queue.peak(item) == false);

	item = 0;
	REQUIRE(queue.push(item) == true);
	item = 1;
	REQUIRE(queue.push(item) == true);
	item = 2;
	REQUIRE(queue.push(item) == true);
	item = 3;
	REQUIRE(queue.push(item) == true);
	item = 4;
	REQUIRE(queue.push(item) == true);
	item = 5;
	REQUIRE(queue.push(item) == false);

	REQUIRE(queue.capacity() == 5);
	REQUIRE(queue.size() == 5);
	REQUIRE(queue.empty() == false);
	REQUIRE(queue.full() == true);

	REQUIRE(queue.pull(item) == true);
	REQUIRE(item == 0);

	REQUIRE(queue.capacity() == 5);
	REQUIRE(queue.size() == 4);
	REQUIRE(queue.empty() == false);
	REQUIRE(queue.full() == false);

	REQUIRE(queue.pull(item) == true);
	REQUIRE(item == 1);
	REQUIRE(queue.pull(item) == true);
	REQUIRE(item == 2);
	REQUIRE(queue.pull(item) == true);
	REQUIRE(item == 3);
	REQUIRE(queue.pull(item) == true);
	REQUIRE(item == 4);

	REQUIRE(queue.capacity() == 5);
	REQUIRE(queue.size() == 0);
	REQUIRE(queue.empty() == true);
	REQUIRE(queue.full() == false);
}
