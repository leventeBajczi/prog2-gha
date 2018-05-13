OUT = build/prog2
CC = g++
MKDIR = mkdir -p
ODIR = obj
SDIR = src
INC = -Iinc

_OBJS = main.o datei/sprache/sprache.o virtualmachine/virtualmachine.o memory/memory.o \
		datei/datei.o datei/instruction/instruction.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))


$(ODIR)/%.o: $(SDIR)/%.cpp
	$(MKDIR) $(shell echo $@ | rev | cut -d"/" -f2- | rev)
	$(CC) -g -c $(INC) -o $@ $< $(CFLAGS)

$(OUT): $(OBJS)
	$(MKDIR) $(shell echo $(OUT) | rev | cut -d"/" -f2- | rev)
	$(CC) -g -o $(OUT) $^

.PHONY: clean

clean:
	rm -rf $(ODIR) $(shell echo $(OUT) | rev | cut -d"/" -f2- | rev) $(LIB)/build