// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 200;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

const byte numChars = 32;
char receivedChars[numChars];

boolean newData = false;


void setup(){
    // set the speed at 60 rpm:
    myStepper.setSpeed(60);
    // initialize the serial port:
    Serial.begin(9600);
}

void loop(){
    recvWithEndMarker();
    controlMotor();
}


void recvWithEndMarker(){
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;

    while(Serial.available() > 0 && newData == false){
        rc = Serial.read();

        if(rc != endMarker){
            receivedChars[ndx] = rc;
            ndx++;
            if(ndx >= numChars){
                ndx = numChars -1;
            }
        }
        else{
            receivedChars[ndx] = '\0'; // Terminate the string
            ndx = 0;
            newData = true;
        }
    }   
}


void controlMotor(){
    if (newData == true && receivedChars == "Half_Clockwise") {
        // step five revolutions in one direction:
        myStepper.step(144*stepsPerRevolution);
    } else if (newData == true && receivedChars == "Full_Clockwise") {
        // step ten revolutions in one direction:
        myStepper.step(288*stepsPerRevolution);
    } else if (newData == true && receivedChars == "Half_Counterclockwise") {
        // step ten revolutions in one direction:
        myStepper.step(-144*stepsPerRevolution);
    } else if (newData == true && receivedChars == "Full_Counterclockwise") {
        // step ten revolutions in one direction:
        myStepper.step(-288*stepsPerRevolution);
    } else if (newData == true && receivedChars == "Full_Clockwise_Counterclockwise") {
        // step ten revolutions in one direction:
        myStepper.step(288*stepsPerRevolution);
        delay(500);
        // step ten revolutions in the other direction:
        myStepper.step(-288*stepsPerRevolution);
    }    
    delay(500);          
    newData = false;
}
