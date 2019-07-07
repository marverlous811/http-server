//
//  ObjectPooling.cpp
//  httpServer
//
//  Created by Ows on 7/7/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#include "../header/ObjectPooling.hpp"

ObjectPooling& ObjectPooling::getInstance(){
    static ObjectPooling pooling;
    return pooling;
}

ObjectPooling::~ObjectPooling(){
    
}

ObjectPooling::ObjectPooling(){
    for(int i = 0; i < MIN_LENGTH; i++){
        Client* cli = new Client();
        this->listAvaiable.push_back(cli);
    }
}

Client* ObjectPooling::getObject(){
    Client* cli;
    if(this->listAvaiable.empty()){
        cli = new Client();
    }
    else{
        cli = this->listAvaiable.back();
        this->listAvaiable.pop_back();
    }
    
    return cli;
}

void ObjectPooling::returnPool(Client *client){
    this->listAvaiable.push_back(client);
}

