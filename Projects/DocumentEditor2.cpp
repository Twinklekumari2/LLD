#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class DocumentElement{
public:
   virtual string render() = 0;
};

class TextElement : public DocumentElement{
public:
    string text;

    TextElement(string t){
        this->text = t;
    }

    string render() override{
        return text;
    }
};

class ImageElement : public DocumentElement{
public:
    string image;

    ImageElement(string path){
        this->image = path;
    }

    string render() override{
        return "Image [" + image + "]";
    }
};

class NewLineElement : public DocumentElement{
public:
      string render() override{
        return "\n";
      }
};

class TabSpaceElement : public DocumentElement{
public: 
     string render() override{
        return "\t";
     }
};

class Document {
private:
    vector<DocumentElement*> documentElement;
public:

    void addElement(DocumentElement* element){
         documentElement.push_back(element);
    }

    string render(){
        string result = "";
        for(auto el : documentElement){
            result += el->render() ;
        }
        return result;
    }
};

class Persistance{
public:
    virtual void save(string data) = 0;    
};

class saveTofile : public Persistance{
public:
    void save(string data) override{
        ofstream file("Document.txt");
        if(file.is_open()){
            file << data << endl;
            file.close();
            cout << "Done : Data is saved to file" << endl;
        }else{
            cout << "Unable to open file for writing" << endl;
        }
    }
};

class saveToDb : public Persistance{
public:
    void save(string data) override {
        cout << "Data Saved" << endl;
    }    
};

class DocumentEditor{
private:
    Document* doc;
    Persistance* db;
    string renderedElement;
public:
    DocumentEditor(Document* document, Persistance* storage){
        this->db = storage;
        this->doc = document;
    }
    void addText(string text){
        doc->addElement(new TextElement(text));
    }

    void addImage(string text){
        doc->addElement(new ImageElement(text));
    }

    void newLine(){
        doc->addElement(new NewLineElement());
    }

    void tabSpace(){
        doc->addElement(new TabSpaceElement());
    }

    string renderDoc(){
        return renderedElement = doc->render();
    }
    
    void save(){
        db->save(renderedElement);
    }
};

int main(){
    Document* document = new Document();
    Persistance* storage = new saveTofile();

    DocumentEditor* documentEditor = new DocumentEditor(document, storage);

    documentEditor->addText("This is my first LLD project");
    documentEditor->addImage("twinkle.jpg");
    documentEditor->newLine();
    documentEditor->tabSpace();
    documentEditor->addText("hey myself twinkle kumari");
    documentEditor->renderDoc();
    documentEditor->save();
    return 0;
}