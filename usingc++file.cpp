//Project is designed using OBJECT ORIENTED PROGRAMMING LANGUAGE C++
#include<stdlib.h>//This library is used by me to use rand() and srand() function to generate random number.
#include<string>
#include<iostream>
#include<fstream>
#include <conio.h>//Used because it contains getch() function which is used in password code.
#include<exception>
#include <windows.h>//Used because it contains beep function to create sounds of different frequencies.
#include<ctime>
using namespace std;
class basegame{
public:
char game_name[50];
char player_name[100];
float moneycome,moneygo;
char square[10]={'o','1','2','3','4','5','6','7','8','9'};
//static float netprofit;
float netprofit;
float MONEY()
{
    float money;
    a:
    cout<<"\nHow much money(Rs) do you want to bet?";
    cin>>money;
    if(!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"wrong input\n\n\a";
        goto a;
        }
        return money;
}
int rand_value1(int sleeptime, int maxrand)
{
    int roll;
    time_t t;
    Sleep(sleeptime);
    srand((unsigned)time(&t));
    roll=rand()%maxrand+1;
    return roll;
}
int rand_value2(int sleeptime, int maxrand)
{
    int roll;
    time_t t;
    Sleep(sleeptime);
    srand((unsigned)time(&t));
    roll=rand()%maxrand+2;
    return roll;
}
void luck(int *a)
{
    system("color 4");
    switch(*a)
    {
    case 2:
        cout<<"got ladder\n";
        *a=38;
        cout<<"reached at"<<*a<<endl;
        break;
    case 4:
        cout<<"got ladder\n";
        *a=14;
        cout<<"reached at"<<*a<<endl;
        break;
    case 9:
        cout<<"got ladder\n";
        *a=31;
        cout<<"reached at"<<*a<<endl;
        break;
    case 45:
        cout<<"snakes mouth\n";
        *a=15;
        cout<<"reached at"<<*a<<endl;
        break;
    case 50:
        cout<<"snakes mouth\n";
        *a=11;
        cout<<"reached at"<<*a<<endl;
        break;
    case 52:
        cout<<"got ladder\n";
        *a=88;
        cout<<"reached at"<<*a<<endl;
        break;
    case 62:
        cout<<"snakes mouth\n";
        *a=57;
        cout<<"reached at"<<*a<<endl;
        break;
    case 80:
        cout<<"got ladder\n";
        *a=99;
        cout<<"reached at"<<*a<<endl;
        break;
    case 92:
        cout<<"snakes mouth\n";
        *a=53;
        cout<<"reached at"<<*a<<endl;
        break;
    case 98:
        cout<<"snakes mouth\n";
        *a=8;
        cout<<"reached at"<<*a<<endl;
        break;
    }
}
void board()
{
    system("color 5");
    cout<<"\n\n\tTic Tac Toe\n\n";
    cout<<"Player 1 (X)  -  Player 2 (O)\n\n\n";
    cout<<"     |     |     \n";
    cout<<"  "<<square[1]<<"  |  "<<square[2]<<"  |  "<<square[3]<<"\n" ;
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<<"\n" ;
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<square[7]<<"  |  "<<square[8]<<"  |  "<<square[9]<<"\n" ;
    cout<<"     |     |     \n\n";
};


int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if(square[3] == square[5] && square[5] == square[7])
        return 1;

    else if(square[1]!='1'&&square[2]!='2'&& square[3]!= '3'&&square[4]!='4'&&square[5]!='5'&&square[6]!='6'&&square[7]!='7'&&square[8]!='8'&&square[9]!='9')
        return 0;
    else
        return  -1;
}

void save(int m){
    ofstream show;
    savelabel:
    show.open("1funfair.txt",ios::app);
    if (show.is_open()){}
    else
    {
    goto savelabel;
    }
    show<<endl<<game_name<<"\t\t"<<player_name<<"\t\t\t"<<m<<"\t\t\t\t"<<moneycome<<"\t\t\t\t\t"<<moneygo<<endl;
    show.close();
    }
};




class game:public basegame
{
    public:
    void NumGuess()
    {
        system("color 9F");
        cout<<"\n********WELCOME TO NUMBER GUESSING GAME";
        strcpy(game_name,"NUMBER GUESSING GAME");
        cout<<"\nRULES:";
        cout<<"\n1-If you guess the number in 2 or less than 2 chances then you will win and you will get 50 percent increase on your bet money";
        cout<<"\n2-If you guess the number in more than 3 chances then , you will loose both your bet money and game";
        cout<<"\n3-If you guess the number in 3 chances then game will be a draw and you will get half of your bet money";
        float m=MONEY();
        int w_n;
        w_n=rand_value1(0,10);
        int guess=1,num;
        b:
        cout<<"\nGuess a number from 1 to 10 : ";
        cin>>num;
        if(num<1||num>10||!cin)
        {
            cin.clear();
            fflush(stdin);
            Beep(300,500);
            cout<<"wrong input\n\n\a";
            goto b;
        }
        while(1)
            {
            if(num==w_n)
                {
                cout<<"\nYou won";
                cout<<"\nYou guess this number in "<<guess<<" times";
                break;
                }
            else
                {
                if(num<w_n)
                    cout<<"\ntoo low";
                else
                {
                    cout<<"\ntoo high";
                }
                c:
                cout<<"\ntry to guess again : ";
                cin>>num;
                if(num<1||num>10||!cin)
                    {
                    cin.clear();
                    fflush(stdin);
                    Beep(300,500);
                    cout<<"wrong input\n\n\a";
                    goto c;
                    }
                guess++;
                }

            }
        if(guess>3)
                {
                cout<<"\n\nfinally you loose because you guess the number in more than 2 times ";
                cout<<"\nso,you loose your rupees "<<m;
                moneycome=m;
                moneygo=0;
                }

        else if(guess==3)
            {
            cout<<"\n\nfinally game draws";
            cout<<"\nyou loose your half money,so you will get rupees "<<m/2;
            moneycome=m/2;
            moneygo=0;
            }
        else
            {
            cout<<"\n\nfinally you won";
            cout<<"\nyou won rupees "<<m+(m/2);
            moneycome=0;
            moneygo=m/2;
            }
netprofit+=(moneycome-moneygo);
save(m);
}


void Snake_Ladder()
{
    strcpy(game_name,"SNAKE AND LADDER GAME");
    system("color 3F");
    cout<<"***WELCOME TO SNAKE AND LADDER GAME computer vs you***\n";
    cout<<"\nRULES:";
    cout<<"\n1-Both will start from 1\nif You reach at 100 before computer then you will win and if computer reached at 100 before you then computer will win\n";
    cout<<"2-if you will win then you will get 50 percent increase on your bet money";
    cout<<"\n2-If you loss then you will loss your bet money";
    cout<<"\n3-If you accept loss and press 2 then game will be a draw and you will get half of your bet money";
    float m=MONEY();
    int a[10][10]={100,99,98,97,96,95,94,93,92,91,81,82,83,84,85,86,87,88,89,90,80,79,78,77,76,75,74,73,72,71,61,62,63,64,65,66,67,68,69,70,60,59,58,57,56,55,54,53,52,51,41,42,43,44,45,46,47,48,49,50,40,39,38,37,36,35,34,33,32,31,21,22,23,24,25,26,27,28,29,30,20,19,18,17,16,15,14,13,12,11,1,2,3,4,5,6,7,8,9,10};
    int choice=1,you=1,comp=1,i,j;
    cout<<"10X10 grid is\n";
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            cout<<a[i][j]<<"\t";
        }
         cout<<"\n";
    }
    int check=0;
    while(choice!=2&&you!=100&&comp!=100)
    {
        p:
        cout<<"\nenter your choice: 1 to roll the dice , 2 to exit this game if you accept loss:";
        cin>>choice;
        if(choice<1||choice>2||!cin){
            cin.clear();
            fflush(stdin);
            Beep(300,500);
            cout<<"wrong input\n\a";
            goto p;
        }
        if(choice==1)
        {
            Beep(120,800);
            int a=rand_value1(10,6);
            cout<<"\ndice:"<<a<<"\n";
            if((you+a)<=100)
            {

            you+=a;
            cout<<"you: "<<you<<"\n";
            int *p=&you;
            luck(p);
            if(you==100)
            {
                cout<<"you won the match";
                cout<<"\nyou won rupees "<<m+(m/2);
                moneycome=0;
                moneygo=m/2;
                check++;
                break;
            }
            }
            else
            {
                cout<<"you can not move forward at this chance\n";
            }
            fflush(stdin);
            int b=rand_value2(20,7)-1;
            if(b==7){b--;}
            cout<<"\ndice:"<<b<<"\n";
            if((comp+b)<=100)
            {
            comp+=b;
            cout<<"computer:"<<comp<<"\n";
            int *q=&comp;
            luck(q);
            if(comp==100)
            {
                cout<<"computer won the match";
                cout<<"\nso,you loose your rupees "<<m;
                moneycome=m;
                moneygo=0;
                check++;
                break;
            }
            }
            else{
                cout<<"computer can not move forward at this chance\n";
            }
        }
    }
    if(check==0)
    {
        cout<<"you accepted loss";
        cout<<"\nso you loose your half money,so you will get rupees "<<m/2;
        moneycome=m/2;
        moneygo=0;
    }
netprofit+=(moneycome-moneygo);
save(m);
}

void SPC()
{
    system("color 0A");
        strcpy(game_name,"StonePaperScissorGame");
        system("color 2F");
        cout<<"\n\nWELCOME TO STONE,PAPER,SCISSOR GAME";
        cout<<"\n\nRULES:";
        cout<<"\n1-You have only 3 chances";
        cout<<"\n2-If you won,you will get 50 percent increased of your bet money";
        cout<<"\n3-If you loose , you will loose your bet money";
        cout<<"\n4-If game draws,you will get half of your bet money";
        float m=MONEY();
        getchar();
        int pc_points=0;
        int your_points=0;
        int i=0;
        char a[]="spc";
        while(i<=2)
            {
            int b=rand_value1(1,2);
            char c;
            cout<<"\n\nEnter s for stone , p for paper and c for scissor:";
            cin>>c;
            fflush(stdin);
            if(c!='s'&&c!='p'&&c!='c')
            {
                Beep(300,500);
                cout<<"\nyou has given wrong input\a";
                continue;
            }
            if(a[b]==c)
                {
                cout<<"\ngame draw because computer chooses "<<a[b];
                cout<<"\nyour points till now= "<<your_points<<" ,computer points till now="<<pc_points;
                } 
            else if((a[b]=='c'&&c=='p')||(a[b]=='s'&&c=='c')||(a[b]=='p'&&c=='s'))
                {
                cout<<"\nyou loose because computer chooses "<<a[b];
                pc_points++;
                cout<<"\nyour points till now= "<<your_points<<" ,computer points till now="<<pc_points;
                }
            else
                {
                cout<<"\nyou won because computer chooses "<<a[b];
                your_points++;
                cout<<"\nyour points till now="<<your_points<<"computer points till now="<<pc_points;
                }
            i++;
            }
        cout<<"\n\noverall your points="<<your_points;
        cout<<"\noverall computer points="<<pc_points;
        if(pc_points>your_points)
            {
            cout<<"\n\nfinally you loose";
            cout<<"\nyou loose your rupees "<<m;
            moneycome=m;
            moneygo=0;
            }
        else if(pc_points==your_points)
            {
            cout<<"\n\nfinally game draws";
            cout<<"\nyou loose your half money,so you will get rupees "<<m/2;
            moneycome=m/2;
            moneygo=0;
            }
        else
            {
            cout<<"\nfinally you won";
            cout<<"\nyou win rupees "<<m+(m/2);
            moneycome=0;
            moneygo=m/2;
            }
netprofit+=(moneycome-moneygo);
save(m);
}
void TTT()
{
    strcpy(game_name,"  TIC TAC TOE GAME    ");
    system("color FD");
    cout<<"\n\nWELCOME TO TIC TAC TOE GAME";
        cout<<"\n\nRULES:You are player 1";
        cout<<"\n1-If you won,you will get 50 percent increased of your bet money";
        cout<<"\n2-If you loose , you will loose your bet money";
        cout<<"\n3-If game draws,you will get half of your bet money";
        float m=MONEY();
    int player=1,i,choice;
    char mark;
    do
    {
        board();
        player=(player%2)?1:2;
        k:
        cout<<"\nPlayer "<<player<<" enter a number:";
        cin>>choice;
        if(choice<1||choice>9||!cin){
            cin.clear();
            fflush(stdin);
            Beep(300,500);
            cout<<"Wrong input!";
            goto k;
        }
        getchar();
        mark=(player==1)?'X':'O';
        if(choice==1&&square[1]=='1')
            square[1]=mark;
        else if(choice==2&&square[2]=='2')
            square[2]=mark;
        else if(choice==3&&square[3]=='3')
            square[3]=mark;

        else if(choice==4&&square[4]=='4')
            square[4]=mark;
        else if(choice==5&&square[5]=='5')
            square[5]=mark;
        else if(choice==6&&square[6]=='6')
            square[6]=mark;
        else if(choice==7&&square[7]=='7')
            square[7]=mark;
        else if(choice==8&&square[8]=='8')
            square[8]=mark;

        else if(choice==9&&square[9]=='9')
            square[9] = mark;

        else
        {
            cout<<"Invalid move\a ";
            player--;
            getchar();
        }
        i=checkwin();
        player++;
    }while(i ==  - 1);

    board();

    if(i==1)
        {
        int p=player-1;
        if(p==1)
            {
                cout<<"==>\aPlayer "<<p<<" win ";
                cout<<"\nyou win rupees "<<m+(m/2);
                moneycome=0;
                moneygo=m/2;
            }
        else
        {
            cout<<"==>\aPlayer "<<p<<" win ";
            cout<<"\nyou loose your rupees "<<m;
            moneycome=m;
            moneygo=0;

        }
        }
    else
        {
        cout<<"==>\aGame draw";
        cout<<"\nyou loose your half money,so you will get rupees"<<m/2;
        moneycome=m/2;
        moneygo=0;
        }
    square[0]='0';
    square[1]='1';
    square[2]='2';
    square[3]='3';
    square[4]='4';
    square[5]='5';
    square[6]='6';
    square[7]='7';
    square[8]='8';
    square[9]='9';
    netprofit+=(moneycome-moneygo);
    save(m);
}
void GUESS_COUNTRY()
{
    strcpy(game_name,"COUNTRY GUESSING GAME");
    system("color 4F");
    cout<<"\n***WELCOME TO COUNTRY GUESSING GAME***";
    cout<<"\nRULES:\n";
    cout<<"1:All names are in small letters\n";
    cout<<"2:-If you guess in only one chances then you will won and you will get 50 percent increased of your bet money\n";
    cout<<"3-If you guess in two chances then game will draw and you will get half of your bet money\n";
    cout<<"4:-If you  need more than two chances to guess then you will lose game and you will lose your bet money\n\n";
    float m=MONEY();
    int b;
    char *a[]={"india","america","china","pakistan","australia","nepal","bhutan"};
    b=rand_value1(0,7)-1;
    char name[30],n[30],na[30];
    strcpy(name,a[b]);
    strcpy(n,name);
    strcpy(na,n);
    char c[30],x;
    int i;
    cout<<"\n\n";
    for(i=0;name[i]!='\0';i++)
        {
        c[i]='*';
        cout<<"*";
        }
    getchar();
    for(i=0;i<2;i++)
        {
        cout<<"\nguess a letter:";
        cin>>x;
        fflush(stdin);
        for(int j=0;name[j]!='\0';j++)
            {
                if(name[j]==x)
                    {
                    c[j]=x;
                    name[j]='*';
                    }
            }
        for(i=0;name[i]!='\0';i++)
            {
            cout<<c[i];
            }
        }
    char ans[30];
    cout<<"\nenter your guessed name:";
    cin>>ans;
    int j=0;
    for(i=0;n[i]!='\0';i++)
            {
            if(ans[i]==n[i])
                {
                continue;
                }
            else
                {
                j++;
                break;
                }
            }

        if(j==0)
            {
            cout<<"\nfinally you won";
            cout<<"\nyou won rupees "<<(m+m/2);
            moneycome=0;
            moneygo=m/2;
            }
        else
            {
            cout<<"\nyour guess is wrong";
            cout<<"\nguess a letter , its your last chance:";
            cin>>x;
            getchar();
            for(int k=0;n[k]!='\0';k++)
                {
                    if(n[k]==x)
                        {
                            c[k]=x;
                            n[j]='*';
                        }
                }
            for(i=0;n[i]!='\0';i++)
                {
                cout<<c[i];
                }
            cout<<"\nenter your guessed name:";
            cin>>ans;
            getchar();
            j=0;
            for(i=0;name[i]!='\0';i++)
            {
            if(ans[i]==na[i])
                {
                continue;
                }
            else
                {
                j++;
                break;
                }
            }

            if(j==0)
            {
                cout<<"\nfinally game draws";
                cout<<"\nyou loose your half money,so you will get rupees "<<m/2;
                moneycome=m/2;
                moneygo=0;
            }
            else
            {
                cout<<"\ncorrect guess is "<<a[b];
                cout<<"\nfinally you loose";
                cout<<"\nyou loss your rupees "<<m;
                moneycome=m;
                moneygo=0;
            }
            }
netprofit+=(moneycome-moneygo);
save(m);
}
void MAGIC()
{
    strcpy(game_name,"     MAGIC GAME     ");
    system("color 02");
    float c;
    cout<<"WELCOME TO MAGIC GAME\n";
    cout<<"This game is free\n";
    cout<<"I will guess how much rupees you will left with you if you follow all steps very carefully.\n";
    cout<<"Rule:Press enter if you have done the given task.\n";
    cout<<"1:Think how much rupees you are having wih you.\n";
    getchar();
    cout<<"2:Let same amount is given to you by your friend so make total money you are having now ,in your mind.\n";
    getchar();
    c=rand_value1(0,500)+1;
    cout<<"3:Let i am giving you "<<c<<" rupees, so make total in your mind.\n";
    getchar();
    cout<<"4:Give half rupees for charity and caculate money you are having now.\n";
    getchar();
    cout<<"5:Give your friends rupees to your friend.\n";
    getchar();
    cout<<"You left "<<c/2<<" rupees with you.\n";
    cout<<"now think how i guess this.\n";
float m=0;
moneycome=0;
moneygo=0;
netprofit+=(moneycome-moneygo);
save(m);
} 
};
int main(){
    system("color 70");
    ofstream show;
    myfilelabel:
    show.open("1funfair.txt",ios::app);
    if (show.is_open()){}
    else
    {
    goto myfilelabel;
    }
    show<<"\n        Game\t\t    Player_name  \t\tBet_money\t\t  Money_come_to_owner\t\t\tMoney_go_from_owner\n";
    show.close();
    char mypassword[]="n123";
 START:
    system("cls");
    cout<<"\nEnter Password  : ";
    char pass[32];//to store password.
    int i = 0;
    char a;
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';
            break;
        }
    }
    fflush(stdin);
     if(strlen(pass)==strlen(mypassword)){
        int len=strlen(pass);
        int i=0;
        while(len){
            if(pass[i]==mypassword[i]){
                i++;
            }
            else{
                Beep(300,500);
                cout<<"\nWRONG PASSWORD!";
                cout<<"\nPress enter to try again";
                getchar();
                goto START;
            }
            len--;
        }
    }
    else{
        Beep(300,500);
        cout<<"\nWRONG PASSWORD!";
        cout<<"\nPress enter to try again";
         getchar();
        goto START;
    }
    game object;
    while(true){
    system("Color E4");
    int x;
    cout<<"\n\n\n************WELCOME TO FUNFAIR GAMES*************\n";
    cout<<"\nEnter your name : ";
    cin>>object.player_name;
    cout<<"\nHello "<<object.player_name;
    q:
    cout<<"\n1:number guessing game\n2:Snake Ladder game\n3:Stone Paper Scissor game\n4:Tic Tac Toe game\n5:Country guessing game\n6:Magic game \n7:exit\nEnter choice:";
    fflush(stdin);
    cin>>x;
    if(x<1||x>7||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"Wrong Choice!";
        goto q;
    }
    system("cls");
    switch(x)
    {
    case 1:
        object.NumGuess();
        break;
    case 2:
        object.Snake_Ladder();
        break;
    case 3:
        object.SPC();
        break;
    case 4:
        object.TTT();
        break;
    case 5:
        object.GUESS_COUNTRY();
        break;
    case 6:
        object.MAGIC();
        break;
    case 7:
        break;
    }
    if(x==7)
    {
        system("color 4");
        cout<<"*********GAME EXIT**********";
        cout<<"\n\nOwners net profit is Rupees "<<object.netprofit;
        cout<<"\n****************************************************************************************************";
        cout<<"\n Press enter to see all players data which is stored in text file...";
        fflush(stdin);
        getchar();
        break;
    }
    }
    fflush(stdin);
    ifstream show1;
    myfilelabelnew:
    show1.open("1funfair.txt");
    if (show1.is_open()){}
    else
    {
    goto myfilelabelnew;
    }
    string line;
    while(show1){
    getline(show1,line);
    cout<<line<<endl;
    }
    show1.close();
    cout<<"\nThis is the data stored in the textfile !";
     return 0;
}
//Respected Arti ma'am and Rupesh sir , i have made this project with great dedication - under your guidance.
//Thanks
