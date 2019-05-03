CC	= gcc
IDIR	= ../include
ODIR	= obj

# Dependências do módulo principal
_MAINOBJ = memoria.o main.o test_mem.o simulator.o
MAINOBJ = $(patsubst %, $(ODIR)/%, $(_MAINOBJ))

_MAINDEPS = memoria.h test_mem.h simulator.h
MAINDEPS = $(patsubst %, $(IDIR)/%, $(_MAINDEPS))

_TESTSOBJ = test_mem.o test_simulator.o memoria.o run_tests.o simulator.o
TESTSOBJ = $(patsubst %, $(ODIR)/%, $(_TESTSOBJ))

_TESTSDEPS = memoria.h test_mem.h test_simulator.h run_tests.h simulator.h
TESTSDEPS = $(patsubst %, $(IDIR)/%, $(_TESTSDEPS))

# Compilando módulos
$(ODIR)/%.o: %.c
	$(CC) -g -c -o $@ $<

all:	main run_tests

main: $(MAINOBJ) $(MAINDEPS)
	$(CC) -g -o $@ $^

run_tests: $(TESTSOBJ) $(TESTSDEPS)
	$(CC) -g -o $@ $^

.PHONY: clean

clean:
	rm -f  $(ODIR)/*.o *~ $(IDIR)/*~ main
