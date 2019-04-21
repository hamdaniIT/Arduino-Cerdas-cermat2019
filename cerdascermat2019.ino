int outA=10;
int outB=11;
int outC=12;
int belPin=9;
int noteDuration=500;
int resPin=0;


void setup()
{
	pinMode(outA, INPUT);
	pinMode(outB, INPUT);
	pinMode(outC, INPUT);
	allLEDOFF();
	
}
void allLEDOFF(){
	digitalWrite(outA, HIGH);
	digitalWrite(outB, HIGH);
	digitalWrite(outC, HIGH);
}

void loop()
{

	int regA=analogRead(A1);
	int regB=analogRead(A2);
    int regC=analogRead(A3);
	if(regA>=0 && regA<=10 ){
		trunOnBel( outA,200);
	}else if(regB>=0 && regB<=10 ){
		
		trunOnBel( outB,250);
	}else if(regC>=0 && regC<=10 ){

		trunOnBel(outC, 300);
	}
	
}

void trunOnBel( int pin,int sound){
    digitalWrite(pin, LOW);
	tone(belPin, sound, noteDuration);
	int pauseBetweenNotes = noteDuration * 1.30;
	delayUser(pauseBetweenNotes);
	noTone(belPin);
	while(true){
		digitalWrite(pin, LOW);
    	if(delayUser(400))break;
        digitalWrite(pin, HIGH);
    	if(delayUser(300))break;
    	
	}
	allLEDOFF();
}
boolean delayUser(int waitduration){
	boolean ret =false;
	for(int i=0;i<=waitduration;i++){
		delay(1);
	    resPin=analogRead(A0);
	    if(resPin>=0 && resPin <=10){
	    	ret=true;
	    }		
	}
	return ret;
}


