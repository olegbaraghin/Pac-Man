# Pac-Man
Proiectul reprezinta un joc numit Pac-Man in care cu player-ul tau mergi printr-un labirint cu obstacole precum fantome.

Regulile jocului Pac-Man:

`Arrow Up` - move Up;
`Arrown Down` - move Down;
`Arrow Left` - move Left;
`Arrow Right` - move Right;

Mergi prin labirint, colectezi niste puncte care se acumuleaza la Score (Normal Pellet, Power Pellet).
Fii atent cu inamicii precum fantomele fiindca te pot omori.


`direction.hpp` -> In acest obiect avem un enum care primeste toate directiile player-ului.
`pacman.hpp` -> In acest file avem clasa Pacman, care reprezinta jucatorul din joc. Aceasta tine evidenta pozitiei, directiei in care se misca, scorului si starii de Power Mode.
`ghost.hpp` -> Aici sunt reprezentate fantomele din joc. Acesta tine evidenta pozitiei, directiei, starii curente si a tintei pe care fantoma o urmareste.
`maze.hpp` -> In clasa Maze este reprezentat labirintul. Aici sunt gestionate dimensiunile labirintului si tipul fiecarei celule.
`pellet` ->  Aici sunt reprezentate cerculetele pe care tu cu ajutorul la PacMan le colectezi. Ele au o pozitie anume, tipul si daca a fost deja colectata.
`painter.hpp` -> se ocupa de redare vizuala a jocului. El afiseaza elemente grafice.
`point.hpp` -> reprezinta pozitia pe labirint.
`game_engine.hpp` -> logica principala a jocului Pac-Man. El leaga toate componentele ai acestui joc: PacMan, fantome, labirintul, cerculetele care trebuie sa fie mancate de PacMan si scorul.