# -------------------------------------
#  Makefile pentru proiectul Pac-Man
# -------------------------------------

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Directoare
SRC_DIR = src
LIB_DIR = lib
INC_DIR = include
OBJ_DIR = obj
BIN = pacman.exe
LIB_STATIC = libpacman.a

# Colectează toate fișierele .cpp
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
LIB_FILES = $(wildcard $(LIB_DIR)/*.cpp)

# Obiecte generate
SRC_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
LIB_OBJS = $(patsubst $(LIB_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(LIB_FILES))

# Toate obiectele
OBJS = $(SRC_OBJS) $(LIB_OBJS)

# Ținta principală
all: prepare $(LIB_STATIC) $(BIN)

# Creează folderul obj dacă nu există
prepare:
	@if [ ! -d $(OBJ_DIR) ]; then mkdir $(OBJ_DIR); fi

# -----------------------------
#  Creează biblioteca statică
# -----------------------------
$(LIB_STATIC): $(LIB_OBJS)
	ar rcs $(LIB_STATIC) $(LIB_OBJS)

# -----------------------------
#  Compilează executabilul
# -----------------------------
$(BIN): $(SRC_OBJS) $(LIB_STATIC)
	$(CXX) $(CXXFLAGS) -o $(BIN) $(SRC_OBJS) $(LIB_STATIC)

# -----------------------------
#  Regula pentru fișiere .cpp
# -----------------------------
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# -----------------------------
#  Curățare
# -----------------------------
clean:
	del /Q $(OBJ_DIR)\*.o
	del /Q $(BIN)
	del /Q $(LIB_STATIC)

clean_linux:
	rm -f $(OBJ_DIR)/*.o $(BIN) $(LIB_STATIC)

