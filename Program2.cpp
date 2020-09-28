
#include<iostream>
#include<stdlib.h>
#include <iomanip>
#include <algorithm>
using namespace std;


int Random_Number(int Card){
    int num = rand()% Card;
    return num;
}

void Hand(int arr[],int size){
    for(int i=0; i < size; i++)
    cout << setw(3) << arr[i];
    cout << endl;
}

void Play(){
    int Final_Score = 0;
    int Current = 0;
    int next;
    int index = 0;
    int live[16];
    int dead[16];
    for(int i = 0; i < 16; i++)
        live[i] = i + 1;
    int size = 16;
    char ch;
    while(size > 0){
        sort(live, live + size);
        sort(dead, dead + index);

        cout << "Current score: " << Final_Score << endl;
        cout << "Dead: ";
        Hand(dead, index);
        cout << "Live :";
        Hand(live, size);
        next = Random_Number(size);
        cout << "Next card: " << live[next] ;
        int Play_Score = live[next];
        live[next] = live[size - 1];
        size--;
        dead[next] = dead[index + 1];
        index++;

        if(Play_Score < Current){
            cout << "    Dead\n" << endl;
        }
        else{
            cout << endl;
            cout << "\nTake it [T] or Leave it [L]? ";
            cin >> ch;
            ch = toupper(ch);

        if(ch == 'T'){
            Final_Score += Play_Score;
            Current = Play_Score;
        }
        else if (ch == 'L') {
            dead[index++] = Play_Score;
        }
        else {
            cout << "Invalid entry, please enter [T]ake it or [L]eave it" << endl;
            cin >> ch;
            ch = toupper(ch);
        }

        cout << endl;
      
    }
}
    cout << endl;
    cout << "Your Final Score is : " << Final_Score << endl;

}

int main(){
    char ch = 'Y';
        do{
            Play();
            cout << "Do you want to play again? (y/n): ";
            cin >> ch;
            ch = toupper(ch);
  
}
    while(ch=='Y');
}
