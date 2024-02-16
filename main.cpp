/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar
{
    int num = 0;
    Bar(int n) : num(n) { }
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()






struct Synthesizer
{
    Synthesizer();
    int numberOfOscillators = 3;
    int numberofKnobs = 15;
    float amountOfVoltagePerOctave = 0.5f;
    int numberOfKeys = 88;
    int numberOfDigitalDisplays = 1;

    struct Keyboard
    {
        Keyboard();
        bool hasEightyEightKeys;
        float midiVelocityEnabled;
        int numOfBlackKeys;
        std::string synthCompany;
        std::string model;

        void pushKey(float midiVelocity, float polyphony = 10.f, bool afterTouch = true);
        void releaseKey(float releaseTime, bool usesADSR = true);
        int getNumOfKeysPressed(int numOfMidiEvents);
    };

    void makeSound(Keyboard keyboard);
    void showPatchParameters();
    float changeVoltage(float amountOfVoltage, Keyboard keyboard);
/*    void changeTimbre(int filterSweep, int rezSweep)
    {
        
        {
            
        }
    }
*/
    Keyboard eventsOnSynth;
};

Synthesizer::Synthesizer()
{
    std::cout << "Synthesizer being constructed!" << std::endl;
}

Synthesizer::Keyboard::Keyboard()
{
    hasEightyEightKeys = true;
    midiVelocityEnabled = 127.f;
    numOfBlackKeys = 36;
    synthCompany = "Nord";
    model = "Lead";
    std::cout << "Keyboard is being constructed!" << std::endl;
}

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
    std::cout << "Sound was made!" << std::endl;
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
    Bicycle();
    int amountOfGears;
    int amountOfBrakeLevers;
    int numberOfShifters;
    int numberOfWheels;
    int numberOfPedals;

    void moveBicycle();
    void shiftGears();
    void stopBicycle();
    void arbitraryFunc(int valueA, int valueB, int doABikeThing);
};

Bicycle::Bicycle()
{
    amountOfGears = 12;
    amountOfBrakeLevers = 2;
    numberOfShifters = 4;
    numberOfWheels = 2;
    numberOfPedals = 2;
    std::cout << "Bicycle being constructed!" << std::endl;
}

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

void Bicycle::arbitraryFunc(int valueA, int valueB, int doABikeThing)
{
    int valueC = 10;
    int valueD = 5;
    int arbitraryMember = valueC + valueD;
    int totalMembers = arbitraryMember * valueC + valueD + valueA + valueB;

    while(doABikeThing < totalMembers)
    {
        ++doABikeThing;
        std::cout << "Say something about bikes" << std::endl;

        if(doABikeThing > 10)
        break;
    }
}

struct Restaurant
{
    Restaurant();
    int amountOfMenuItems;
    std::string nameOfIngredientsPerMenuItem;
    int numberOfOvens;
    int numberOfEmployees;
    int numberOfTables;

    struct Kitchen
    {
        Kitchen();
        int numOfCooks;
        int numOfDeepFryers;
        bool greaseCollected;
        float gallonsOfVegOil;
        std::string orderName ;
        double totalAmountOfOil;

        void fillFryerWithOil(double amountOfOil, double costOfVegOilPerGallon = 2.0, bool oilNeedsReplaced = false);
        void printOrderTicket(int orderNumber, bool hasSpecialInstructions = false);
        double annualRevenue(double annualProfit);
    };

    void makeFood(Kitchen kitchen);
    void serveDiners(Kitchen kitchen);
    float chargeMoney(float moneyOfMeal);

    Kitchen patronsBeingServed;
};

Restaurant::Restaurant()
{
    amountOfMenuItems = 90;
    nameOfIngredientsPerMenuItem = "Tomatoes, lettuce, cheese, meat, and mayo";
    numberOfOvens = 4;
    numberOfEmployees = 10;
    numberOfTables = 30;
    std::cout << "Restaurant being constructed!" << std::endl;
}

Restaurant::Kitchen::Kitchen() : numOfCooks(3), numOfDeepFryers(2), greaseCollected(true), gallonsOfVegOil(20.f), orderName("Lisa"), totalAmountOfOil(100.00)
{
    std::cout << "Kitchen being constructed!" << std::endl;
}

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
    std::cout << "Displaying annual profit" << std::endl;
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
    Bank();
    double amountOfMoneyInVault = 987654.56;
    int amountOfArmedGuards = 4;
    int numOfCustomersInLine = 7;
    int numOfTellers = 4;
    float amountOfAccounts = 1355.5f;

    double collectMoney(double amountOfMoneyCollected);
    void serviceClient();
    float wireMoney(float amountOfMoneyWired);
};

Bank::Bank()
{
    std::cout << "Bank is being constructed!" << std::endl;
}

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
    Case();
    int crystal = 1;
    float dialRing = 10.25f;
    int bezel = 1;
    float dateWindow = 1201.f;
    int hands = 2;

    void houseInternalComponents();
    float displayTime(float currentTime);
    void keepInternalPartsClean();
};

Case::Case()
{
    std::cout << "Case is being constructed!" << std::endl;
}

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
    Band();
    int links;
    int lug;
    int pins;
    int buckle;
    int adjustment;

    void holdWatchToWrist();
    void adjustBandTightness();
    void adjustBandLooseness();
};

Band::Band()
{
    links = 5;
    lug = 2;
    pins = 9;
    buckle = 1;
    adjustment = 1;
    std::cout << "Wristband is being constructed!" << std::endl;
}

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
    Hands();
    float hourHand = 12.f;
    float secondHand = 60.f;
    double sweepSecondHand = 120.00;
    double tideDial = 24.00;
    float arbitraryDial = 120.f;

    float displayHours(float hours);
    float displayMinutes(float minutes);
    float displaySeconds(float seconds);
};

Hands::Hands()
{
    std::cout << "Watch hands are being constructed!" << std::endl;
}

float Hands::displayHours(float hours)
{
    std::cout << "Displaying hours" << std::endl;
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
    AdjustmentDials();
    float crown;
    float pusher1;
    int reset;
    double innerBezelCrown;
    double pusher2;

    float changeTimeForward(float time);
    float changeTimeBackward(float time);
    void useAuxiliaryFunction();
};

AdjustmentDials::AdjustmentDials()
{
    crown = 120.f;
    pusher1 = 120.f;
    reset = 1;
    innerBezelCrown = 120.00;
    pusher2 = 60.00;
    std::cout << "Adjustment dials are being constructed!" << std::endl;
}

float AdjustmentDials::changeTimeForward(float time)
{
    std::cout << "Dial adjusted forward" << std::endl;
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
    Movement();
    double mainWheel;
    int fork;
    double ratchetWheel;
    double safetyRoller;
    int barrellHub;

    void keepTime();
    void makeClickSound();
    void adjustTiming();
};

Movement::Movement() : mainWheel(240.00), fork(4), ratchetWheel(120.0), safetyRoller(60.00), barrellHub(1)
{
    std::cout << "Movement is being constructed!" << std::endl;
}

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
    WristWatch();
    Case outerCase;
    Band band;
    Hands hands;
    AdjustmentDials adjustmentDials;
    Movement movement;

    float displayCurrentTime(float currentTime);
    double measureTimePast(double time);
    void changeDisplayedTime();
};

WristWatch::WristWatch()
{
    std::cout << "Wristwatch is being constructed!" << std::endl;
}

float WristWatch::displayCurrentTime(float currentTime)
{
    std::cout << "Current time is displayed" << std::endl;
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

    Synthesizer instantiatedSynthesizer;
    instantiatedSynthesizer.makeSound(instantiatedSynthesizer.eventsOnSynth);
    instantiatedSynthesizer.showPatchParameters();
    instantiatedSynthesizer.changeVoltage(55.5, instantiatedSynthesizer.eventsOnSynth);

    std::cout << "Is instantiatedSynthesizer's member var 'numberOfOscillators' equal to 0? " << (instantiatedSynthesizer.numberOfOscillators == 0 ? "Yes" : "No") << "\n";

    Synthesizer::Keyboard boardWithKeys;
    boardWithKeys.pushKey(127.f, 10.f, true);
    boardWithKeys.releaseKey(200.f, true);
    boardWithKeys.getNumOfKeysPressed(127);

    std::cout << "Is boardWithKeys' member var 'numOfBlackKeys' equal to 36? " << (boardWithKeys.numOfBlackKeys == 36 ? "Yes" : "No") << "\n";

    Bicycle bike;
    bike.moveBicycle();
    bike.shiftGears();
    bike.stopBicycle();
    bike.arbitraryFunc(0, 0, 0);

    std::cout << "Is bike's member var 'amountOfGears' equal to 10? " << (bike.amountOfGears == 10 ? "Yes" : "No") << "\n";

    Restaurant placeToEat;
    placeToEat.makeFood(placeToEat.patronsBeingServed);
    placeToEat.serveDiners(placeToEat.patronsBeingServed);
    placeToEat.chargeMoney(20);

    std::cout << "Is placeToEat's member var 'amountOfMenuItems' equal to 54? " << (placeToEat.amountOfMenuItems == 54 ? "Yes" : "No") << "\n";

    Restaurant::Kitchen cookArea;
    cookArea.fillFryerWithOil(50.75, 2.0, false);
    cookArea.printOrderTicket(5, false);
    cookArea.annualRevenue(359000.52);

    std::cout << "Is cookArea's member var 'greaseCollected' set to true? " << (cookArea.greaseCollected == true ? "Yes" : "No") << "\n";

    std::cout << "Is cookArea's member var 'numOfCooks' equal to 3? " << (cookArea.numOfCooks == 3 ? "Yes" : "No") << "\n";

    Bank localBank;
    localBank.serviceClient();
    localBank.collectMoney(258.22);
    localBank.wireMoney(300.f);

    std::cout << "Is localBank's member var 'amountOfMoneyInVault' equal to 0? " << (localBank.amountOfMoneyInVault == 0.0 ? "Yes" : "No") << "\n";

    Case watchCase;
    watchCase.houseInternalComponents();
    watchCase.displayTime(12.25);
    watchCase.keepInternalPartsClean();

    std::cout << "Is watchCase's member var 'bezel' equal to 1? " << (watchCase.bezel == 1 ? "Yes" : "No") << "\n";

    Band wristBand;
    wristBand.holdWatchToWrist();
    wristBand.adjustBandTightness();
    wristBand.adjustBandLooseness();

    std::cout << "Is wristBand's member var 'links' equal to 9? " << (wristBand.links == 9 ? "Yes" : "No") << "\n";

    Hands watchHands;
    watchHands.displayHours(12.f);
    watchHands.displayMinutes(60.f);
    watchHands.displaySeconds(120.f);

    std::cout << "Is watchHands's member var 'tideDial' equal to 3? " << (watchHands.tideDial == 3.0 ? "Yes" : "No") << "\n";

    AdjustmentDials dials;
    dials.changeTimeForward(1.f);
    dials.changeTimeBackward(12.f);
    dials.useAuxiliaryFunction();

    std::cout << "Is dials's member var 'crown' equal to 120? " << (dials.crown == 120.f ? "Yes" : "No") << "\n";

    Movement mechanisms;
    mechanisms.keepTime();
    mechanisms.makeClickSound();
    mechanisms.adjustTiming();

    std::cout << "Is mechanisms's member var 'mainWheel' equal to 240? " << (mechanisms.mainWheel == 240.00 ? "Yes" : "No") << "\n";

    WristWatch wholeWatch;
    wholeWatch.displayCurrentTime(10.5);
    wholeWatch.measureTimePast(12.45);
    wholeWatch.changeDisplayedTime();
}
