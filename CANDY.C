#include<stdio.h>
#include<conio.h>
void main(){
	int candyX=40,candyY=5,candy2X=30,candy2Y=2,boxX=40,boxY=14,score=0,lifeline=3,d,f;
	char ch;
	textbackground(BLUE);
	start:
	clrscr();
	gotoxy(60,5);
	cprintf("Score=%d",score);
	gotoxy(60,6);
	cprintf("Life line=%d",lifeline);
	gotoxy(candyX,candyY);
	textcolor(YELLOW);
	cprintf("0");
	gotoxy(candy2X,candy2Y);
	textcolor(GREEN);
	cprintf("0");
	gotoxy(boxX,boxY);
	textcolor(CYAN);
	cprintf("#");
	gotoxy(boxX+7,boxY);
	cprintf("#");
	gotoxy(boxX,boxY+1);
	cprintf("########");
	if(kbhit()){
			ch=getch();
			switch(ch){
				case 'a':if(boxX>1){
					boxX -=2;
					}
					break;
				case 'A':if(boxX>1){
					boxX -= 2;
					}
					break;
				case 'd':if(boxX<73){
					boxX += 2;
					}
					break;
				case 'D':if(boxX<73){
					boxX +=2;
					}
					break;
				case 'x':exit(0);
			}
	}
			candyY++ && candy2Y++;
			if(candyY==14 || candy2Y==14){
				d=candyX-boxX;
				f=candy2X-boxX;
				if(d>=1 && d<=6 || f>=1 && f<=6){
					score++;
				}else{
					lifeline--;
					if(lifeline==0){
						clrscr();
						gotoxy(40,13);
						textcolor(RED);
						sound(200);
						delay(200);
						nosound();
						cprintf("GAME OVER");
						getch();
						exit(0);
					}
				}
				candyY=1;
				candy2Y=1;
				candyX=rand()%80+1;
				candy2X=rand()%80+1;
			}
			delay(200);
			goto start;
}