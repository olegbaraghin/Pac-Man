CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Directoare
SRCDIR = src
LIBDIR = lib
INCDIR = include
TESTDIR = tests
OBJDIR = obj
BINDIR = bin

# Fișiere sursă
# Core Lib sources (Point, Ghost, etc.)
LIB_SOURCES = $(wildcard $(LIBDIR)/*.cpp)
# App sources (Main, Engine, Painter)
APP_SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Test sources
TEST_SOURCES = $(wildcard $(TESTDIR)/*.cpp)

# Obiecte
LIB_OBJECTS = $(patsubst $(LIBDIR)/%.cpp, $(OBJDIR)/lib_%.o, $(LIB_SOURCES))
APP_OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/src_%.o, $(APP_SOURCES))
TEST_OBJECTS = $(patsubst $(TESTDIR)/%.cpp, $(OBJDIR)/test_%.o, $(TEST_SOURCES))

# Executabile
TARGET = $(BINDIR)/pacman
TEST_TARGET = $(BINDIR)/run_tests

# Reguli implicite
all: directories $(TARGET)

# Creare executabil principal
$(TARGET): $(LIB_OBJECTS) $(APP_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Creare executabil teste
tests: directories $(TEST_TARGET)

$(TEST_TARGET): $(LIB_OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilare surse din lib/
$(OBJDIR)/lib_%.o: $(LIBDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilare surse din src/
$(OBJDIR)/src_%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilare surse din tests/
$(OBJDIR)/test_%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Creare directoare necesare
directories:
	mkdir -p $(OBJDIR) $(BINDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean tests directories

