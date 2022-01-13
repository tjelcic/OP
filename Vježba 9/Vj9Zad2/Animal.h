#include <iostream>
#include <cstdlib>
#include <string.h>

class Animal
{
protected:
    char species[15] = "Animal";
public:
    virtual int legs() = 0;
    virtual char* name() = 0;
};

class Insect : public Animal
{
protected:
    char species[15] = "Insect";
public:
};

class Spider : public Animal
{
protected:
    char species[15] ="Spider";
public:
};

class Bird : public Animal
{
private:
    char species[15] = "Bird";
public:
};

class Tarantula : public Spider
{
private:
    int num_leg = 8;
    char _name[15] = "Tarantula";
public:
    int legs();
    char* name();
};

class Cockroach : public Insect
{
private:
    int num_leg = 6;
    char _name[15] = "Cockroach";
public:
    int legs();
    char* name();
};

class Sparrow : public Bird
{
private:
    int num_leg = 2;
    char _name[15] = "Sparrow";
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
