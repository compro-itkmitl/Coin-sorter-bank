#include <COUNTER.h>
	COUNTER::COUNTER(int pin){
		data = pin;
		pinMode(pin, INPUT);
	}

	COUNTER::COUNTER(){

	}
	// Set pin
	void COUNTER::Init(int pin){
		data = pin;
		pinMode(pin, INPUT);
	}
	// Get value from sensor
	int COUNTER::getSensor(){
		int out = digitalRead(data);
		return out;
	}
	// Process 1 coin and return 1
	int COUNTER::processCount1(){
		return 1;
	}
	// Process 5 coin and return 1
	int COUNTER::processCount5(){
		return 5;
	}
	// Process 10 coin and return 1
	int COUNTER::processCount10(){
		return 10;
	}
