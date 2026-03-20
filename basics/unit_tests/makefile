CC = clang
CFLAGS = -Wall -Wextra -std=c11 -I../..
TARGET = example_test.out
SOURCES = example_test.c ../../munit/munit.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
