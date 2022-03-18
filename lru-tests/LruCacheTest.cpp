#include "gtest/gtest.h"
#include "LruCache.h"

TEST(LruCache, GetFromEmptyList) {
	const size_t capacity = 10;
	LruCache<int, int> cache(capacity);

	ASSERT_EQ(cache.get(10), int());
}

TEST(LruCache, PutAndGet) {
	const size_t capacity = 3;
	LruCache<int, int> cache(capacity);

	int key = 1, value = 2;

	cache.put(key, value);

	ASSERT_EQ(value, cache.get(key));
}

TEST(LruCache, PutManyTimes) {
	const size_t capacity = 3;
	LruCache<int, int> cache(capacity);

	int key = 1;

	const int TEST_SIZE = 100;

	for (int value = 0; value < TEST_SIZE; value++) {
		cache.put(key, value);
		
		ASSERT_EQ(value, cache.get(key));
	}
}

TEST(LruCache, SimpleEviction) {
	const size_t capacity = 3;
	LruCache<int, int> cache(capacity);

	for (int value = 1; value <= capacity; value++) {
		cache.put(value, value);
	}

	int keyForMoving = 1;

	cache.get(keyForMoving);
	cache.put(4, 4);

	int evictedKey = 2;

	ASSERT_EQ(cache.get(evictedKey), int());
	ASSERT_NE(cache.get(keyForMoving), int());
}

TEST(LruCache, Evictions) {
	const size_t capacity = 3;
	LruCache<int, int> cache(capacity);

	for (int value = 1; value <= 10 * capacity; value++) {
		cache.put(value, value);
	}

	for (int evictedKey = 1; evictedKey < 10 * capacity - capacity; evictedKey++) {
		ASSERT_EQ(cache.get(evictedKey), int());
	}

	for (int cachedKey = 10 * capacity - capacity + 1; cachedKey <= 10 * capacity; cachedKey++) {
		ASSERT_NE(cache.get(cachedKey), int());
	}
}