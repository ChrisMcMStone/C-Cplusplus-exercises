#include <iostream>
using namespace std;

class Animal {

public:
    void noise() {
        cout << "Generic noise!" << endl;
    }
};

class Cow : public Animal {

public:
    void noise() {
        cout << "Moo!" << endl;
    }
};

class Sheep : public Animal {

public:
    void noise() {
        cout << "Baaaa!" << endl;
    }
};

void func(Animal *x) {
    x->noise();
}

int main() {

    Animal *animal = new Animal;
    Cow *cow = new Cow;
    Sheep *sheep = new Sheep;

    func(animal);
    func(cow);
    func(sheep);
    
}

/*
 Given the above code, what will be printed by the three calls to 'func' in the main function?

Answers:

func(animal); --> "Generic noise!"
func(cow); --> "Generic noise!"
func(sheep); --> "Generic noise!"

func(animal); --> "Generic noise!"
func(cow); --> "Moo"
func(sheep); --> "Generic noise!"

func(animal); --> "Generic noise!"
func(cow); --> "Moo"
func(sheep); --> "Baaa"

func(animal); --> "Generic noise!"
func(cow); --> "Generic noise!"
func(sheep); --> "Baaa"

Explanation:

Without the use of "virtual", the implementation of the 'noise' method is decided at compile time base on the type of the pointer that you pass to the 'func' method.

However, if you use "virtual" like below, then 'func' decides which 'noise()' method to use at run time based on the type of the pointed-to object. 

public:
    virtual void noise() {
        cout << "Generic noise!" << endl;
    }
};

*/


