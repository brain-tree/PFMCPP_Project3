 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    void run(int howFast, bool startWithLeftFoot);

    struct Foot
    {
        void stepForward();
        int stepSize();
    };

    Foot leftFoot;
    Foot rightFoot;
};

void Person::Foot::stepForward()
{
    std::cout << "stepped forward!\n";
}

int Person::Foot::stepSize()
{
    return 5;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward(); // returns void
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize(); // returns int
    howFast = distanceTraveled - howFast;
}



 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

/*
paste your code below
*/

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
    std::cout << "good to go!" << std::endl;
}
