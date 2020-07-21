#define cons 1000

String input = "";
bool LED = 0, mode = 0, doing = 0, said = 1;

//for make a nonbreak delay
long unsigned var1 = millis(); 
long unsigned var2 = var1 + cons;
long unsigned var3 = var2 + cons;

void generateSignal(void);

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    //digitalWrite(LED_BUILTIN, HIGH);
    if (Serial.available())
        input = Serial.readString();
/*
    Serial.print(input.length());
    Serial.print("\t.");
    Serial.print(input[(input.length() - 1)]);
*/

    if (input == "start\n"){
        //inverter function
        mode = HIGH;
        input = "";
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("Started");
    }
    else if (input == "stop\n"){
        //invert function
        mode = LOW;
        input = "";
        said = LOW;
        digitalWrite(LED_BUILTIN, LOW);
    }
    else if (input == ""){
        //do nothing        
    }
    else{
        //do nothing
        //print error message(command not find)
        Serial.println("Command not found");
        input = "";
    }

    generateSignal();

    delay(1); // to avoid errors
}

void generateSignal(void){
    if (doing){
        //create signal
        if ((var1 + cons) < millis()){
            var1 = millis();
            //do something
            Serial.println("step 1");
        }

        if ((var2 + cons) < millis()){
            var1 = millis();
            var2 = millis();
            //do something
            Serial.println("step 2");
        }

        if ((var3 + cons) < millis()){
            var1 = millis();
            var2 = var1 + cons;
            var3 = var2 + cons;
            Serial.println("doing = LOW");
            doing = LOW;
        }
    }else if (mode){
        doing = HIGH;
        var1 = millis();
        var2 = var1 + cons;
        var3 = var2 + cons;
    }
    else{
        if(!said){
            said = HIGH;
            Serial.println("Stopped");
        }
    }
}
