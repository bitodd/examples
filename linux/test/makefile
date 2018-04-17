TOPDIR=`pwd`
LIBPATH=${TOPDIR}
LDFLAGS=-Wl,-rpath,$(LIBPATH)
LIBS=-lpthread

TARGET=demo
.PHONY: all clean
all: $(TARGET)

$(TARGET) : test.o
	g++ -o demo test.o $(LIBS) #-L. -lagorasdk $(LDFLAGS)
test.o : test.cpp
	g++ -c test.cpp -I.
clean :
	rm -f demo test.o
