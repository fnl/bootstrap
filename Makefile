PROG = $(P)
OBJECTS = 

#CC = cc
CFLAGS += -g -Wall -std=c99 -include standard.h -DG_LOG_DOMAIN=\"$(P)\" `pkg-config --cflags glib-2.0`
LDFLAGS +=
LDLIBS += `pkg-config --libs glib-2.0`

$(PROG): $(OBJECTS)

clean:
	rm -f *.o $(P)
	rm -rf $(P).dSYM
