# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -g

# Source files
q1_SRCS = a3q1_main.c a3q1_functions.c
q2_SRCS = a3q2_main.c a3q2_functions.c

# Header files
HEADERS = a3q1_header.h a3q2_header.h

# Object files
q1_OBJS = $(q1_SRCS:.c=.o)
q2_OBJS = $(q2_SRCS:.c=.o)

# Executable names
q1_TARGET = a3q1
q2_TARGET = a3q2

# Build all targets
all: $(q1_TARGET) $(q2_TARGET)

# Link object files to create the executable for q1
$(q1_TARGET): $(q1_OBJS)
	$(CC) $(CFLAGS) -o $@ $(q1_OBJS)

# Link object files to create the executable for q2
$(q2_TARGET): $(q2_OBJS)
	$(CC) $(CFLAGS) -o $@ $(q2_OBJS)

# Compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(q1_TARGET) $(q2_TARGET) *.o
