.PHONY: petshop

HEADERS = animal.h petshop.h procedimento.h
OBJECTS = animal.o petshop.o procedimento.o

default: petshop

%.o: %.c $(HEADERS)
	    gcc -c $< -o $@

petshop: $(OBJECTS)
	    gcc $(OBJECTS) -o $@

clean:
	    -rm -f $(OBJECTS)
			-rm -f petshop
