#include <Arduino.h>

class COUNTER
{
	int data;
public:
	COUNTER(int pin);
	COUNTER();
	void Init(int pin);
	int getSensor();
	int processCount1();
	int processCount5();
	int processCount10();
};

