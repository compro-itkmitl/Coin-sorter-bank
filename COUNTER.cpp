#include <COUNTER.h>
	COUNTER::COUNTER(int pin){
		data = pin;
		pinMode(pin, INPUT);
	}

	COUNTER::COUNTER(){

	}

	void COUNTER::Init(int pin){
		data = pin;
		pinMode(pin, INPUT);
	}

	int COUNTER::getSensor(){
		int out = digitalRead(data);
		return out;
	}

	int COUNTER::processCount1(){
		return 1;
	}

	int COUNTER::processCount5(){
		return 5;
	}

	int COUNTER::processCount10(){
		return 10;
	}
