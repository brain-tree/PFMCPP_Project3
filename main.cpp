/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()


//insert Example::main() into main() of user's repo.




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

Synthesizer::Synthesizer()
{
    std::cout << "Synthesizer being constructed!" << std::endl;
}

Synthesizer::Keyboard::Keyboard()
{
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
    int amountOfGears = 12;
    int amountOfBrakeLevers = 2;
    int numberOfShifters = 4;
    int numberOfWheels = 2;
    int numberOfPedals = 2;

    void moveBicycle();
    void shiftGears();
    void stopBicycle();
};

Bicycle::Bicycle()
{
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

struct Restaurant
{
    Restaurant();
    int amountOfMenuItems = 90;
    std::string nameOfIngredientsPerMenuItem = "Tomatoes, lettuce, cheese, meat, and mayo";
    int numberOfOvens = 4;
    int numberOfEmployees = 10;
    int numberOfTables = 30;

    struct Kitchen
    {
        Kitchen();
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

Restaurant::Restaurant()
{
    std::cout << "Restaurant being constructed!" << std::endl;
}

Restaurant::Kitchen::Kitchen()
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
    int links = 5;
    int lug = 2;
    int pins = 9;
    int buckle = 1;
    int adjustment = 1;

    void holdWatchToWrist();
    void adjustBandTightness();
    void adjustBandLooseness();
};

Band::Band()
{
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
    float crown = 120.f;
    float pusher1 = 120.f;
    int reset = 1;
    double innerBezelCrown = 120.00;
    double pusher2 = 60.00;

    float changeTimeForward(float time);
    float changeTimeBackward(float time);
    void useAuxiliaryFunction();
};

AdjustmentDials::AdjustmentDials()
{
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
    double mainWheel = 240.00;
    int fork = 4;
    double ratchetWheel = 120.00;
    double safetyRoller = 60.00;
    int barrellHub = 1;

    void keepTime();
    void makeClickSound();
    void adjustTiming();
};

Movement::Movement()
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
