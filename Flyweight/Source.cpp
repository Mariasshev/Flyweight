#include <iostream>
#include <map>
using namespace std;


class Character 
{
public:
    virtual void Show(int positionX, int positionY) = 0;
};

class LightInfantry : public Character 
{
private:
    char symbol;
    int speed;
    int strength;

public:
    LightInfantry() : symbol('A'), speed(20), strength(10) {}

    void Show(int positionX, int positionY) override 
    {
        cout << "Transport pos: " << positionX << ", " << positionY << endl;
        cout << "Speed: " << speed << ", Strength: " << strength << endl;
    }
};

class TransportVehicle : public Character 
{
private:
    char symbol;
    int speed;
    int strength;

public:
    TransportVehicle() : symbol('B'), speed(70), strength(0) {}

    void Show(int positionX, int positionY) override 
    {
        cout << "Transport pos: " << positionX << ", " << positionY << endl;
        cout << "Speed: " << speed << ", Strength: " << strength << endl;
    }
};

class HeavyGroundCombatEquipment : public Character 
{
private:
    char symbol;
    int speed;
    int strength;

public:
    HeavyGroundCombatEquipment() : symbol('C'), speed(15), strength(150) {}

    void Show(int positionX, int positionY) override 
    {
        cout << "Transport pos: " << positionX << ", " << positionY << endl;
        cout << "Speed: " << speed << ", Strength: " << strength << endl;
    }
};

class LightGroundCombatVehicles : public Character 
{
private:
    char symbol;
    int speed;
    int strength;

public:
    LightGroundCombatVehicles() : symbol('D'), speed(50), strength(30) {}

    void Show(int positionX, int positionY) override 
    {
        cout << "Transport pos: " << positionX << ", " << positionY << endl;
        cout << "Speed: " << speed << ", Strength: " << strength << endl;
    }
};

class Aircraft : public Character 
{
private:
    char symbol;
    int speed;
    int strength;

public:
    Aircraft() : symbol('E'), speed(300), strength(100) {}

    void Show(int positionX, int positionY) override 
    {
        cout << "Transport pos: " << positionX << ", " << positionY << endl;
        cout << "Speed: " << speed << ", Strength: " << strength << endl;
    }
};

class CharacterFactory {
private:
    map<char, Character*> characters;

public:
    Character* GetCharacter(char key) 
    {
        Character* character = characters[key];
        if (!character) 
        {
            switch (key) 
            {
            case 'A':
                character = new LightInfantry();
                break;
            case 'B':
                character = new TransportVehicle();
                break;
            case 'C':
                character = new HeavyGroundCombatEquipment();
                break;
            case 'D':
                character = new LightGroundCombatVehicles();
                break;
            case 'E':
                character = new Aircraft();
                break;
            }
            characters[key] = character;
        }
        return character;
    }
};

int main() {
    CharacterFactory characterFactory;
    int posX = 10;
    int posY = 10;

    Character* infantry = characterFactory.GetCharacter('A');
    infantry->Show(posX, posY);
    cout << "----------" << endl << endl;
    
    Character* vehicle = characterFactory.GetCharacter('B');
    vehicle->Show(posX + 25, posY + 25);
    cout << "----------" << endl << endl;

    Character* combat = characterFactory.GetCharacter('C');
    combat->Show(posX + 45, posY + 45);
    cout << "----------" << endl << endl;

    Character* light = characterFactory.GetCharacter('D');
    light->Show(posX + 65, posY + 65);
    cout << "----------" << endl << endl;

    Character* aircraft = characterFactory.GetCharacter('E');
    aircraft->Show(posX + 85, posY + 85);
    cout << "----------" << endl << endl;

    system("pause");
    return 0;
}