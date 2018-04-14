OUT = build/prog2
CC = g++
MKDIR = mkdir -p
ODIR = obj
SDIR = src
INC = -Iinc

_OBJS = main.o virtualmachine/virtualmachine.o memory/memory.o memory/stack/stack.o memory/registerarray/registerarray.o \
		json/jsonobject.o json/jsonarray.o datei/datei.o datei/sprache/sprache.o datei/instruction/instruction.o \
		datei/instruction/simpleinstruction/simpleinstruction.o datei/instruction/complexinstruction/complexinstruction.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))


$(ODIR)/%.o: $(SDIR)/%.cpp
	$(MKDIR) $(shell echo $@ | rev | cut -d"/" -f2- | rev)
	$(CC) -c $(INC) -o $@ $< $(CFLAGS)

$(OUT): $(OBJS) 
	$(MKDIR) $(shell echo $(OUT) | rev | cut -d"/" -f2- | rev)
	$(CC) -o $(OUT) $^

.PHONY: clean

clean:
	rm -rf $(ODIR) $(shell echo $(OUT) | rev | cut -d"/" -f2- | rev)