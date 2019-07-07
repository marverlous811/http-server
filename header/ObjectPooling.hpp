//
//  ObjectPooling.hpp
//  httpServer
//
//  Created by Ows on 7/7/19.
//  Copyright © 2019 hieunq. All rights reserved.
//

#ifndef ObjectPooling_hpp
#define ObjectPooling_hpp

#include <vector>
#include "./Client.hpp"

#define MIN_LENGTH 100

class ObjectPooling{
private:
    std::vector<Client*> listAvaiable;
    std::vector<Client*> listBusy;
    ObjectPooling();
public:
    static ObjectPooling& getInstance();
    ~ObjectPooling();
    
    Client* getObject();
    void returnPool(Client* client);
};

#endif /* ObjectPooling_hpp */
