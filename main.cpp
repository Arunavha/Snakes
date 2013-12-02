#include<iostream.h>
#include<conio.h>
#include<windows.h>
#include<winuser.h>

const char DOWN='s',UP='w',LEFT='a',RIGHT='d';

class SnakePiece{
private:
short is_init;
int pX;
int pY;
char shape;

public:
class UninitialisedException{
public:
UninitialisedException(){cerr<<"The object is not initialised.";}
};
SnakePiece(){}
SnakePiece(int x,int y,char c):pX(x),pY(y),shape(c){
is_init=1;
}
void init_piece(int x,int y,char c){
pX=x;
pY=y;
shape=c;
is_init=1;
}
int getX(){
is_initf();
return pX;
}
int getY(){
is_initf();
return pY;
}
void setX(int i){
is_initf();
pX=i;
}
void setY(int i){
is_initf();
pY=i;
}

void setShape(char i){
shape=i;
}
void is_initf(){
if(!is_init)throw UninitialisedException();
}
void display(){
is_initf();
cout<<"X: "<<pX<<" Y: "<<pY<<" shape: "<<shape<<"\n";
}
void paint(int newX,int newY){
is_initf();
gotoxy(getX(),getY()); cout<<" \b";
gotoxy(newX,newY); cout<<shape<<"\b";
setX(newX); setY(newY);
}
void repaint(){
is_initf();
gotoxy(getX(),getY());cout<<shape<<"\b";
}
};

class Snake{
private:
char s_dir;
int tX,tY,tX1,tY1;
int max;
SnakePiece s[200];
SnakePiece head;
void init(){
head.init_piece(wherex(),wherey(),'O');
head.repaint();
for(int i=0;i<max;i++){
s[i].init_piece(wherex(),wherey()+1,'*');
s[i].repaint();
if(i==max-1){ //this if is for test purposes only
s[i].init_piece(wherex(),wherey()+1,'X');
s[i].repaint();
}
}
gotoxy(head.getX(),head.getY());
}
public:
Snake():max(20),s_dir(UP){
init();
}
void display(){
cout<<"Direction of snake is: "<<s_dir<<endl; head.display();
for(int i=0;i<max;i++){
s[i].display();
}
}

void snake_down(){
if(s_dir==UP)snake_up();
else{
tX=head.getX(); tY=head.getY();
if((head.getY()+1)>23)head.setY(0);
head.paint(head.getX(),head.getY()+1);
for(int i=0;i<max;i++){
if(i==(max-1)){
s[i].paint(tX,tY);
}
tX1=s[i].getX();tY1=s[i].getY();
s[i].setX(tX);s[i].setY(tY);
tX=tX1;tY=tY1;
if(i==0){
s[i].repaint(); 
} 
}
s_dir=DOWN;
}

}

void snake_up(){
if(s_dir==DOWN)snake_down();
else{
tX=head.getX(); tY=head.getY();
if((head.getY()-1)<1)head.setY(23);
head.paint(head.getX(),head.getY()-1);
for(int i=0;i<max;i++){
if(i==(max-1)){
s[i].paint(tX,tY);
}
tX1=s[i].getX();tY1=s[i].getY();
s[i].setX(tX);s[i].setY(tY);
tX=tX1;tY=tY1;
if(i==0){
s[i].repaint();
}
}
s_dir=UP;
}

}

void snake_left(){
if(s_dir==RIGHT)snake_right();
else{
tX=head.getX(); tY=head.getY();
if((head.getX()-2)<1)head.setX(79);
head.paint(head.getX()-2,head.getY());
for(int i=0;i<max;i++){
if(i==(max-1)){
s[i].paint(tX,tY);
}
tX1=s[i].getX();tY1=s[i].getY();
s[i].setX(tX);s[i].setY(tY);
tX=tX1;tY=tY1;
if(i==0){
s[i].repaint();
}
}
s_dir=LEFT;
}

}

void snake_right(){
if(s_dir==LEFT)snake_left();
else{
tX=head.getX(); tY=head.getY();
if((head.getX()+2)>79)head.setX(1);
head.paint(head.getX()+2,head.getY());
for(int i=0;i<max;i++){
if(i==(max-1)){
s[i].paint(tX,tY);
}
tX1=s[i].getX();tY1=s[i].getY();
s[i].setX(tX);s[i].setY(tY);
tX=tX1;tY=tY1;
if(i==0){
s[i].repaint();
}
}
s_dir=RIGHT;
}

}

void snake_move(char dir){
if(dir==LEFT)snake_left();
if(dir==RIGHT)snake_right();
if(dir==UP)snake_up();
if(dir==DOWN)snake_down();
}
};

int main(){
char last_move=UP;
clrscr();
gotoxy(wherex()+20,wherey()+20);
Snake s;
while(1){
if (GetAsyncKeyState(VK_DOWN) == -32767){
//cout<<"DOWN";
s.snake_move(DOWN);
last_move=DOWN;
}
if (GetAsyncKeyState(VK_UP) == -32767){
//cout<<"UP";
s.snake_move(UP);
last_move=UP;
}

if (GetAsyncKeyState(VK_LEFT) == -32767){
//cout<<"LEFT";
s.snake_move(LEFT);
last_move=LEFT;
}

if (GetAsyncKeyState(VK_RIGHT) == -32767){
//cout<<"RIGHT";
s.snake_move(RIGHT);
last_move=RIGHT;
}else{
s.snake_move(last_move);
}

Sleep(10); //Speed of snake
}

}

class Wall{ //At this point I realise that there should have been a class called 'GameObject'. Anyways, this will still work.
private:
short is_init;
int pX;
int pY;
char shape;

public:
class UninitialisedException{
public:
UninitialisedException(){cerr<<"The object is not initialised.";}
};
Wall(){}
Wall(int x,int y,char c):pX(x),pY(y),shape(c){
is_init=1;
}
void init_piece(int x,int y,char c){
pX=x;
pY=y;
shape=c;
is_init=1;
}
int getX(){
is_initf();
return pX;
}
int getY(){
is_initf();
return pY;
}
void setX(int i){
is_initf();
pX=i;
}
void setY(int i){
is_initf();
pY=i;
}

void setShape(char i){
shape=i;
}
void is_initf(){
if(!is_init)throw UninitialisedException();
}
void display(){
is_initf();
cout<<"X: "<<pX<<" Y: "<<pY<<" shape: "<<shape<<"\n";
}
void paint(int newX,int newY){
is_initf();
gotoxy(getX(),getY()); cout<<" \b";
gotoxy(newX,newY); cout<<shape<<"\b";
setX(newX); setY(newY);
}
void repaint(){
is_initf();
gotoxy(getX(),getY());cout<<shape<<"\b";
}
}; //Wall is still under works
