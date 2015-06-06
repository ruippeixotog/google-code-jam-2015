QUAL_CC_FILES = $(wildcard qualification/*.cpp)
QUAL_BIN_FILES = $(patsubst qualification/%.cpp, %, $(QUAL_CC_FILES))
ROUND1A_CC_FILES = $(wildcard round1a/*.cpp)
ROUND1A_BIN_FILES = $(patsubst round1a/%.cpp, %, $(ROUND1A_CC_FILES))
ROUND1B_CC_FILES = $(wildcard round1b/*.cpp)
ROUND1B_BIN_FILES = $(patsubst round1b/%.cpp, %, $(ROUND1B_CC_FILES))
ROUND2_CC_FILES = $(wildcard round2/*.cpp)
ROUND2_BIN_FILES = $(patsubst round2/%.cpp, %, $(ROUND2_CC_FILES))

BIN_FILES = $(QUAL_BIN_FILES) $(ROUND1A_BIN_FILES) $(ROUND1B_BIN_FILES) $(ROUND2_BIN_FILES)
CC_FLAGS = -Wall -O2 -lm
CC = g++

all: $(BIN_FILES)

$(QUAL_BIN_FILES):%: qualification/%.cpp
	$(CC) $(CC_FLAGS) -o $@ $<

$(ROUND1A_BIN_FILES):%: round1a/%.cpp
	$(CC) $(CC_FLAGS) -o $@ $<

$(ROUND1B_BIN_FILES):%: round1b/%.cpp
	$(CC) $(CC_FLAGS) -o $@ $<

$(ROUND2_BIN_FILES):%: round2/%.cpp
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	rm -f $(BIN_FILES)
