target=server client
.PHONY:all clean

all:$(target)

server:
	g++ epoll_s.cpp -std=c++11 -o server

client:
	g++ epoll_c.cpp -std=c++11 -o client

clean:
	rm server client
