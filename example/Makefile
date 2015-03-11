CPPFLAGS:=-I../include -I../../err2/include/ -MMD
CFLAGS:=--save-temps -O2 -W -Wall --std=gnu99 -Werror -Wno-unused-parameter

SRC:=$(wildcard *.c)
PROGS:=cat catl ls echo head

.PHONY: all
all: $(PROGS)

cat: cat.o libffile.a
catl: catl.o libffile.a
head: head.o libffile.a

.PRECIOUS: ffile.o
libffile.a: libffile.a(ffile.o)

.PHONY: clean
clean:
	$(RM) $(PROGS) *.[adios]

include ../../makelib/include/makelib/Library.mak
-include $(SRC:.c=.d)
