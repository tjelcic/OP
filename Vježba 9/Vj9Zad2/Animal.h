#include <iostream>
#include <cstdlib>
#include <string.h>

#define SIZE 15

class Animal
{
protected:
    char species[SIZE] = "Animal";
public:
    virtual int legs() = 0;
    virtual char* name() = 0;
};

class Insect : public Animal
{
protected:
    char species[SIZE] = "Insect";
public:
};

class Spider : public Animal
{
protected:
    char species[SIZE] ="Spider";
public:
};

class Bird : public Animal
{
private:
    char species[SIZE] = "Bird";
public:
};

class Tarantula : public Spider
{
private:
    int num_leg = 8;
    char _name[SIZE] = "Tarantula";
public:
    int legs();
    char* name();
};

class Cockroach : public Insect
{
private:
    int num_leg = 6;
    char _name[SIZE] = "Cockroach";
public:
    int legs();
    char* name();
};

class Sparrow : public Bird
{
private:
    int num_leg = 2;
    char _name[SIZE] = "Sparrow";
public:
    int legs();
    char* name();
};

class Count
{
private:
    Animal** arr;
    int sz = 0;
    int num = 0;
public:
    Count();
    void add(Animal* A1);
    void sum();
};
