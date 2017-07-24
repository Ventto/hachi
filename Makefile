BIN     = wordcount

SRCDIR  = src
SRCS    = hashtbl.c main.c
OBJS    = $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

CC      := gcc
CFLAGS  := -Wall -Wextra -pedantic -std=c99

.PHONY: all
all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: debug
debug: CFLAGS+=-g
debug: all

.PHONY: clean
clean:
	$(RM) $(OBJS) $(BIN)
