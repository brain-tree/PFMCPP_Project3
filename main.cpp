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
        void changeVelocity(int midiValue);
    };

    void makeSound(Keyboard keyboard);
    void showPatchParameters();
    float changeVoltage(float amountOfVoltage, Keyboard keyboard);
    void changeTimbre(int filterSweep, int rezSweep);

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

void Synthesizer::Keyboard::changeVelocity(int midiValue)
{
    int velocityValue = 0;
    bool midiTriggered = true;
    int velocityChanged = midiTriggered + velocityValue + midiValue;

    while(midiTriggered)
    {
        ++velocityValue;
        ++velocityChanged;
        std::cout << "New velocity" << std::endl;
        if(velocityChanged >= 1)
            break;
    }
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

void Synthesizer::changeTimbre(int filterSweep, int rezSweep)
{
    int acidTweak = filterSweep + rezSweep;
    int acid = 0;

    while(acidTweak > acid)
    {
        ++acid;
        std::cout << "Come on you runts, let's have some Aphex acid!" << std::endl;
    }
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
        if(doABikeThing >= 5)
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
        void replaceTheOven(int newOven, int oldOven);
    };

    void makeFood(Kitchen kitchen);
    void serveDiners(Kitchen kitchen);
    float chargeMoney(float moneyOfMeal);
    void cleanTheKitchen(int amountOfAmmonia, int numOfSponges);

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

void Restaurant::Kitchen::replaceTheOven(int newPizzaOven, int oldPizzaOven)
{
    int numOfNewOvens = 2;
    int numOfOldOvens = 1;
    int sizeOfNewOven = oldPizzaOven * 2;
    int amountOfPizzasPerHour = sizeOfNewOven * newPizzaOven + oldPizzaOven - numOfOldOvens;

    while(numOfNewOvens > 2)
    {
        ++amountOfPizzasPerHour;
        std::cout << "More pizzas capable" << std::endl;
    }
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

void Restaurant::cleanTheKitchen(int amountOfAmmonia, int numOfSponges)
{
    bool kitchenIsClean = true;
    int sponges = 0;
    int ammonia = 0;
    int cleanTheKitchen = amountOfAmmonia + numOfSponges;

    while(sponges && ammonia <= 1)
    {
        ++sponges;
        ++ammonia;
        ++cleanTheKitchen;
        std::cout << "The kitchen is being cleaned!" << std::endl;
        if(kitchenIsClean)
            break;
    }
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
    float convertToCanadianDollar(float dollarValue);
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

float Bank::convertToCanadianDollar(float dollarValue)
{
    float usdValue = 1.f;
    float exchangeRate = 0.74f;
    float convertedValue = usdValue / exchangeRate;
    float totalCash = 1452584.63f;
    float markupRate = convertedValue * 100.f;
    float conversionValue = totalCash * convertedValue + markupRate;
    bool totalConverted = true;

    while(dollarValue <= 1)
    {
        ++conversionValue;
        std::cout << "Calculated conversion value: " << conversionValue << std::endl;
        if(totalConverted)
            break;
    }
    return conversionValue;
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
    int removeCase(int inchesRound);
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

int Case::removeCase(int inchesRound)
{
    int caseDiameter = 2;
    int numOfRotations = inchesRound * caseDiameter;
    bool caseOff = true;

    while(caseDiameter == 2)
    {
        ++numOfRotations;
        std::cout << "Removing the case. Rotations performed: " << numOfRotations << std::endl;
        if(caseOff)
            break;
    }
    return numOfRotations;
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
    void removeBand(double wristCircumference);
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

void Band::removeBand(double wristCircumference)
{
    double numOfInches = 5.0;
    double tightnessOfBand = 1.0;
    double bandRemoved = wristCircumference - tightnessOfBand - numOfInches;

    while(tightnessOfBand == 1.0)
    {
        --tightnessOfBand;
        std::cout << "The band is being removed." << std::endl;
        if(bandRemoved < 1)
            break;
    }
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
    int increaseTime(int timeInSeconds);
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

int Hands::increaseTime(int timeInSeconds)
{
    int secondsTicking = 0;
    int totalTime = secondsTicking + timeInSeconds;

    while(secondsTicking < 10)
    {
        ++secondsTicking;
        std::cout << "Increasing seconds: " << secondsTicking << std::endl;
        if(secondsTicking > 10)
        ++secondsTicking;
        std::cout << "Alternate add: " << secondsTicking << std::endl;
    }
    return totalTime;
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
    int adjustTheDial(int increaseValue, int decreaseValue);
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

int AdjustmentDials::adjustTheDial(int increaseValue, int decreaseValue)
{
    int adjustmentValue = 100;
    int neutralValue = increaseValue + decreaseValue;

    while(adjustmentValue <= 100)
    {
        ++adjustmentValue;
        std::cout << "Value at 100" << std::endl;
    }
    if(adjustmentValue > 100)
    {
        ++adjustmentValue;
        std::cout << "Value is over 100" << std::endl;
    }
    if(adjustmentValue += 200)
    {
        std::cout << "Current value: " << adjustmentValue << std::endl;
    }
    if(adjustmentValue >= 100)
    {
        --adjustmentValue;
        std::cout << "Decreasing value: " << adjustmentValue << std::endl;
    }
    else
    {
        std::cout << "Quitting." << neutralValue << std::endl;
    }
    return adjustmentValue;
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
    void movementFunc(double gearFunction);
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

void Movement::movementFunc(double gearFunction)
{
    double gearValue = 1.0;
    double gearPosition = gearValue + gearFunction;

    while(gearValue >= 1.0)
    {
        ++gearValue;
        ++gearPosition;
        std::cout << "Gear is functioning. Gear position: " << gearPosition << std::endl;
        if(gearValue > 9)
            break;
    }
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
    int changRate(int increaseRate, int decreaseRate);
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

int WristWatch::changRate(int increaseRate, int decreaseRate)
{
    int neutralRate = increaseRate - decreaseRate;
    int normalRate = 0;
    int fasterRate = 100;
    bool watchIsWorking = true;

    while(watchIsWorking)
    {
        ++normalRate;
        --fasterRate;
        std::cout << "Faster rate is " << fasterRate << ". Normal rate is " << normalRate << "." << std::endl;
        if(normalRate && fasterRate == 50)
            break;
    }
    return neutralRate;
}







int main()
{
    Example::main();
    
    std::cout << "good to go!" << std::endl;

    Synthesizer instantiatedSynthesizer;
    instantiatedSynthesizer.makeSound(instantiatedSynthesizer.eventsOnSynth);
    instantiatedSynthesizer.showPatchParameters();
    instantiatedSynthesizer.changeVoltage(55.5, instantiatedSynthesizer.eventsOnSynth);
    instantiatedSynthesizer.changeTimbre(0, 1);

    std::cout << "Is instantiatedSynthesizer's member var 'numberOfOscillators' equal to 0? " << (instantiatedSynthesizer.numberOfOscillators == 0 ? "Yes" : "No") << "\n";

    Synthesizer::Keyboard boardWithKeys;
    boardWithKeys.pushKey(127.f, 10.f, true);
    boardWithKeys.releaseKey(200.f, true);
    boardWithKeys.getNumOfKeysPressed(127);
    boardWithKeys.changeVelocity(127);

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
    placeToEat.cleanTheKitchen(0, 0);

    std::cout << "Is placeToEat's member var 'amountOfMenuItems' equal to 54? " << (placeToEat.amountOfMenuItems == 54 ? "Yes" : "No") << "\n";

    Restaurant::Kitchen cookArea;
    cookArea.fillFryerWithOil(50.75, 2.0, false);
    cookArea.printOrderTicket(5, false);
    cookArea.annualRevenue(359000.52);
    cookArea.replaceTheOven(2, 1);

    std::cout << "Is cookArea's member var 'greaseCollected' set to true? " << (cookArea.greaseCollected == true ? "Yes" : "No") << "\n";

    std::cout << "Is cookArea's member var 'numOfCooks' equal to 3? " << (cookArea.numOfCooks == 3 ? "Yes" : "No") << "\n";

    Bank localBank;
    localBank.serviceClient();
    localBank.collectMoney(258.22);
    localBank.wireMoney(300.f);
    localBank.convertToCanadianDollar(1.f);

    std::cout << "Is localBank's member var 'amountOfMoneyInVault' equal to 0? " << (localBank.amountOfMoneyInVault == 0.0 ? "Yes" : "No") << "\n";

    Case watchCase;
    watchCase.houseInternalComponents();
    watchCase.displayTime(12.25);
    watchCase.keepInternalPartsClean();
    watchCase.removeCase(2);

    std::cout << "Is watchCase's member var 'bezel' equal to 1? " << (watchCase.bezel == 1 ? "Yes" : "No") << "\n";

    Band wristBand;
    wristBand.holdWatchToWrist();
    wristBand.adjustBandTightness();
    wristBand.adjustBandLooseness();
    wristBand.removeBand(1);

    std::cout << "Is wristBand's member var 'links' equal to 9? " << (wristBand.links == 9 ? "Yes" : "No") << "\n";

    Hands watchHands;
    watchHands.displayHours(12.f);
    watchHands.displayMinutes(60.f);
    watchHands.displaySeconds(120.f);
    watchHands.increaseTime(0);

    std::cout << "Is watchHands's member var 'tideDial' equal to 3? " << (watchHands.tideDial == 3.0 ? "Yes" : "No") << "\n";

    AdjustmentDials dials;
    dials.changeTimeForward(1.f);
    dials.changeTimeBackward(12.f);
    dials.useAuxiliaryFunction();
    dials.adjustTheDial(0, 1);

    std::cout << "Is dials's member var 'crown' equal to 120? " << (dials.crown == 120.f ? "Yes" : "No") << "\n";

    Movement mechanisms;
    mechanisms.keepTime();
    mechanisms.makeClickSound();
    mechanisms.adjustTiming();
    mechanisms.movementFunc(1);

    std::cout << "Is mechanisms's member var 'mainWheel' equal to 240? " << (mechanisms.mainWheel == 240.00 ? "Yes" : "No") << "\n";

    WristWatch wholeWatch;
    wholeWatch.displayCurrentTime(10.5);
    wholeWatch.measureTimePast(12.45);
    wholeWatch.changeDisplayedTime();
    wholeWatch.changRate(0, 100);
}
