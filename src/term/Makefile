EXE = term
all: $(EXE)

CC = g++
CFLAGS = -g -W -Wall
LIBS =
INCLUDE = -I/usr/local/include

OBJS = main.o

-include $(OBJS:.o=.d)

term: $(OBJS)
	$(CC) $(INCLUDE) -o $@ $(CFLAGS) $(LIBS) $(OBJS)

%.d: %.cpp
	set -e; $(CC) $(INCLUDE) -MM $(CFLAGS) $< \
		| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
		[ -s $@ ] || rm -f $@

%.o: %.cpp
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXE) *.o *~ core.* *.d
