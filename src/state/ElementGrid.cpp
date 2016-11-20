#include "ElementGrid.h"
#include "Element.h"

namespace state{
    

    ElementGrid::ElementGrid (State& s) : ElementList(s) {
        
        this->width=width;
        this->height=height;
    }

    /*bool  const ElementGrid::hasCell (int i, int j) {
        width=this->getWidth();
        height=this->getHeight();
        if (i>=height|| j>=width){
            return false;
        }else {
            return true;
        }
    }*/
    int  ElementGrid::getWidth () const{
        return width;
    }
    int  ElementGrid::getHeight () const{
        return height;
    }
    Element*  ElementGrid::getCell (int i, int j) const{
        return elements.at(i+j*width);
    }
    bool  ElementGrid::isSpace(int i, int j ) const{
        Element* elm=elements.at(i+j*width);
        if (i>=height|| j>=width){
            return 0;//throw runtime_error("la cellule demandee n existe pas");
        } else {
            if (elm->getTypeID()==SPACE){
                return true;
            }else{
                return false;
            }
        }
    }
    void ElementGrid::setCell (int i, int j, Element* e){
        if (i>=height|| j>=width){
            //throw runtime_error("la cellule demandee n existe pas");
        }else{
            elements.at(i+j*width)=e;
        }
    }
    void ElementGrid::load (const char* file_name){
       /* std::ifstream fin(file_name);
        if (!fin.good()){
            throw runtime_error("Cannot_open_file");
        }
        while (true){
        char tmp[0x1000];
        fin.getline(tmp,0x1000);
        if(fin.eof()){
            break;
        }
        if (!fin.good()){
            throw runtime_error("Cannot_read_file");
            
        }
       */
    }
}