make:
	g++ -o .\build\hangman main.cpp .\src\display.cpp .\src\game.cpp

run:
	powershell.exe -Command "& {Start-Process powershell.exe -ArgumentList '.\build\hangman.exe'}"

clean:
	rm -Force .\build\hangman.exe