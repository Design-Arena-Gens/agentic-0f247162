CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGETS = counting_sort radix_sort bucket_sort

all: $(TARGETS)

counting_sort: counting_sort.c
	$(CC) $(CFLAGS) -o counting_sort counting_sort.c

radix_sort: radix_sort.c
	$(CC) $(CFLAGS) -o radix_sort radix_sort.c

bucket_sort: bucket_sort.c
	$(CC) $(CFLAGS) -o bucket_sort bucket_sort.c

clean:
	rm -f $(TARGETS)

test: all
	@echo "=== Testing Counting Sort ==="
	./counting_sort
	@echo "\n=== Testing Radix Sort ==="
	./radix_sort
	@echo "\n=== Testing Bucket Sort ==="
	./bucket_sort

.PHONY: all clean test
