#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define DA_INIT_CAPACITY 256

#define da_reserve(da, expected_capacity)                                               \
    do {                                                                                \
        if ((expected_capacity) > (da)->capacity) {                                     \
            if ((da)->capacity == 0) {                                                  \
                (da)->capacity = DA_INIT_CAPACITY;                                      \
            }                                                                           \
            while ((expected_capacity) > (da)->capacity) {                              \
                (da)->capacity *= 2;                                                    \
            }                                                                           \
            (da)->items = realloc((da)->items, (da)->capacity * sizeof(*(da)->items) ); \
            assert((da)->items != NULL && "Buy more RAM lol");                          \
        }                                                                               \
    } while (0)

#define da_append(da, item)                  \
    do {                                     \
        da_reserve((da), (da)->count + 1);   \
        (da)->items[(da)->count++] = (item); \
    } while (0)

#define da_free(da) free((da).items)

#define da_foreach(Type, it, da) for (Type *it = (da)->items; it < (da)->items + (da)->count; ++it)

#define da_append_many(da, new_items, new_items_count)                                          \
    do {                                                                                        \
        da_reserve((da), (da)->count + (new_items_count));                                      \
        memcpy((da)->items + (da)->count, (new_items), (new_items_count)*sizeof(*(da)->items)); \
        (da)->count += (new_items_count);                                                       \
    } while (0)

#define da_resize(da, new_size)     \
    do {                            \
        da_reserve((da), new_size); \
        (da)->count = (new_size);   \
    } while (0)

#define da_last(da) (da)->items[(assert((da)->count > 0), (da)->count-1)]

#define da_remove_unordered(da, i)                   \
    do {                                             \
        size_t j = (i);                              \
        assert(j < (da)->count);                     \
        (da)->items[j] = (da)->items[--(da)->count]; \
    } while(0)

#define da_remove(da, i)                   \
    do {                                             \
        size_t j = (i);                              \
        assert(j < (da)->count);                     \
		memmove((da)->items + i, (da)->items + i + 1, ((da)->count - i - 1) * sizeof(*(da)->items));\
        (da)->count--; \
    } while(0)

typedef struct {
	int *items;
	size_t count;
	size_t capacity;
} Int_da;

int main() {

	Int_da nums = {0};

	for (int i = 0; i <10; i++) {
		da_append(&nums, i);
	}

	printf("\narray looks like: ");
	da_foreach(int, num_p, &nums) {
		printf("%d ", *num_p);
	}

	da_remove_unordered(&nums, 5);

	printf("\narray looks like: ");
	da_foreach(int, num_p, &nums) {
		printf("%d ", *num_p);
	}

	da_remove(&nums, 5);

	printf("\narray looks like: ");
	da_foreach(int, num_p, &nums) {
		printf("%d ", *num_p);
	}

	return 0;
}
