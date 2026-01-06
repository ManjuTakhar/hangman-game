CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./include
SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/**/*.cpp) $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/hangman

.PHONY: all clean directories

all: directories $(TARGET)

directories:
	@mkdir -p $(OBJDIR)/game $(OBJDIR)/gamestate $(OBJDIR)/gamemode
	@mkdir -p $(OBJDIR)/word $(OBJDIR)/wordlist $(OBJDIR)/player
	@mkdir -p $(OBJDIR)/score $(OBJDIR)/difficulty $(OBJDIR)/display
	@mkdir -p $(OBJDIR)/input $(OBJDIR)/config $(OBJDIR)/utils
	@mkdir -p $(OBJDIR)/stats $(OBJDIR)/hint $(OBJDIR)/save $(OBJDIR)/validator
	@mkdir -p $(BINDIR)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

run: $(TARGET)
	./$(TARGET)

