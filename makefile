prog: main.o text.o button.o menu.o 
	gcc Compile/main.o Compile/text.o Compile/button.o Compile/menu.o -o game -lSDL -g -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -g -o Compile/main.o
button.o:Scripts/Sources/button.c
	gcc -c Scripts/Sources/button.c -g -o Compile/button.o
menu.o:Scripts/Sources/menu.c
	gcc -c Scripts/Sources/menu.c -g -o Compile/menu.o
text.o:Scripts/Sources/text.c
	gcc -c Scripts/Sources/text.c -g -o Compile/text.o