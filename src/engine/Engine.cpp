#include "Engine.h"
#include <pthread.h>
#include <vector>
#include <list>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "Attack.h"
#include "Move.h"
#include "ProduceFighter.h"
#include "ProduceInfantry.h"
#include "AttackCommand.h"
#include "CaptureCommand.h"
#include "ProduceFighterCommand.h"
#include "MoveCommand.h"
#include "ProduceInfantryCommand.h"
#include "Capture.h"
#include "CaptureCommand.h"
namespace engine{
    
    Engine::~Engine (){
        
    }
 
    Engine::Engine (CommandSet* commandset, ActionList* actionlist){
        this->commandset=commandset;
        this->actionlist=actionlist;
    }
    EngineMode  Engine::getMode () const{
        return PLAY; 
    }

    void  Engine::addCommand (Command* cmd){
        engine_mutex.lock();
        commandset->setCommand(cmd);
        engine_mutex.unlock();
    }
    
    void Engine::addAction (Action* action){
        actionlist->actions.push_back(action);
    }
    /*void  Engine::takeCommands (CommandSet& commands){
        // prend les commandes du clavier
        
        
    }*/

    void  Engine::loadLevel (const char* file_name) const{
        
    }
    void  Engine::setMode (EngineMode mode){
        
    }
    
    void Engine::apply (){
        engine_mutex.lock();
        
        while(commandset->size()!=0){
            engine::CommandTypeID commandID=commandset->commands.front()->getCommandTypeID();
            engine::Command* cmd;
            cmd=commandset->commands.front();
            if(commandID==CommandTypeID::ATTACKCOMMAND){
                engine::AttackCommand* cmdAttck=static_cast<engine::AttackCommand*>(cmd);
                actionlist->actions.push_back(new engine::Attack(cmdAttck->getAttacker(), cmdAttck->getDefender(), cmdAttck->getStaticMap(), cmdAttck->getMapUnits()));
            }
            if(commandID==CommandTypeID::CAPTURECOMMAND){
                engine::CaptureCommand* cmdcap=static_cast<engine::CaptureCommand*>(cmd);
                actionlist->actions.push_back(new engine::Capture(cmdcap->getCapturer(), cmdcap->getCaptured()));          
            }
            if(commandID==CommandTypeID::MOVECOMMAND){
                engine::MoveCommand* cmdmv=static_cast<engine::MoveCommand*>(cmd);
                actionlist->actions.push_back(new engine::Move(cmdmv->getMover(), cmdmv->getDestination(), cmdmv->getStaticMapElements(), cmdmv->getMapUnits()));
            }
            if(commandID==CommandTypeID::PRODUCEFIGHTERCOMMAND){
                engine::ProduceFighterCommand* cmdprodf=static_cast<engine::ProduceFighterCommand*>(cmd);
                actionlist->actions.push_back(new engine::ProduceFighter(cmdprodf->getX(), cmdprodf->getY(), cmdprodf->getListOfElements(), cmdprodf->getListOfTurn(), cmdprodf->getPlayerColor()));
            }
            if(commandID==CommandTypeID::PRODUCEINFANTRYCOMMAND){
                engine::ProduceInfantryCommand* cmdprodi=static_cast<engine::ProduceInfantryCommand*>(cmd);
                actionlist->actions.push_back(new engine::ProduceInfantry(cmdprodi->getX(), cmdprodi->getY(), cmdprodi->getListOfElements(), cmdprodi->getListOfTurn(), cmdprodi->getPlayerColor()));
            }
            commandset->commands.erase(commandset->commands.begin());
        }
        engine_mutex.unlock();
    }
    
    void Engine::run(){
        if(actionlist->actions.empty()){
            std::cout<<"aucune commande à exécuter"<<std::endl;
        }
        engine_mutex.lock();
        while(!actionlist->actions.empty()){
            actionlist->actions.front()->execute();
            actionlist->actions.erase(actionlist->actions.begin());
        }
        engine_mutex.unlock();
    }




}