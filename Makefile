#
# Download and place this file into your git repository. 
# Rename it to 'Makefile' (without quotes)
#
# wget http://www.phys.uconn.edu/phys2200/downloads/Makefile.sample
# mv Makefile.sample Makefile
#
# or
#
# wget http://www.phys.uconn.edu/phys2200/downloads/Makefile.sample -O Makefile
#

EDITOR = /usr/bin/gedit
INDENT = /usr/bin/indent

CC        = clang
LDFLAGS   = -O2
CFLAGS    = -Weverything -Wextra -pedantic $(LDFLAGS)
LDLIBS    = -lm

.SUFFIXES:
.SUFFIXES:  .c .o .h

.PHONY: edit clean veryclean

target    = pi

$(target) : $(target).o pi-code.o timer.o adjust.o
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

edit : $(target).c
	$(EDITOR) $<
	$(INDENT) $<

clean : 
	rm -f *.o
	rm -f *.*~

veryclean : clean
	rm  -f $(target)
