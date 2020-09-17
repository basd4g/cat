CFLAGS=-std=c11
SRCS=cat.c
OBJS=$(SRCS:.c=.o)

cat: $(OBJS)
	$(CC) -o cat $(OBJS) $(LDFLAGS)

test: cat
	diff cat.c < ./cat cat.c

clean:
	rm -rf *.o cat
.PHONY: test clean
