CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

IDIR=include
SDIR=src
ODIR=build
LDIR=../lib

LIBS=-lm

_DEPS = bbst.h node.h planeSweeper.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o bbst.o node.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_SRC = main.cc bbst.cc node.cc planeSweeper.cc
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

$(ODIR)/%.o: $(SDIR)/%.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(SRC) $(DEPS)
	$(CC) -o build/$@ $(SRC) $(CFLAGS) $(LIBS)
	./build/all

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o core