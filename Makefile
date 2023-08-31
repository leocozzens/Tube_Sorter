CC = gcc
BINREADER = xxd -i
EXT = c
CFLAGS = -Iinclude -g -Wall
SRC = src
INCLUDE = include
OBJ = obj
RAWNAME = raw
RAW = raw_assets
BINDIR = bin
PROJNAME = Tube_Sorter
BINNAME = $(PROJNAME).bin
SRCS = $(wildcard $(SRC)/*.$(EXT))
OBJS = $(patsubst $(SRC)/%.$(EXT), $(OBJ)/%.o, $(SRCS))
RAW_ASSETS = $(wildcard $(RAW)/*.$(RAWNAME))
RAWS = $(patsubst $(RAW)/%.$(RAWNAME), $(INCLUDE)/$(RAWNAME)_%.h, $(RAW_ASSETS))
BIN = $(BINDIR)/$(BINNAME)

SUBMITNAME = $(PROJECT_NAME).zip
zip = zip

all: create_dirs
all: $(BIN)

release: CFLAGS = -I$(INCLUDE) -O2
release: new

$(BIN): $(RAWS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.$(EXT)
	$(CC) $(CFLAGS) -c $< -o $@

$(INCLUDE)/$(RAWNAME)_%.h: $(RAW)/%.$(RAWNAME)
	$(BINREADER) $< > $@

%.o: $(SRC)/%.$(EXT)
	$(CC) $(CFLAGS) -c $< -o $(OBJ)/$@	

link: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN)

clean:
	rm -rf $(BINDIR) $(OBJ)
	rm -f $(INCLUDE)/$(RAWNAME)_*

create_dirs:
	@mkdir -p $(BINDIR) $(OBJ)

new: clean
new: all

submit:
	rm -f $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)