/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <typeinfo>
#include <exception>
#include <cstdlib>
#include "ElementList.h"

namespace state{
    
    ElementList::ElementList (State& s) :s(s) {
        this->elements=elements;
    }
    ElementList::~ElementList (){
        if(&elements){
            delete &elements;
        }
    }
    bool ElementList::equals (const ElementList& other) const{
        if (typeid(this).name()==typeid(other).name()){
            return true;
        }else{
                return false;
            }
        
    }
    const State& ElementList::getState() const{
        return this->s;
    }
    int const ElementList::size() {
        return this->size();
    }
    /*Element* const ElementList::get (int i) {
    // on cherche un "élément" à un emplacement "i", s'il existe on le renvoie sinon erreur
       if (i>=this->size()){
            return 0; //throw runtime_error("la cellule demandee n'existe pas");
       }else{
                return elements.at(i);
            }
    }*/
    void ElementList::clear (){
        free(this);
    }
    void ElementList::set (int i, Element* e){
        elements.at(i)=e;
    }
}