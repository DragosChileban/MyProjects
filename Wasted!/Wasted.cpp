#include <bits/stdc++.h>
using namespace std;

char table[11][11];
int run_x,run_y,block_x,block_y,menu_key;

void tableinit() {
    int rand_x,rand_y;
    rand_x=rand() % 2 + 5;
    rand_y=rand() % 2 + 5;
    for(int i=0;i<=11;i++) {
        table[i][0]='0';
        table[i][11]='0';
        table[0][i]='0';
        table[11][i]='0';
    }
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
            table[i][j]='-';
    table[rand_x][rand_y]='#';
    run_x=rand_x;
    run_y=rand_y;
}

void tableprint() {
    cout<<"   1 2 3 4 5 6 7 8 9 10"<<'\n';
    for(int i=1;i<=10;i++) {
        cout<<i;
        if(i!=10)
            cout<<"  ";
        else
            cout<<" ";
        for(int j=1;j<=10;j++)
            cout<<table[i][j]<<" ";
        cout<<'\n';
    }
}

bool isOver(int x,int y) {
    if(table[x-1][y-1]=='0' && table[x-1][y]=='0' && table[x-1][y+1]=='0' && table[x][y+1]=='0' && table[x+1][y+1]=='0' && table[x+1][y]=='0' && table[x+1][y-1]=='0' && table[x][y-1]=='0')
        return 1;
    return 0;
}

void nextMove() {
    if(table[run_x-1][run_y-1]=='-') {
        run_x-=1;run_y-=1;
    } else
    if(table[run_x-1][run_y]=='-') {
        run_x-=1;
    } else
    if(table[run_x-1][run_y+1]=='-') {
        run_x-=1;run_y-=1;
    } else
    if(table[run_x][run_y+1]=='-') {
        run_y+=1;
    } else
    if(table[run_x+1][run_y+1]=='-') {
        run_x+=1;run_y+=1;
    } else
    if(table[run_x+1][run_y]=='-') {
        run_x+=1;
    } else
    if(table[run_x+1][run_y-1]=='-') {
        run_x+=1;run_y-=1;
    } else
    if(table[run_x][run_y-1]=='-') {
        run_y-=1;
    }

}

void gameloop() {
    int score=0;
    while(isOver(run_x,run_y)==0) {
        tableprint();
        cout<<'\n'<<"YOUR SCORE: "<<score<<'\n';
        cout<<"Your next obstacle's coordonates (x,y): ";
        do {
        cin>>block_x>>block_y;
        }while((block_x == run_x && block_y == run_y) || (table[block_x][block_y]=='0'));
        table[block_x][block_y]='0';
        //system("PAUSE");
        table[run_x][run_y]='-';
        nextMove();
        table[run_x][run_y]='#';
        score++;
        system("CLS");
    }
    cout<<"#      #    #####      #     #      #                     #   #    #       #    ##"<<'\n';
    cout<<" #    #    #     #     #     #       #         #         #         # #     #    ##"<<'\n';
    cout<<"  #  #    #       #    #     #        #       # #       #     #    #  #    #    ##"<<'\n';
    cout<<"   ##    #         #   #     #         #     #   #     #      #    #   #   #    ##"<<'\n';
    cout<<"   ##     #       #    #     #          #   #     #   #       #    #    #  #    ##"<<'\n';
    cout<<"   ##      #     #     #     #           # #       # #        #    #     # #      "<<'\n';
    cout<<"   ##       #####       #####             #         #         #    #       #    ##"<<'\n';
    cout<<'\n'<<"YOUR SCORE IS: "<<score<<'\n';
    system("PAUSE");
}
 void rules() {
    cout<<"THE GAME RULES ARE SIMPLE: "<<'\n';
    cout<<"TRY TO SURROUND THE FUGITIVE (MARKED BY # SYMBOL) BY PLACING OBSACLES ON THE MAP."<<'\n';
    cout<<"YOU WIN THE GAME WHEN THE FUGITIVE HAS NO MORE SPACE TO RUN!"<<'\n'<<'\n';
    system("PAUSE");
 }

int startmenu() {
    cout<<"#       #       #     #       #####    #######   ######   ####"<<'\n';
    cout<<" #     # #     #     # #     #            #      #        #   #"<<'\n';
    cout<<"  #   #   #   #     #   #     #####       #      ######   #    #"<<'\n';
    cout<<"   # #     # #     #######         #      #      #        #   #"<<'\n';
    cout<<"    #       #     #       #   #####       #      ######   ####    by Dragos Chileban"<<'\n';
    cout<<'\n';
    cout<<"1.PLAY"<<'\n';
    cout<<"2.RULES"<<'\n';
    cout<<"3.EXIT"<<'\n';
    do {
        cin>>menu_key;
    }while(menu_key<1 || menu_key>3);

}

void leave() {
    cout<<"######   #      #   ######    ##"<<'\n';
    cout<<"#     #   #    #    #         ##"<<'\n';
    cout<<"#     #    #  #     #         ##"<<'\n';
    cout<<"######      ##      ######    ##"<<'\n';
    cout<<"#     #     ##      #         ##"<<'\n';
    cout<<"#     #     ##      #           "<<'\n';
    cout<<"######      ##      ######    ##"<<'\n';
    cout<<'\n'<<"And thank you for playing :)"<<'\n'<<'\n';
    system("PAUSE");
}

int main() {
    int key;
    tableinit();
    do{
        system("CLS");
        key=startmenu();
        switch(key) {
            case 1 : system("CLS");gameloop();break;
            case 2 : system("CLS");rules();system("cls");break;
            case 3 : system("CLS");leave();break;
        }

    }while(key!=3);


}
