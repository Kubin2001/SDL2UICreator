#pragma once

// Wymaga sdl2 do dzia�ania
// Funcja do wykrywania kolizji obiekt�w 2d w �rodkowisku sdl
// Zwarca od 1 do 4 w przypadku wykrycia kolizji a 0 w przypadku jej braku
//    2
//1       3
//    4
int Collision(SDL_Rect rect, SDL_Rect rect2);
// Wymaga sdl2 do dzia�ania
// Funcja do wykrywania kolizji obiekt�w 2d w �rodkowisku sdl
// Zwarca od 1 przypadku wykrycia kolizji a 0 w przypadku jej braku
// Nie wykrywa strony kolizji a tylko czy takowa mia�a miejsce
bool SimpleCollision(SDL_Rect rect, SDL_Rect rect2);
// Wymaga sdl2 do dzia�ania
// Funcja do wykrywania kolizji obiekt�w 2d w �rodkowisku sdl
// Zwarca od 1 do 4 w przypadku wykrycia kolizji a 0 w przypadku jej braku
// Dodaje mo�liwo�� wybrania g��boko�ci kolizji
int AdvancedCollision(SDL_Rect rect, SDL_Rect rect2, int deepth);

//Kolizja rectangle kt�re udaje ko�o i zwyk�ego sdl rect
//Mowa o kole idealnym nie np 40 na 60 tylko zawsze musi by� kwadratowe
bool CircleMouseCollision(const SDL_Rect circleRect, const SDL_Rect rect);

class CollisonProjectile
{
    private:
        int xMov = 0;
        
        int yMov = 0;

        int timer = 0;

        SDL_Rect rectangle;

    public:
        CollisonProjectile(int x, int y, int w, int h, int xMov, int yMov);

        SDL_Rect* GetRectangle();

        void setSpeedX(int temp);

        void setSpeedY(int temp);

        int GetTimer();

        void SetTimer(int temp);

        void MoveProjectlile();
};
