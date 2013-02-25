CC_FILES = $(wildcard weekly/*.cpp) $(wildcard algorithmic-challenges/*/*.cpp)
BIN_FILES = $(patsubst %.cpp, %.out, $(CC_FILES))
CC_FLAGS = -Wall -O2 -lm
CC = g++

all: $(BIN_FILES)

.PHONY: check-syntax
check-syntax:
	$(CC) $(CC_FLAGS) -Wextra -pedantic -fsyntax-only $(CHK_SOURCES)

%.out: %.cpp
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	rm $(BIN_FILES)
