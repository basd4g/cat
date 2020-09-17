CFLAGS=-std=c11
SRCS=cat.c
OBJS=$(SRCS:.c=.o)

willani: $(OBJS)
	$(CC) -o cat $(OBJS) $(LDFLAGS)

test: willani
	@echo 'No test cases'

clean:
	rm -rf *.o cat
.PHONY: test clean
