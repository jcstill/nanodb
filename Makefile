# Compiler Specific:
COMP=gcc
CFLAG=-c
WFLAG=-Wall
OFLAG=-o

# Program Specific:
SOURCES=	nanodb.c

OBJECTS=$(SOURCES:.c=.o)
HEADERS=$(SOURCES:.c=.h)
EXECUTABLE=nanodb

# Start of Make:
Start: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(COMP) $(OBJECTS) -lm $(OFLAG) $@ $(WFLAG)

.c.o:
	$(COMP) $(CFLAG) $< $(OFLAG) $@ $(WFLAG)

# Cleanup Routines:
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
