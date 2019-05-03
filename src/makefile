CC	= gcc
IDIR	= ../include
ODIR	= obj

# Dependências do módulo principal
_MAINOBJ = memoria.o main.o test_mem.o simulator.o
MAINOBJ = $(patsubst %, $(ODIR)/%, $(_MAINOBJ))

_MAINDEPS = memoria.h test_mem.h simulator.h
MAINDEPS = $(patsubst %, $(IDIR)/%, $(_MAINDEPS))

# Compilando módulos
$(ODIR)/%.o: %.c
	$(CC) -g -c -o $@ $<

main: $(MAINOBJ) $(MAINDEPS)
	$(CC) -g -o $@ $^

.PHONY: clean

clean:
	rm -f  $(ODIR)/*.o *~ $(IDIR)/*~ main
