#include <iostream>
#include <SDL.h>
#include "Font.h"

Font::Font(const int characterAmount) {
    this->size = characterAmount;
}

SDL_Texture* Font::GetTexture() {
    return texture;
}

int Font::GetSize() {
    return size;
}

void Font::SetSize(int temp) {
    size = temp;
}

void Font::SetTexture(SDL_Texture* temptex) {
    texture = temptex;
}

SDL_Rect* Font::GetRectangle() {
    return &rectangle;
}

void Font::LoadText(int stepW,int stepH) {
    SDL_Rect temp;
    int xCord = 1;
    int yCord = 1;
    for (int i = 0; i < size; i++)
    {
        sourceRectangles.push_back(temp);
        sourceRectangles[i].x = xCord;
        sourceRectangles[i].y = yCord;
        sourceRectangles[i].w = stepW;
        sourceRectangles[i].h = stepH;
        xCord += 31;
    }
}

void Font::RenderText(SDL_Renderer* renderer, std::string text, int x, int y, int w, int h, int step,int textStartX,int textStartY) {
    rectangle.x = x + textStartX;
    rectangle.y = y + textStartY;
    rectangle.w = w;
    rectangle.h = h;
    int temp = rectangle.x;
    for (int i = 0; i < text.length(); i++)
    {
        switch (text[i])
        {
        case 'A':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[0], &rectangle);
            rectangle.x += step;
            break;
        case 'B':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[1], &rectangle);
            rectangle.x += step;
            break;
        case 'C':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[2], &rectangle);
            rectangle.x += step;
            break;
        case 'D':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[3], &rectangle);
            rectangle.x += step;
            break;
        case 'E':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[4], &rectangle);
            rectangle.x += step;
            break;
        case 'F':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[5], &rectangle);
            rectangle.x += step;
            break;
        case 'G':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[6], &rectangle);
            rectangle.x += step;
            break;
        case 'H':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[7], &rectangle);
            rectangle.x += step;
            break;
        case 'I':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[8], &rectangle);
            rectangle.x += step;
            break;
        case 'J':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[9], &rectangle);
            rectangle.x += step;
            break;
        case 'K':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[10], &rectangle);
            rectangle.x += step;
            break;
        case 'L':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[11], &rectangle);
            rectangle.x += step;
            break;
        case 'M':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[12], &rectangle);
            rectangle.x += step;
            break;
        case 'N':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[13], &rectangle);
            rectangle.x += step;
            break;
        case 'O':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[14], &rectangle);
            rectangle.x += step;
            break;
        case 'P':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[15], &rectangle);
            rectangle.x += step;
            break;
        case 'Q':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[16], &rectangle);
            rectangle.x += step;
            break;
        case 'R':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[17], &rectangle);
            rectangle.x += step;
            break;
        case 'S':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[18], &rectangle);
            rectangle.x += step;
            break;
        case 'T':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[19], &rectangle);
            rectangle.x += step;
            break;
        case 'U':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[20], &rectangle);
            rectangle.x += step;
            break;
        case 'V':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[21], &rectangle);
            rectangle.x += step;
            break;
        case 'W':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[22], &rectangle);
            rectangle.x += step;
            break;
        case 'X':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[23], &rectangle);
            rectangle.x += step;
            break;
        case 'Y':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[24], &rectangle);
            rectangle.x += step;
            break;
        case 'Z':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[25], &rectangle);
            rectangle.x += step;
            break;
        case 'a':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[26], &rectangle);
            rectangle.x += step;
            break;
        case 'b':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[27], &rectangle);
            rectangle.x += step;
            break;
        case 'c':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[28], &rectangle);
            rectangle.x += step;
            break;
        case 'd':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[29], &rectangle);
            rectangle.x += step;
            break;
        case 'e':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[30], &rectangle);
            rectangle.x += step;
            break;
        case 'f':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[31], &rectangle);
            rectangle.x += step;
            break;
        case 'g':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[32], &rectangle);
            rectangle.x += step;
            break;
        case 'h':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[33], &rectangle);
            rectangle.x += step;
            break;
        case 'i':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[34], &rectangle);
            rectangle.x += step;
            break;
        case 'j':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[35], &rectangle);
            rectangle.x += step;
            break;
        case 'k':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[36], &rectangle);
            rectangle.x += step;
            break;
        case 'l':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[37], &rectangle);
            rectangle.x += step;
            break;
        case 'm':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[38], &rectangle);
            rectangle.x += step;
            break;
        case 'n':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[39], &rectangle);
            rectangle.x += step;
            break;
        case 'o':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[40], &rectangle);
            rectangle.x += step;
            break;
        case 'p':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[41], &rectangle);
            rectangle.x += step;
            break;
        case 'q':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[42], &rectangle);
            rectangle.x += step;
            break;
        case 'r':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[43], &rectangle);
            rectangle.x += step;
            break;
        case 's':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[44], &rectangle);
            rectangle.x += step;
            break;
        case 't':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[45], &rectangle);
            rectangle.x += step;
            break;
        case 'u':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[46], &rectangle);
            rectangle.x += step;
            break;
        case 'v':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[47], &rectangle);
            rectangle.x += step;
            break;
        case 'w':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[48], &rectangle);
            rectangle.x += step;
            break;
        case 'x':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[49], &rectangle);
            rectangle.x += step;
            break;
        case 'y':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[50], &rectangle);
            rectangle.x += step;
            break;
        case 'z':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[51], &rectangle);
            rectangle.x += step;
            break;
        case '0':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[52], &rectangle);
            rectangle.x += step;
            break;
        case '1':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[53], &rectangle);
            rectangle.x += step;
            break;
        case '2':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[54], &rectangle);
            rectangle.x += step;
            break;
        case '3':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[55], &rectangle);
            rectangle.x += step;
            break;
        case '4':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[56], &rectangle);
            rectangle.x += step;
            break;
        case '5':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[57], &rectangle);
            rectangle.x += step;
            break;
        case '6':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[58], &rectangle);
            rectangle.x += step;
            break;
        case '7':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[59], &rectangle);
            rectangle.x += step;
            break;
        case '8':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[60], &rectangle);
            rectangle.x += step;
            break;
        case '9':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[61], &rectangle);
            rectangle.x += step;
            break;
        case ':':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[62], &rectangle);
            rectangle.x += static_cast<int>(step *0.5);
            break;
        case '.':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[63], &rectangle);
            rectangle.x += static_cast<int>(step *0.5);
            break;
        case '-':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[64], &rectangle);
            rectangle.x += step;
            break;
        case '+':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[65], &rectangle);
            rectangle.x += step;
            break;
        case '(':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[66], &rectangle);
            rectangle.x += step;
            break;
        case ')':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[67], &rectangle);
            rectangle.x += step;
            break;
        case '%':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[68], &rectangle);
            rectangle.x += step;
            break;
        case '*':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[69], &rectangle);
            rectangle.x += step;
            break;
        case '/':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[70], &rectangle);
            rectangle.x += step;
            break;
        case '=':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[71], &rectangle);
            rectangle.x += step;
            break;
        case '!':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[72], &rectangle);
            rectangle.x += step;
            break;
        case '?':
            SDL_RenderCopy(renderer, texture, &sourceRectangles[73], &rectangle);
            rectangle.x += step;
            break;
        case ';':
            rectangle.y += step;
            rectangle.x = x;
            break;
           
        default:
            rectangle.x += step;
            break;
        }
    }
    rectangle.x = temp;
}

Font::~Font() {
    SDL_DestroyTexture(texture);
}