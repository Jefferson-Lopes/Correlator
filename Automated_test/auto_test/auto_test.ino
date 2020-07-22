//Output pins
#define OUT 10
#define CLK 8

//Length of input data
#define LENGHT 3

//Set the delay time
#define DELAY 500

//Serial input
String input = "";

//State
bool mode = 0;

//Memory
bool in[LENGHT] = {};

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
        Serial.print("Started\n\n");
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
        for (int i = 0; i < sizeof(in); i++)
            in[i] = random(2);

        showSignal();
    
        //load the results
        
        delay(DELAY);
        digitalWrite(CLK, LOW);
        digitalWrite(OUT, in[0]);
        
        delay(DELAY);
        digitalWrite(CLK, HIGH);
        
        delay(DELAY);
        digitalWrite(CLK, LOW);
        digitalWrite(OUT, in[1]);
        
        delay(DELAY);
        digitalWrite(CLK, HIGH);

        delay(DELAY);
        digitalWrite(CLK, LOW);
        digitalWrite(OUT, in[2]);
        
        delay(DELAY);
        digitalWrite(CLK, HIGH);
    }
    
}

void showSignal(void){
    Serial.print("Input: ");
    
    for (int i = 0; i < sizeof(in); i++)
        Serial.print(in[i]);

    Serial.print("\n\n");
}
