#include <Windows.h>
#include <iostream>
#include<cstdlib>
#include<conio.h>

using namespace std;
 
bool gameover;
int S=20;
int H=20;
int x=S/2;
int y=H/2;
int fruitX;
int fruitY;
int score;


 
enum eDirection
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
eDirection dir;

void getFruitX()
{
    fruitX = 1 + rand()%(S-2);
		 
}

void getFruitY()
{
    fruitY = 1 + rand()%(H-2);		 
}

void Input()
{
	if(_kbhit())
	{
	  	switch (_getch())
	  	{
	  	  case'a':
		    dir = LEFT;
			break;
		  case'd':
		    dir = RIGHT;
		    break;
	      case'w':
	        dir = UP;
	        break;
	      case's':
	        dir = DOWN;
	        break;	    
		}
	}
}


void Logic()
 {
 	if(x==fruitX and y == fruitY)
 	 {
 	   score = score + 10;
	   getFruitX();
	   getFruitY();
	 }
 if(x<1 or x>H-1 or y<1 or y>S-1)
   {
   gameover=true;
   }
   switch(dir)
  {
  	case LEFT:
  		x--;
  		break;
  	case RIGHT:
  		x++;
  		break;
  	case DOWN:
  		y++;
  		break;
  	case UP:
  		y--;
  		break;
  }
}




void Setup()
{
    x=S/2-1;
	y=H/2-1;
    getFruitX();
    getFruitY();
}
	
		
void Draw()
{
	system("cls");
  	for(int i=0;i<S;i++)	
    {
      	cout<<"#";
	}	
	
    cout<<"\n";
    for(int j=0;j<S;j++)
    {	
    	for(int i=0; i<H; i++)	
      	{
      		bool empty = true;
      		
      		if(i==0 or i==S-1)
      		{
      			cout<<"#";
      			empty = false;
			}
      				
      		if(i==x and j==y)
      		{
      			cout<<"O";
      			empty = false;
			}
			
			if(empty == true && i==fruitX and j==fruitY)
      		{
      			cout<<"F";
      			empty = false;
			}
			
      	
      	    if(empty == true)
      			cout<<" ";
				  	
	  	}	
      		    cout<<"\n";
      		    
      		    
      		    
      		   
    }
    
    for(int i=0;i<S;i++)	
    {
      	cout<<"#";
	}	
    cout<<"\n";
    std::cout<<"score ";
    std::cout<<score;
}

	
int main(int argc, char** argv) 
{
    Setup();  
    system("cls");
    while(gameover == false)
    {
    Sleep(100);
	Input();
	Logic();
    Draw();

	}
	
	if(gameover)
	{
		system("cls");
	}
	return 0;
}

