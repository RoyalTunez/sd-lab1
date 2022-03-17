#include "gtest/gtest.h"
#include "lru_cache.h"

TEST(LruCache, GetFromEmptyList) {
	lru_cache<int, int> cache(10);

	ASSERT_EQ(cache.get(10), int());
}