OBJS = basic.o
OBJS += wall_post.o
OBJS += wall.o
OBJS += user.o
OBJS += user_network.o
OBJS += main.o

CC = g++
CCFLAGS = -std=c++11
%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

run: ${OBJS}
	$(CC) $(CCFLAGS) $^ -o $@

.PHONY: all
all: run


