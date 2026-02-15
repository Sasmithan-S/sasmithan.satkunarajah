all: Flood-It

API_Gene_instance.o: API_Gene_instance.c API_Gene_instance.h
	gcc -c API_Gene_instance.c `sdl2-config --cflags`

API_Grille.o: API_Grille.c API_Grille.h
	gcc -c API_Grille.c `sdl2-config --cflags`

Liste_case.o: Liste_case.c Liste_case.h
	gcc -c Liste_case.c `sdl2-config --cflags`

exercice1.o: exercice1.c exercice1.h 
	gcc -c exercice1.c `sdl2-config --cflags`

exercice2.o: exercice2.c exercice2.h
	gcc -c exercice2.c `sdl2-config --cflags`

exercice3.o: exercice3.c exercice3.h
	gcc -c exercice3.c `sdl2-config --cflags`

exercice4.o: exercice4.c exercice4.h
	gcc -c exercice4.c `sdl2-config --cflags`

graphe.o: graphe.c graphe.h
	gcc -c graphe.c `sdl2-config --cflags`

Flood-It.o: Flood-It.c
	gcc -c Flood-It.c `sdl2-config --cflags`

Flood-It: Flood-It.o Liste_case.o API_Grille.o API_Gene_instance.o exercice1.o exercice2.o exercice3.o exercice4.o graphe.o
	gcc -o Flood-It Flood-It.o Liste_case.o API_Grille.o API_Gene_instance.o exercice1.o exercice2.o exercice3.o exercice4.o graphe.o `sdl2-config --libs` 

clean:
	rm -f *.o Flood-It
	rm -rf Courbes

graphes:
	mkdir -p Courbes/nbcl Courbes/dim Courbes/donnees/coups Courbes/donnees/temps
	./Flood-it 10 10 5 1 1 0 1
	./Flood-it 10 10 5 1 2 0 1 
	./Flood-it 10 10 5 1 3 0 1 
	./Flood-it 10 10 5 1 4 0 1
	gnuplot script_courbes.gp