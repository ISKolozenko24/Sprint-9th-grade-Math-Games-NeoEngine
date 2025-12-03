#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> hang={
" +---+\n     |\n     |\n     |\n    ===",
" +---+\n |   |\n     |\n     |\n    ===",
" +---+\n |   |\n O   |\n     |\n    ===",
" +---+\n |   |\n O   |\n |   |\n    ===",
" +---+\n |   |\n O   |\n/|   |\n    ===",
" +---+\n |   |\n O   |\n/|\\  |\n    ===",
" +---+\n |   |\n O   |\n/|\\  |\n/    |\n    ===",
" +---+\n |   |\n O   |\n/|\\  |\n/ \\  |\n    ==="
};
vector<string> words={
"school","computer","program","science","engine",
"planet","history","winter","matrix","future"
};
void logo(){
cout<<"........................................\n";
cout<<".................HANGMAN................\n";
cout<<"........................................\n\n";
}

int pickWordIndex(int &last){
    last++;
    if(last>=words.size()) last=0;
    return last;
}

int main(){
logo();

int lastWord=-1;
char menuChoice;
while(true){
    cout<<"MENU:\n";
    cout<<"1 - Play\n";
    cout<<"2 - Info\n";
    cout<<"3 - Exit\n";
    cout<<"Choice: ";
    cin>>menuChoice;

    if(menuChoice=='3'){
        cout<<"Bye!\n";
        return 0;
    }
    if(menuChoice=='2'){
        cout<<"\nSimple hangman game.\nGuess letters, don't die.\n\n";
        continue;
    }
    if(menuChoice=='1'){
        int idx = pickWordIndex(lastWord);
        string w = words[idx];
        string g(w.size(),'_');
        vector<char> used;
        int m=0;

        while(m<7 && g!=w){
            cout<<"\n"<<hang[m]<<"\n\n";

            cout<<"Word: ";
            for(char c:g) cout<<c<<" ";
            cout<<"\nUsed: ";
            for(char c:used) cout<<c<<" ";
            cout<<"\nLetter: ";

            char x; cin>>x;
            x=tolower(x);

            bool was=false;
            for(char c:used) if(c==x) was=true;
            if(was){
                cout<<"Already used!\n";
                continue;
            }
            used.push_back(x);

            bool ok=false;
            for(int i=0;i<w.size();i++){
                if(w[i]==x){
                    g[i]=x;
                    ok=true;
                }
            }
            if(!ok){
                m++;
                cout<<"Wrong! "<<m<<"/7\n";
            } else cout<<"Good!\n";
        }
        cout<<"\n"<<hang[m]<<"\n\n";
        if(g==w) cout<<"You win! Word: "<<w<<"\n";
        else cout<<"You lost! Word was: "<<w<<"\n\n";
    }
}
return 0;
}


