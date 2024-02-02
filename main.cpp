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
    //5 properties:
    //    - Number of oscillators
    int numberOfOscillators = 3;
    //    - Number of knobs
    int numberofKnobs = 15;
    //    - Amount of voltage per octave
    float amountOfVoltagePerOctave = 0.5f;
    //    - Number of keys
    int numberOfKeys = 88;
    //    - Number of digital displays
    int numberOfDigitalDisplays = 1;

    struct Keyboard
    {
        bool hasEightyEightKeys = true;
        float midiVelocityEnabled = 127.f;
        int numOfBlackKeys = 36;
        std::string synthCompany = "Nord";
        std::string model = "Lead";

        void pushKey(float midiVelocity, int polyphony = 10, bool afterTouch = true);
        void releaseKey(float releaseTime, bool usesADSR = true);
        int getNumOfKeysPressed(int numOfMidiEvents); //3) returns the number of keys pressed
    };

    //3 things it can do:
    //    - Make sound
    void makeSound(Keyboard keyboard);
    //    - Show patch parameters
    void showPatchParameters();
    //    - Adjust sound
    float changeVoltage(float amountOfVoltage, Keyboard keyboard); //returns the current voltage value

    Keyboard eventsOnSynth;
};

struct Bicycle
{
    //5 properties:
    //    - Amount of gears
    int amountOfGears = 12;
    //    - Amount of brake levers
    int amountOfBrakeLevers = 2;
    //    - Number of shifters
    int numberOfShifters = 4;
    //    - Number of wheels
    int numberOfWheels = 2;
    //    - Number of pedals
    int numberOfPedals = 2;
    //3 things it can do:
    //    - Move a person
    void moveBicycle();
    //    - Shift gears
    void shiftGears();
    //    - Stop
    void stopBicycle();
};

struct Restaurant
{
    //5 properties:
    //    - Amount of menu items
    int amountOfMenuItems = 90;
    //    - Name of ingredients per menu item
    std::string nameOfIngredientsPerMenuItem = "Tomatoes, lettuce, cheese, meat, and mayo";
    //    - Number of ovens
    int numberOfOvens = 4;
    //    - Number of employees
    int numberOfEmployees = 10;
    //    - Number of tables
    int numberOfTables = 30;

    struct Kitchen
    {
        //5 member variables with relevant data types.  the names are relevant to the UDT's purpose.
        int numOfCooks = 3;
        int numOfDeepFryers = 2;
        bool greaseCollected = true;
        float gallonsOfVegOil = 20.f;
        std::string orderName = "Lisa";

        void fillFryerWithOil(float amountOfOil, double costOfVegOilPerGallon = 2.0, bool oilNeedsReplaced = false);
        void printOrderTicket(int orderNumber, bool hasSpecialInstructions = false);
        double annualRevenue(float annualProfit); //3) returns the annual revenue
    };

    //3 things it can do:
    //    - Make food
    void makeFood(Kitchen kitchen);
    //    - Serve diners
    void serveDiners(Kitchen kitchen);
    //    - Charge money
    float chargeMoney(float moneyOfMeal); //returns the amount of the bill

    Kitchen patronsBeingServed;
};

struct Bank
{
    //5 properties:
    //    - Amount of money in vault
    double amountOfMoneyInVault = 987654.56;
    //    - Amount of armed guards
    int amountOfArmedGuards = 4;
    //    - Number of customers in line
    int numOfCustomersInLine = 7;
    //    - Number of tellers
    int numOfTellers = 4;
    //    - Amount of accounts
    float amountOfAccounts = 1355.5f;
    //3 things it can do:
    //    - Collect money
    double collectMoney(double amountOfMoneyCollected); //returns amount of money collected
    //    - Service client
    void serviceClient();
    //    - Wire money
    float wireMoney(float amountOfMoneyWired); //returns amount of money wired
};

struct Case
{
    //5 properties:
    //    - Crystal
    int crystal = 1;
    //    - Dial ring
    float dialRing = 10.25f;
    //    - Bezel
    int bezel = 1;
    //    - Date window
    float dateWindow = 1201.f;
    //    - Hands
    int hands = 2;
    //3 things it can do:
    //    - House internal components
    void houseInternalComponents();
    //    - Display time
    float displayTime(float currentTime); //returns current time displayed
    //    - Keep internal components clean
    void keepInternalPartsClean();
};

struct Band
{
    //5 properties:
    //    - Links
    int links = 5;
    //    - Lug
    int lug = 2;
    //    - Pins
    int pins = 9;
    //    - Buckle
    int buckle = 1;
    //    - Adustment
    int adjustment = 1;
    //3 things it can do:
    //    - Holds watch to wrist
    void holdWatchToWrist();
    //    - Tight to wrist
    void adjustBandTightness();
    //    - Loosen on wrist
    void adjustBandLooseness();
};

struct Hands
{
    //5 properties:
    //    - Hour hand
    float hourHand = 12.f;
    //    - Second hand
    float secondHand = 60.f;
    //    - Sweep second hand
    double sweepSecondHand = 120.00;
    //    - Tide dial
    double tideDial = 24.00;
    //    - Arbitrary subdial
    float arbitraryDial = 120.f;
    //3 things it can do:
    //    - Mark number of hours
    float displayHours(float hours); //returns current hour
    //    - Mark number of minutes
    float displayMinutes(float minutes); //returns current minute
    //    - Mark number of seconds
    float displaySeconds(float seconds); //returns current second
};

struct AdjustmentDials
{
    //5 properties:
    //    - Crown
    float crown = 120.f;
    //    - Pusher 1
    float pusher1 = 120.f;
    //    - Reset
    int reset = 1;
    //    - Inner bezel crown
    double innerBezelCrown = 120.00;
    //    - Pusher 2
    double pusher2 = 60.00;
    //3 things it can do:
    //    - Change displayed time forward
    float changeTimeForward(float time); //returns new time
    //    - Change displayed time backward
    float changeTimeBackward(float time); //returns new time
    //    - Activate secondary function
    void useAuxiliaryFunction();
};

struct Movement
{
    //5 properties:
    //    - Main wheel
    double mainWheel = 240.00;
    //    - Fork
    int fork = 4;
    //    - Ratchet wheel
    double ratchetWheel = 120.00;
    //    - Safety roller
    double safetyRoller = 60.00;
    //    - Barrell hub
    int barrellHub = 1;
    //3 things it can do:
    //    - Keep time
    void keepTime();
    //    - Produce clicking noise
    void makeClickSound();
    //    - Adjust timing
    void adjustTiming();
};

struct WristWatch
{
    //5 properties:
    //    - Outer Case
    Case outerCase;
    //    - Band
    Band band;
    //    - Hands
    Hands hands;
    //    - Adjustment dials
    AdjustmentDials adjustmentDials;
    //    - Movement
    Movement movement;
    //3 things it can do:
    //    - Display current time
    float displayCurrentTime(float currentTime); //returns current time
    //    - Measure amount of time past
    double measureTimePast(double time); //returns amount of time past
    //    - Change displayed time
    void changeDisplayedTime();
};







int main()
{
    std::cout << "good to go!" << std::endl;
}
