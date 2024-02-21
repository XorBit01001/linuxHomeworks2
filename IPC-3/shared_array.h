#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>

class shared_array {
private:
    std::string name;
    size_t size;
    int* data;
    sem_t* semaphore;
public:
    shared_array(const std::string& name, size_t size);
    ~shared_array();

    int& operator[](size_t index);

};

