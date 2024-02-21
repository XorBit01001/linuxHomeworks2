#include "shared_array.h"

shared_array::shared_array(const std::string& name_, size_t size_)
    : name(name_), size(size_)
{
    int fd = shm_open(name.c_str(), O_CREAT | O_RDWR, 0666);
    ftruncate(fd, size * sizeof(int));
    data = (int*)mmap(nullptr, size * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    semaphore = sem_open(name.c_str(), O_CREAT | O_RDWR, 0666, 1);
}

shared_array::~shared_array() {
    munmap(data,  size * sizeof(int));
    sem_close(semaphore);
    sem_unlink(name.c_str());
}

int& shared_array::operator[](size_t index) {
    sem_wait(semaphore);
    int& value = data[index];
    sem_post(semaphore);
    return value;
}