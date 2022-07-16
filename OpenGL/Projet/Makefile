#Makefile pour les shaders
#R. RAFFIN, Dept Info, Arles

compilateur = g++
preproc_options = -c -Wall -Iinclude
link_options = -Wall
libs = -lglew32 -Llib -lfreeglut -lopengl32 -lglu32
main = main

all: $(main)
	@echo "\ncompilation terminee"

$(main): fonctions.o objetsOFF.o glsl_fs.o glsl_vs.o glsl_program.o main.o
	@echo "--- compilation de $@ ..."
	$(compilateur) $(link_options) $^ $(libs) -o $@
	@echo "--- compilation de $@ terminée"

fonctions.o: fonctions.cpp fonctions.h
	$(compilateur) $(preproc_options) $<
	
objetsOFF.o: objetsOFF.cpp objetsOFF.h
	$(compilateur) $(preproc_options) $<

glsl_fs.o: glsl_fs.cpp glsl_fs.h
	$(compilateur) $(preproc_options) $<

glsl_program.o: glsl_program.cpp glsl_program.h
	$(compilateur) $(preproc_options) $<

glsl_vs.o: glsl_vs.cpp glsl_vs.h
	$(compilateur) $(preproc_options) $<

main.o: main.cpp
	$(compilateur) $(preproc_options) $<

clean:
	rm -f *.o $(main) *~

archive:
	tar czvf $(main).tgz *.cpp *.h Makefile *.vert *.frag
