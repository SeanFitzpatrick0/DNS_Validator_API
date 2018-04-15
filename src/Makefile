IDIR = ../include
CC=gcc
CFLAGS=-I$(IDIR)
ODIR=obj

_DEPS = DNS_Validator.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = DNS_Validator_Tests.o DNS_Validator.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

DNS_Tests: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 