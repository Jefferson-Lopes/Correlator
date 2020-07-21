/*
this program alows you to generate a signal for the
cross-correlation circuit and still use your Arduino for
another things. In other words, this program is runnig 
in background.

NOTE: never use delay() in another ports of this program.
*/

#define cons 300
#define OUT1 10
#define OUT2 9
#define CLK 8

String input = "";
bool LED = 0, mode = 0, doing = 0, said = 1;

//memory
bool in1[3] = {};
bool in2[3] = {};

//for make a nonbreak delay
long unsigned var1 = millis(); 
long unsigned var2 = var1 + cons;
long unsigned var3 = var2 + cons;
long unsigned var4 = var3 + cons;
long unsigned var5 = var4 + cons;
long unsigned var6 = var5 + cons;

void generateSignal(void);

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    //digitalWrite(LED_BUILTIN, HIGH);
    if (Serial.available())
        input = Serial.readString();

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


    //Add new code here
    

    delay(1); // to avoid errors
}

void generateSignal(void){
    if (doing){
        //create signal   
        if ((var1 + cons) < millis()){
            var1 = millis();
            //do something
            in1[0] = random(2);
            in2[0] = random(2);
            //clk low
            digitalWrite(OUT1, in1[0]);
            digitalWrite(OUT2, in2[0]);
            digitalWrite(CLK, LOW);
        }

        if ((var2 + cons) < millis()){
            var1 = millis();
            var2 = millis();
            //clk high
            digitalWrite(CLK, HIGH);
        }

        if ((var3 + cons) < millis()){
            var1 = millis();
            var2 = millis();
            var3 = millis();
            //do something
            in1[1] = random(2);
            in2[1] = random(2);
            //clk low
            digitalWrite(OUT1, in1[1]);
            digitalWrite(OUT2, in2[1]);
            digitalWrite(CLK, LOW);
        }

        if ((var4 + cons) < millis()){
            var1 = millis();
            var2 = millis();
            var3 = millis();
            var4 = millis();
            //clk high
            digitalWrite(CLK, HIGH);
        }

        if ((var5 + cons) < millis()){
            var1 = millis();
            var2 = millis();
            var3 = millis();
            var4 = millis();
            var5 = millis();
            
            in1[2] = random(2);
            in2[2] = random(2);

            //clk low
            digitalWrite(OUT1, in1[2]);
            digitalWrite(OUT2, in2[2]);
            digitalWrite(CLK, LOW);
        }

        if ((var6 + cons) < millis()){
            var1 = millis(); 
            var2 = var1 + cons;
            var3 = var2 + cons;
            var4 = var3 + cons;
            var5 = var4 + cons;
            var6 = var5 + cons;
            
            doing = LOW;
            //clk high
            digitalWrite(CLK, HIGH);

            for (int i = 0; i < 3; i++)
                Serial.print(in1[i]);

            Serial.print("\n");

            for (int i = 0; i < 3; i++)
                Serial.print(in2[i]);

            Serial.print("\n\n");
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
