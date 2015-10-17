OBJS = basic.o
OBJS += wall_post.o
OBJS += wall.o
OBJS += user.o
OBJS += user_network.o
OBJS += main.o

CC = g++

%.o: %.cpp
	$(CC) -c $< -o $@

run: ${OBJS}
	$(CC) $^ -o $@

.PHONY: all
all: run


