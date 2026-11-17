
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class
class Animal {
protected:
    string color;
    string food;
    const string species;
    double weight;

public:
    Animal(string c, string f, string s, double w)
        : color(c), food(f), species(s), weight(w) {
    }

    virtual void Print() {
        cout << "Species: " << species << endl;
        cout << "Color: " << color << endl;
        cout << "Food: " << food << endl;
        cout << "Weight: " << weight << endl;
    }

    virtual ~Animal() = default;
};

class Lynx : public Animal {
public:
    Lynx(string c, string f, double w)
        : Animal(c, f, "Lynx", w) {
    }

    void Print() override {
        Animal::Print();
    }
};

// Pet inherits Animal
class Pet : public Animal {
protected:
    string name;

public:
    Pet(string c, string f, string s, double w, string n)
        : Animal(c, f, s, w), name(n) {
    }

    void Print() override {
        Animal::Print();
        cout << "Name: " << name << endl;
    }
};

// Dog inherits Pet
class Dog : public Pet {
private:
    vector<string> commands;

public:
    Dog(string c, string f, double w, string n,
        vector<string> cmds)
        : Pet(c, f, "Dog", w, n), commands(cmds) {
    }

    void Print() override {
        Pet::Print();

        cout << "Commands: ";
        for (const string& command : commands) {
            cout << command << " ";
        }
        cout << endl;
    }
};

// Cat inherits Pet
class Cat : public Pet {
public:
    Cat(string c, string f, double w, string n)
        : Pet(c, f, "Cat", w, n) {
    }

    void Print() override {
        Pet::Print();
    }
};

// Parrot inherits Animal
class Parrot : public Pet {
private:
    bool talking;
    double wingspan;

public:
    Parrot(string c, string f, double w,
        bool t, double ws,string n)
        : Pet(c, f, "Parrot", w, n),
        talking(t), wingspan(ws) {
    }

    void Print() override {
        Pet::Print();
        cout << "Talking: "
            << (talking ? "Yes" : "No") << endl;
        cout << "Wingspan: " << wingspan << endl;
    }
};

int main() {
    Dog dog("Brown", "Meat", 15, "Rex",
        { "Sit", "Stay", "Come", "Fetch" });

    Cat cat("White", "Fish", 5, "Luna");

    Parrot parrot("Green", "Seeds", 1.5, true, 30,"Charlee");

    Lynx lynx("Golden", "Meat", 25);

    cout << "--- DOG ---" << endl;
    dog.Print();

    cout << "\n--- CAT ---" << endl;
    cat.Print();

    cout << "\n--- PARROT ---" << endl;
    parrot.Print();

    cout << "\n--- LYNX ---" << endl;
    lynx.Print();

    return 0;
}
