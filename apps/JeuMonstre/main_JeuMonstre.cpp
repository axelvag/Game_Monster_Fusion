#include <Grapic.h>
using namespace grapic;

const int DIMW = 500*2;
/*const int WIN_DIM_X = 600;
const int WIN_DIM_Y = 500;*/

struct Data
{
    int n;
    //int demo;

    Image imbase1;                                                       //variable d'image
    Image imbase2;
    Image imbase3;
    Image imbase4;

    Image imevol1;
    Image imevol2;
    Image imevol3;


    int etat;       // 0=aucun carre, 1=selection en cours, 2=un carre
};

void init(Data& d)
{
    d.etat = 0;
    //d.demo = 4;

    d.imbase1 = image("data/imagegolembase1.jpg");                     //fais le lien de l'image
    d.imbase2 = image("data/imagegolembase2.jpg");
    d.imbase3 = image("data/imagegolembase3.jpg");
    d.imbase4 = image("data/imagegolembase4.jpg");

    d.imevol1 = image("data/imagegolemevol1.jpg");
    d.imevol2 = image("data/imagegolemevol2.jpg");
    d.imevol3 = image("data/imagegolemevol3.jpg");
}

/*int caseToPixel(Data& d, int c)
{
    return (d.n-c) * WIN_DIM_Y/d.n;
}


void menu(Data& d)
{
    if (isMousePressed(SDL_BUTTON_LEFT))
    {
        int x, y;
        mousePos(x, y);
        if (x>WIN_DIM_X-100)
        {
            d.demo = d.n -1-y / (WIN_DIM_Y/d.n);
        }
    }
    fontSize(20);                                           // Change the default size of the font
    color(255, 0, 0);                                           // Change the default color (the color of the pen)
    grid(WIN_DIM_X-100,0,WIN_DIM_X-1,WIN_DIM_Y, 1, d.n);
    color(0,255,124);
    rectangleFill( WIN_DIM_X-99, caseToPixel(d,d.demo)+1, WIN_DIM_X-2, caseToPixel(d,d.demo+1)-2 );
    color(0, 0, 0);                                           // Change the default color (the color of the pen)
    int i;
    for(i=0;i<d.n;++i)
    {
        print(WIN_DIM_X-100+10, caseToPixel(d,i+1)+20, "Demo");
        print(WIN_DIM_X-100+70, caseToPixel(d,i+1)+20, i);
    }
}*/

void draw(Data& d)
{
    int x,y;

    print(350,650,"FUSIONNE DEUX MONSTRES");


    image_draw( d.imbase1, 50*2, 370*2, 100, 100);                          //affiche image
    image_draw( d.imbase2, 160*2, 370*2, 100, 100);
    image_draw( d.imbase3, 270*2, 370*2, 100, 100);
    image_draw( d.imbase4, 380*2, 370*2, 100, 100);

    if (d.etat)
        {
        image_draw( d.imevol1, 220*2, 200*2, 100, 100);
        }

    if ((isMousePressed(SDL_BUTTON_LEFT)) && (x>10) && (y>10) && (x<800) && (y<800))//(x>100) && (y>740) && (x<150) && (y<800))
    {

        int x,y;
        mousePos(x, y);
        if (d.etat!=1)
        {
            d.etat = 1;
        }

    }
    else
    {
    if (d.etat==1)
    {
        d.etat=2;
    }

    }
}

    //image_draw( d.imevol1, 220*2, 200*2, 100, 100);
    //image_draw( d.imevol2, 220*2, 200*2, 100, 100);
    //image_draw( d.imevol3, 220*2, 200*2, 100, 100);



/*void drawevol1(Data& d)
{
    image_draw( d.imevol1, 220*2, 200*2, 100, 100);
}*/

int main(int , char** )
{
    Data dat;
    //menu(dat);
    bool stop=false;
	winInit("Tutorials", DIMW, DIMW);
	init(dat);
    backgroundColor( 100, 100, 200 );

	while( !stop )
    {
        winClear();
        draw(dat);
        stop = winDisplay();
    }
    winQuit();
	return 0;
}
