prog: main.o text.o button.o menu.o player.o game_background.o music.o minimap.o enemy.o game.o tictac.o graphics.o core.o store.o enigmaphoto.o enigmatext.o choices.o backgroundenigma.o
	gcc Compile/main.o Compile/text.o Compile/button.o Compile/menu.o Compile/player.o Compile/game_background.o Compile/minimap.o Compile/enemy.o Compile/music.o Compile/tictac.o Compile/graphics.o Compile/core.o Compile/store.o Compile/game.o Compile/enigmaphoto.o Compile/enigmatext.o Compile/choices.o Compile/backgroundenigma.o -o game -lSDL -g -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -g -o Compile/main.o
button.o:Scripts/Sources/button.c
	gcc -c Scripts/Sources/button.c -g -o Compile/button.o
menu.o:Scripts/Sources/menu.c
	gcc -c Scripts/Sources/menu.c -g -o Compile/menu.o
text.o:Scripts/Sources/text.c
	gcc -c Scripts/Sources/text.c -g -o Compile/text.o
player.o:Scripts/Sources/player.c
	gcc -c Scripts/Sources/player.c -g -o Compile/player.o
game.o:Scripts/Sources/game.c
	gcc -c Scripts/Sources/game.c -g -o Compile/game.o
game_background.o:Scripts/Sources/game_background.c
	gcc -c Scripts/Sources/game_background.c -g -o Compile/game_background.o
minimap.o:Scripts/Sources/minimap.c
	gcc -c Scripts/Sources/minimap.c -g -o Compile/minimap.o
enemy.o:Scripts/Sources/enemy.c
	gcc -c Scripts/Sources/enemy.c -g -o Compile/enemy.o
music.o:Scripts/Sources/music.c
	gcc -c Scripts/Sources/music.c -g -o Compile/music.o
tictac.o:Scripts/TicTacToe/tictac.c
	gcc -c Scripts/TicTacToe/tictac.c -g -o Compile/tictac.o
graphics.o:Scripts/TicTacToe/graphics.c
	gcc -c Scripts/TicTacToe/graphics.c -g -o Compile/graphics.o
core.o:Scripts/TicTacToe/core.c
	gcc -c Scripts/TicTacToe/core.c -g -o Compile/core.o
store.o:Scripts/TicTacToe/store.c
	gcc -c Scripts/TicTacToe/store.c -g -o Compile/store.o
enigmatext.o: Scripts/Sources/Enigma/enigmatext.c
	gcc -c Scripts/Sources/Enigma/enigmatext.c -g -o Compile/enigmatext.o
enigmaphoto.o: Scripts/Sources/Enigma/enigmaphoto.c
	gcc -c Scripts/Sources/Enigma/enigmaphoto.c -g -o Compile/enigmaphoto.o
choices.o:Scripts/Sources/Enigma/choices.c
	gcc -c Scripts/Sources/Enigma/choices.c -g -o Compile/choices.o
backgroundenigma.o:Scripts/Sources/Enigma/backgroundenigma.c
	gcc -c Scripts/Sources/Enigma/backgroundenigma.c -g -o Compile/backgroundenigma.o
	