main:
	make -f Makefile.main

add:
	make -f Makefile.add

sub:
	make -f Makefile.sub

mul:
	make -f Makefile.mul

conv:
	make -f Makefile.conv

all:
	make -f Makefile.add
	make -f Makefile.sub
	make -f Makefile.mul
	make -f Makefile.conv

runTests:
	./add
	./sub
	./mul
	./conv

clean:
	rm -f sub
	rm -f mul
	rm -f main
	rm -f add
	rm -f conv