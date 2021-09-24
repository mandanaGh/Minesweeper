# Minesweeper
A c++ Minesweeper game.
The program is written in Turbo C++.

## Rules
Minesweeper rules are very simple. The board is divided into cells, with mines randomly distributed. To win, you need to open all the cells. The objective in Minesweeper is to find and mark all the mines hidden under the grey squares, in the shortest time possible. This is done by clicking on the squares to open them. The number on a cell shows the number of mines adjacent to it. Using this information, you can determine cells that are safe, and cells that contain mines. Cells suspected of being mines can be marked with a flag using the right mouse button. Each square will have one of the following:

1. A mine, and if you click on it you'll lose the game.
2. A number, which tells you how many of its adjacent squares have mines in them.
3. Nothing. In this case you know that none of the adjacent squares have mines, and they will be automatically opened as well.

It is guaranteed that the first square you open won't contain a mine, so you can start by clicking any square. Often you'll hit on an empty square on the first try and then you'll open up a few adjacent squares as well, which makes it easier to continue. Then it's basically just looking at the numbers shown, and figuring out where the mines are.
<br>
<br>
<br>



<p align="center">
<img src="https://github.com/mandanaGh/Minesweeper/blob/main/images/Minesweeper.jpg" width="600"></p>
