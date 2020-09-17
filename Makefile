CFLAGS=-std=c11
SRCS=cat.c
OBJS=$(SRCS:.c=.o)

cat: $(OBJS)
	$(CC) -o cat $(OBJS) $(LDFLAGS)

test: cat
	./cat cat.c | (cat cat.c | diff /dev/fd/3 - ) 3<&0
	./cat cat.c Makefile | (cat cat.c Makefile | diff /dev/fd/3 - ) 3<&0

clean:
	rm -rf *.o cat
.PHONY: test clean
