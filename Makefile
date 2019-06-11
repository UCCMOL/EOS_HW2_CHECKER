CC = g++
TARGETS = finaltest finalchecker
CFLAGS = -std=c++11

all: $(TARGETS)
	mkdir -p result
	mkdir -p p2_result

finaltest : finaltest.o

finalchecker : finalchecker.o

.cpp.o:
	$(CC) $(CFLAGS) -c -o $*.o $<

clean:
	rm -f *.o $(TARGETS)
	@rm -fr result
	@rm -fr p2_result

check_all: p1_check p2_check

p1_check:
	diff -qr result/ result_ans/
p2_check:
	./finalchecker
