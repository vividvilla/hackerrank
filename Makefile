CC_FILES = $(wildcard src/*.cpp)
BIN_FILES = $(patsubst src/%.cpp, %, $(CC_FILES))
CC_FLAGS = -Wall -O2 -lm
CC = g++

all: $(BIN_FILES)

.PHONY: check-syntax
check-syntax:
	$(CC) $(CC_FLAGS) -Wextra -pedantic -fsyntax-only $(CHK_SOURCES)

%: src/%.cpp
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	rm -f $(BIN_FILES)
