#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class DocumentEditor{
public:
    vector<string> documentElement;
    string renderedDocument;

    void addText(string text){
        documentElement.push_back(text);
    }
    void addImage(string path){
        documentElement.push_back(path);
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            string result = "";
           for(auto element : documentElement){
            if(element.size() > 4 && (element.substr(element.size()-4) == ".jpg" || element.substr(element.size()-4) == ".png")){
                result += "Image [ "+  element + " ] \n";
            }
            else{
                result += element + '\n';
            }
            renderedDocument = result;
           }
        }
        return renderedDocument;
    }

    void saveTofile(){
        ofstream file("document3.txt");
        if(file.is_open()){
            file << renderDocument() << endl;
            file.close();
            cout << "Document saved to document.txt" << endl;
        }else{
            cout << "Unable to open file fro writing" << endl;
        }
    }
};

int main(){
    DocumentEditor* docu = new DocumentEditor();
    docu->addText("Twinkle kumari");
    docu->addImage("twinkle.png");
    docu->addText("i am preparing for interview");
    // docu->renderDocument();
    docu->saveTofile();

    return 0;
}