#include<bits/stdc++.h>
using namespace std;



class Button {

    public:
        virtual void press() = 0;
};

class WindowButton : public Button {
    public: 
         void press(){
            cout<<"Windows Button"<<endl;
        }
};

class MacbookButton : public Button {
    public:
         void press(){
            cout<<"Macbook Button"<<endl;
        }
};

class Text {
    public:
        virtual void showText() = 0;
};

class WindowText : public Text {
    public:
         void showText() {
            cout<<"windows text"<<endl;
        }
       
};

class MacbookText : public Text {
    public:
          void showText() {
            cout<<"MacBook text"<<endl;
        }
};

class Factory {
    public:
        Factory () {
            cout<<"Factory class"<<endl;
        }
        virtual Button* createButton() = 0;
        virtual Text* createText() = 0;
};

class MacFactory : public Factory {
    public:
         Button* createButton() {
            return new MacbookButton();
        }
         Text* createText() {
            return new MacbookText();
        }
};

 class WinFactory : public Factory {
    public:
         Button* createButton() {
            return new WindowButton();
        }
         Text* createText() {
            return new WindowText();
        }
};

class GUIFactory{
    public:
        static Factory* CreateFactory(string ostype){
            if(ostype == "window") {
                return new WinFactory();
            }else {
                return new MacFactory();
            }
        }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif

    string ostype;
    cin>>ostype;

    Factory* osfact = GUIFactory::CreateFactory(ostype);
    Button* button = osfact->createButton();
    button->press();

    Text* text = osfact->createText();
    text->showText();

    return 0;
}
 