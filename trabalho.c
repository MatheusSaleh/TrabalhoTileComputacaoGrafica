#include<allegro5/allegro5.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>


#define BLOCKSIZE 32
#define WMAPA 50
#define HMAPA 20
#define SCREENWIDTH BLOCKSIZE*WMAPA
#define SCREENHEIGHT BLOCKSIZE*HMAPA
#define BLOCO_TRABALHO_3 2


enum KEYS {UP, DOWN, LEFT, RIGHT};
enum KEYS2 {W,S,A,D};

const char* blockFiles[5] =
{
    "blocoDoTrabalho1.bmp",
    "blocoDoTrabalho2.bmp",
    "blocoDoTrabalho3.bmp",
    "blocoDoTrabalho4.bmp",
    "blocoDoTrabalho5.bmp"
};

int mapa[25][40] =
{
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1},
    {1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1},
    {1,1,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0},
    {1,1,0,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,0},
    {1,1,0,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,0},
    {3,3,0,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,0},
    {3,3,0,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,0},
    {3,3,0,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,0},
    {3,3,0,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,0},
    {3,3,0,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,0},
    {3,3,0,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,0},
    {3,3,0,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,0},
    {3,3,0,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,0},
    {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3}
};

ALLEGRO_BITMAP *blocos[4] = {NULL, NULL, NULL, NULL};

void drawMap()
{
    for(int i = 0; i < HMAPA; i++)
    {
        for(int j = 0; j < WMAPA; j++)
        {
            al_draw_bitmap(blocos[ mapa[i][j] ], j*BLOCKSIZE, i*BLOCKSIZE, 0 );
        }
    }
}

bool colisao(int x, int y)
{
    int pX1= x / BLOCKSIZE;
    int pY1= y / BLOCKSIZE;
    int pX2= (x+25) / BLOCKSIZE;
    int pY2= (y+25) / BLOCKSIZE;
    //printf ("x: %d  y: %d   c1: %d  l1: %d   c2: %d  l2: %d \n",x,y,pX1,pY1,pX2,pY2);
    if (mapa[pY1][pX1] !=2 || mapa[pY2][pX2] !=2 ||
            mapa[pY1][pX2] !=2 || mapa[pY2][pX1] !=2 )
        return true;
    else
        return false;
}

bool colisaoDoCowboy(int x, int y)
{
    int pX1= x / BLOCKSIZE;
    int pY1= y / BLOCKSIZE;
    int pX2= (x+25) / BLOCKSIZE;
    int pY2= (y+25) / BLOCKSIZE;
    printf ("x: %d  y: %d   c1: %d  l1: %d   c2: %d  l2: %d \n",x,y,pX1,pY1,pX2,pY2);
    if (mapa[pY1][pX1] ==2 || mapa[pY2][pX2] ==2 ||
            mapa[pY1][pX2] ==2 || mapa[pY2][pX1] ==2 )
    {
        printf("Colidiu");
        return true;
    }

    else
        return false;
}

bool checkColision(int playerX, int playerY, int characterX, int characterY, int player2, int personagem3)
{
    int playerLeft = playerX;
    int playerRight = playerX + al_get_bitmap_width(player2);
    int playerTop = playerY;
    int playerBottom = playerY + al_get_bitmap_height(player2);

    int characterLeft = characterX;
    int characterRight = characterX + al_get_bitmap_width(personagem3);
    int characterTop = characterY;
    int characterBottom = characterY + al_get_bitmap_height(personagem3);

    if(playerRight >= characterLeft && playerLeft <= characterRight &&
            playerBottom >= characterTop && playerTop <= characterBottom)
    {
        return true;
    }
    return false;
}

int main()
{
    ALLEGRO_DISPLAY *display;

    const float FPS = 60;
    bool done = false;
    bool redesenha = true;
    int posX = 265;
    int posY = 265;
    int posX2 = 650;
    int posY2 = 150;
    int posX5 = 600;
    int posY5 = 300;
    int posX6 = 650;
    int posY6 = 300;
    int posX3 = 600;
    int posY3 = 500;


    bool keys[4] = {false, false, false, false};
    bool keys2[4] = {false, false, false, false};

    al_init();
    display = al_create_display(SCREENWIDTH, SCREENHEIGHT);
    al_set_window_position(display, 300, 200);

    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    blocos[0] = al_load_bitmap("blocoDoTrabalho1.bmp");
    blocos[1] = al_load_bitmap("blocoDoTrabalho2.bmp");
    blocos[2] = al_load_bitmap("blocoDoTrabalho3.bmp");
    blocos[3] = al_load_bitmap("blocoDoTrabalho4.bmp");
    blocos[4] = al_load_bitmap("blocoDoTrabalho5.bmp");

    ALLEGRO_BITMAP *player2 = al_load_bitmap("CowboyFeliz.png");
    ALLEGRO_BITMAP *player = al_load_bitmap("BombinhoFalando.png");
    ALLEGRO_BITMAP *personagem1 = al_load_bitmap("BombinhoAndando.png");
    ALLEGRO_BITMAP *armadillo = al_load_bitmap("Armadillo.png");
    ALLEGRO_BITMAP *slime = al_load_bitmap("SlimeParadoDeFrente.png");
    ALLEGRO_BITMAP *coqueiro = al_load_bitmap("coqueiro.png");
    ALLEGRO_BITMAP *personagem3 = al_load_bitmap("personagem3.png");
    ALLEGRO_BITMAP *personagem4 = al_load_bitmap("personagem4.png");
    ALLEGRO_BITMAP *personagem5 = al_load_bitmap("personagem5.png");
    ALLEGRO_BITMAP *personagem6 = al_load_bitmap("personagem6.png");

    al_start_timer(timer);

    while(!done)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        ALLEGRO_EVENT_TYPE tipoEvento=events.type;
        switch(tipoEvento)
        {
        case ALLEGRO_EVENT_TIMER:
        {
            redesenha = true;
            break;
        }
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
        {
            done = true;
            break;
        }
        case ALLEGRO_EVENT_KEY_DOWN:
        {
            int tecla = events.keyboard.keycode;
            switch(tecla)
            {
            case ALLEGRO_KEY_UP:
            {
                keys[UP] = true;
                break;
            }
            case ALLEGRO_KEY_DOWN:
            {
                keys[DOWN] = true;
                break;
            }
            case ALLEGRO_KEY_LEFT:
            {
                keys[LEFT] = true;
                break;
            }
            case ALLEGRO_KEY_RIGHT:
            {
                keys[RIGHT] = true;
                break;
            }
            }
            break;
        }
        case ALLEGRO_EVENT_KEY_UP:
        {
            int tecla = events.keyboard.keycode;
            switch(tecla)
            {
            case ALLEGRO_KEY_UP:
            {
                keys[UP] = false;
                break;
            }
            case ALLEGRO_KEY_DOWN:
            {
                keys[DOWN] = false;
                break;
            }
            case ALLEGRO_KEY_LEFT:
            {
                keys[LEFT] = false;
                break;
            }
            case ALLEGRO_KEY_RIGHT:
            {
                keys[RIGHT] = false;
                break;
            }
            case ALLEGRO_KEY_ESCAPE:
            {
                done = true;
                break;
            }
            }
            break;
        }
        }
        if(!colisao(posX, posY-keys[UP] * 2))
            posY -= keys[UP] * 2;
        if(!colisao(posX, posY+keys[DOWN] * 2))
            posY += keys[DOWN] * 2;
        if(!colisao(posX - keys[LEFT]*2, posY))
            posX -= keys[LEFT] * 2;
        if(!colisao(posX+keys[RIGHT]*2, posY))
            posX += keys[RIGHT] * 2;

        if(events.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(events.keyboard.keycode)
            {
            case ALLEGRO_KEY_W:
                keys2[W] = true;
                break;
            case ALLEGRO_KEY_S:
                keys2[S] = true;
                break;
            case ALLEGRO_KEY_A:
                keys2[A] = true;
                break;
            case ALLEGRO_KEY_D:
                keys2[D] = true;
                break;
            }
        }
        else if(events.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(events.keyboard.keycode)
            {
            case ALLEGRO_KEY_W:
                keys2[W] = false;
                break;
            case ALLEGRO_KEY_S:
                keys2[S] = false;
                break;
            case ALLEGRO_KEY_A:
                keys2[A] = false;
                break;
            case ALLEGRO_KEY_D:
                keys2[D] = false;
                break;
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            }
        }

        posY2 -= keys2[W] * 2;
        posY2 += keys2[S] * 2;
        posX2 -= keys2[A] * 2;
        posX2 += keys2[D] * 2;
        if (posX2 == posX6 && posY2 == posY6)
        {
            posX6 = -100;
            posY6 = -100;
        }
        if(posX2 == posX5 && posY2 == posY5)
        {
            posX5 = -100;
            posY5 = -100;
        }
        if(posX2 == posX3 && posY2 == posY3){
            posX3 = -100;
            posY3 = -100;
        }

        if(colisaoDoCowboy(posX2, posY2))
        {
            posX2 = -100;
            posY2 = -100;
        }





        if(redesenha)
        {
            drawMap(mapa);

            al_draw_bitmap(player, posX, posY, 0);
            al_draw_bitmap(player2, posX2, posY2, 0);
            al_draw_bitmap(personagem1, 100, 220, 0);
            al_draw_bitmap(armadillo, 100, 400, 0);
            al_draw_bitmap(slime, 70, 390, 0);
            al_draw_bitmap(coqueiro, 155, 390, 0);
            if(posX3 != -100 && posY3 != -100){
                al_draw_bitmap(personagem3, posX3, posY3, 0);
            }
            al_draw_bitmap(personagem4, 500, 300, 0);
            if(posX5 != -100 && posY5 != -100){
                al_draw_bitmap(personagem5, posX5, posY5, 0);
            }
            if (posX6 != -100 && posY6 != -100)
            {
                al_draw_bitmap(personagem6, posX6, posY6, 0);
            };




            al_flip_display();
            redesenha = false;
        }
    }

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);

    return 0;
}


