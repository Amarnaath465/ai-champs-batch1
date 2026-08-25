CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Iinclude

SRC := src/can_driver.c src/sensor_poll.c src/hal_adc.c src/hal_gpio.c src/state_machine.c src/diag_formatter.c
TEST_SRCS := $(wildcard tests/test_*.c)
TEST_BINS := $(patsubst tests/%.c,bin/%,$(TEST_SRCS))

.PHONY: all test clean

all: test

# Builds every tests/test_*.c against the shared SRC and runs it. Add a new
# tests/test_<module>.c file and `make test` picks it up automatically —
# no Makefile changes needed.
test: $(TEST_BINS)
	@status=0; \
	for t in $(TEST_BINS); do \
		echo "== $$t =="; \
		./$$t || status=1; \
		echo ""; \
	done; \
	exit $$status

bin/%: tests/%.c $(SRC) | bin
	$(CC) $(CFLAGS) -o $@ $< $(SRC)

bin:
	mkdir -p bin

clean:
	rm -rf bin
