#include "Capture.h"
#include <math.h>

namespace engine{

    Capture::Capture (state::Infantry* capturer, state::Structure* captured){
        this->capturer=capturer;
        this->captured=captured;
    }
    
    Capture::~Capture(){
        
    }
    
    void Capture::execute () const{
        std::string answer;
        std::cout<<"do you want to capture this building? y or n"<<std::endl;
        std::cin>>answer;
        if(answer=="y"){
    int range = sqrt((captured->getY()-capturer->getY())*(captured->getY()-capturer->getY())+(captured->getX()-capturer->getX())*(captured->getX()-capturer->getX()));
    if (range==1){
        if (capturer->getColor() != captured->getColor()){
            if(captured->isFree()==1){
                captured->setCapturepoints(captured->getCapturepoints()-capturer->getHp());
                // si batiment non capturé
                if  (captured->getCapturepoints() >0){
                      std::cout<<"Il reste " << captured->getCapturepoints()<< "points de capture"<< std::endl;  
                }
                //si batiment capturé
                else{
                    captured->setColor(capturer->getColor()); // on change sa couleur
                    captured->setCapturepoints(20);           // on remet ses points à 20
                    std::cout<< "La structure ennemie a été capturée " << std::endl;
                }
            }
        }
    }
        }
    }
    
}


