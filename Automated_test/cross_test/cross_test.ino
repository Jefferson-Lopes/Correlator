//Output pins
#define OUT1 10
#define OUT2 9
#define CLK 8

//Length of input data
#define LENGHT 3

//Set the delay time
#define DELAY 500

//Serial input
String input = "";

//States
bool LED = 0, mode = 0;

//Memory
bool in1[LENGHT] = {};
bool in2[LENGHT] = {};

//Function
void generateSignal(void);
void showSignal(void);

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(0));
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

    if (Serial.available())
        input = Serial.readString();

    if (input == "start\n"){
        mode = HIGH;
        input = "";
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("Started\n\n");
    }
    else if (input == "stop\n"){
        mode = LOW;
        input = "";
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("Stopped");
    }
    else if (input == ""){
        //do nothing        
    }
    else{    //avoid input errors
        Serial.println("Command not found");
        input = "";
    }

    generateSignal();
}

void generateSignal(void){

    if (mode){
        //randomly generates the input numbers
        for (int i = 0; i < sizeof(in1); i++){
            in1[i] = random(2);
            in2[i] = random(2);
        }

        showSignal();
    
        //load the results
        
        delay(DELAY);
        digitalWrite(CLK, LOW);
        digitalWrite(OUT1, in1[0]);
        digitalWrite(OUT2, in2[0]);
        
        delay(DELAY);
        digitalWrite(CLK, HIGH);
        
        delay(DELAY);
        digitalWrite(CLK, LOW);
        digitalWrite(OUT1, in1[1]);
        digitalWrite(OUT2, in2[1]);
        
        delay(DELAY);
        digitalWrite(CLK, HIGH);

        delay(DELAY);
        digitalWrite(CLK, LOW);
        digitalWrite(OUT1, in1[2]);
        digitalWrite(OUT2, in2[2]);
        
        delay(DELAY);
        digitalWrite(CLK, HIGH);
    }
    
}

void showSignal(void){
    Serial.print("Input 1: ");
    for (int i = 0; i < sizeof(in1); i++)
        Serial.print(in1[i]);

    Serial.print("\nInput 2: ");

    for (int i = 0; i < sizeof(in2); i++)
        Serial.print(in2[i]);

    Serial.print("\n\n");
}
