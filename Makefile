All: chars csvfold linesafter linesbefore linefold trimws unfind
	@sleep 1
	touch All

chars: chars.c
	gcc -o chars chars.c

chars.c:

csvfold: csvfold.c
	gcc -o csvfold csvfold.c

csvfold.c:

linefold: linefold.c
	gcc -o linefold linefold.c

linefold.c:

linesafter: linesafter.c
	gcc -o linesafter linesafter.c

linesafter.c:

linesbefore: linesbefore.c
	gcc -o linesbefore linesbefore.c

linesbefore.c:

trimws: trimws.c
	gcc -o trimws trimws.c

trimws.c:

unfind: unfind.c
	gcc -o unfind unfind.c

unfind.c:

userinstall:
	cp -p chars           $(HOME)/bin/chars
	chmod u=rwx,go=rx     $(HOME)/bin/chars
	cp -p csvfold         $(HOME)/bin/csvfold
	chmod u=rwx,go=rx     $(HOME)/bin/csvfold
	cp -p linefold        $(HOME)/bin/linefold
	chmod u=rwx,go=rx     $(HOME)/bin/linefold
	cp -p linesafter      $(HOME)/bin/linesafter
	chmod u=rwx,go=rx     $(HOME)/bin/linesafter
	cp -p linesbefore     $(HOME)/bin/linesbefore
	chmod u=rwx,go=rx     $(HOME)/bin/linesbefore
	cp -p trimws          $(HOME)/bin/trimws
	chmod u=rwx,go=rx     $(HOME)/bin/trimws
	cp -p unfind          $(HOME)/bin/unfind
	chmod u=rwx,go=rx     $(HOME)/bin/unfind
