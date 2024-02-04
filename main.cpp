/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct Synthesizer
{
    int numberOfOscillators = 3;
    int numberofKnobs = 15;
    float amountOfVoltagePerOctave = 0.5f;
    int numberOfKeys = 88;
    int numberOfDigitalDisplays = 1;

    struct Keyboard
    {
        bool hasEightyEightKeys = true;
        float midiVelocityEnabled = 127.f;
        int numOfBlackKeys = 36;
        std::string synthCompany = "Nord";
        std::string model = "Lead";

        void pushKey(float midiVelocity, float polyphony = 10.f, bool afterTouch = true);
        void releaseKey(float releaseTime, bool usesADSR = true);
        int getNumOfKeysPressed(int numOfMidiEvents);
    };

    void makeSound(Keyboard keyboard);
    void showPatchParameters();
    float changeVoltage(float amountOfVoltage, Keyboard keyboard);

    Keyboard eventsOnSynth;
};

void Synthesizer::Keyboard::pushKey(float midiVelocityPushed, float morePolyphony, bool afterTouched)
{
    midiVelocityEnabled = midiVelocityPushed - morePolyphony - afterTouched;
}

void Synthesizer::Keyboard::releaseKey(float releasedTime, bool usedADSR)
{
    midiVelocityEnabled = releasedTime - usedADSR;
}

int Synthesizer::Keyboard::getNumOfKeysPressed(int numOfMidiEvents)
{
    return numOfMidiEvents;
}

void Synthesizer::makeSound(Keyboard keyboard)
{
    keyboard.pushKey(0.5f, 10.f, true);
}

void Synthesizer::showPatchParameters()
{
    numberOfKeys -= 3;
}

float Synthesizer::changeVoltage(float amountOfVoltage, Keyboard keyboard)
{
    return amountOfVoltagePerOctave = amountOfVoltage + keyboard.midiVelocityEnabled;
}

struct Bicycle
{
    int amountOfGears = 12;
    int amountOfBrakeLevers = 2;
    int numberOfShifters = 4;
    int numberOfWheels = 2;
    int numberOfPedals = 2;

    void moveBicycle();
    void shiftGears();
    void stopBicycle();
};

void Bicycle::moveBicycle()
{
    std::cout << "Bicycle is moving!\n";
}

void Bicycle::shiftGears()
{
    std::cout << "Gears are being shifted!\n";
}

void Bicycle::stopBicycle()
{
    std::cout << "Bicycle is being stopped!\n";
}

struct Restaurant
{
    int amountOfMenuItems = 90;
    std::string nameOfIngredientsPerMenuItem = "Tomatoes, lettuce, cheese, meat, and mayo";
    int numberOfOvens = 4;
    int numberOfEmployees = 10;
    int numberOfTables = 30;

    struct Kitchen
    {
        int numOfCooks = 3;
        int numOfDeepFryers = 2;
        bool greaseCollected = true;
        float gallonsOfVegOil = 20.f;
        std::string orderName = "Lisa";
        double totalAmountOfOil = 100.00;

        void fillFryerWithOil(double amountOfOil, double costOfVegOilPerGallon = 2.0, bool oilNeedsReplaced = false);
        void printOrderTicket(int orderNumber, bool hasSpecialInstructions = false);
        double annualRevenue(double annualProfit);
    };

    void makeFood(Kitchen kitchen);
    void serveDiners(Kitchen kitchen);
    float chargeMoney(float moneyOfMeal);

    Kitchen patronsBeingServed;
};

void Restaurant::Kitchen::fillFryerWithOil(double amountOfOil, double costOfVegOilPerGallon, bool oilNeedsReplaced)
{
    totalAmountOfOil = amountOfOil - costOfVegOilPerGallon - oilNeedsReplaced;
}

void Restaurant::Kitchen::printOrderTicket(int orderNumber, bool hasSpecialInstructions)
{
    numOfCooks = orderNumber + hasSpecialInstructions;
}

double Restaurant::Kitchen::annualRevenue(double annualProfit)
{
    return annualProfit;
}

void Restaurant::makeFood(Kitchen kitchen)
{
    amountOfMenuItems = kitchen.numOfCooks + kitchen.numOfDeepFryers;
}

void Restaurant::serveDiners(Kitchen kitchen)
{
    numberOfEmployees = kitchen.numOfCooks + kitchen.numOfDeepFryers;
}

float Restaurant::chargeMoney(float moneyOfMeal)
{
    return moneyOfMeal;
}

struct Bank
{
    double amountOfMoneyInVault = 987654.56;
    int amountOfArmedGuards = 4;
    int numOfCustomersInLine = 7;
    int numOfTellers = 4;
    float amountOfAccounts = 1355.5f;

    double collectMoney(double amountOfMoneyCollected);
    void serviceClient();
    float wireMoney(float amountOfMoneyWired);
};

double Bank::collectMoney(double amountOfMoneyCollected)
{
    return amountOfMoneyCollected;
}

void Bank::serviceClient()
{
    std::cout << "Client is being served.\n";
}

float Bank::wireMoney(float amountOfMoneyWired)
{
    return amountOfMoneyWired;
}

struct Case
{
    int crystal = 1;
    float dialRing = 10.25f;
    int bezel = 1;
    float dateWindow = 1201.f;
    int hands = 2;

    void houseInternalComponents();
    float displayTime(float currentTime);
    void keepInternalPartsClean();
};

void Case::houseInternalComponents()
{
    std::cout << "Internal components are housed.\n";
}

float Case::displayTime(float currentTime)
{
    return currentTime;
}

void Case::keepInternalPartsClean()
{
    std::cout << "Internal parts are nice and clean.\n";
}

struct Band
{
    int links = 5;
    int lug = 2;
    int pins = 9;
    int buckle = 1;
    int adjustment = 1;

    void holdWatchToWrist();
    void adjustBandTightness();
    void adjustBandLooseness();
};

void Band::holdWatchToWrist()
{
    std::cout << "Band is holding watch to wrist.\n";
}

void Band::adjustBandTightness()
{
    std::cout << "The band has tightened.\n";
}

void Band::adjustBandLooseness()
{
    std::cout << "The band has loosened.\n";
}

struct Hands
{
    float hourHand = 12.f;
    float secondHand = 60.f;
    double sweepSecondHand = 120.00;
    double tideDial = 24.00;
    float arbitraryDial = 120.f;

    float displayHours(float hours);
    float displayMinutes(float minutes);
    float displaySeconds(float seconds);
};

float Hands::displayHours(float hours)
{
    return hours;
}

float Hands::displayMinutes(float minutes)
{
    return minutes;
}

float Hands::displaySeconds(float seconds)
{
    return seconds;
}

struct AdjustmentDials
{
    float crown = 120.f;
    float pusher1 = 120.f;
    int reset = 1;
    double innerBezelCrown = 120.00;
    double pusher2 = 60.00;

    float changeTimeForward(float time);
    float changeTimeBackward(float time);
    void useAuxiliaryFunction();
};

float AdjustmentDials::changeTimeForward(float time)
{
    return time + 1.f;
}

float AdjustmentDials::changeTimeBackward(float time)
{
    return time - 1.f;
}

void AdjustmentDials::useAuxiliaryFunction()
{
    std::cout << "Some kind of secondary function is being used.\n";
}

struct Movement
{
    double mainWheel = 240.00;
    int fork = 4;
    double ratchetWheel = 120.00;
    double safetyRoller = 60.00;
    int barrellHub = 1;

    void keepTime();
    void makeClickSound();
    void adjustTiming();
};

void Movement::keepTime()
{
    std::cout << "Current time.\n";
}

void Movement::makeClickSound()
{
    std::cout << "Clicking sound is audible.\n";
}

void Movement::adjustTiming()
{
    std::cout << "Time is being adjusted.\n";
}

struct WristWatch
{
    Case outerCase;
    Band band;
    Hands hands;
    AdjustmentDials adjustmentDials;
    Movement movement;

    float displayCurrentTime(float currentTime);
    double measureTimePast(double time);
    void changeDisplayedTime();
};

float WristWatch::displayCurrentTime(float currentTime)
{
    return currentTime;
}

double WristWatch::measureTimePast(double time)
{
    return time;
}

void WristWatch::changeDisplayedTime()
{
    std::cout << "Time has been changed.\n";
}







int main()
{
    Example::main();
    
    std::cout << "good to go!" << std::endl;
}
