#include <Arduino.h>

// This is library for coin sorter bank project
class COUNTER
{
	int data;
public:
	COUNTER(int pin); //Constructor set pin default
	COUNTER();
	void Init(int pin); // Set pin to sensor
	int getSensor(); // Read value from sensor
	int processCount1(); // Process 1 coin
	int processCount5(); // Process 5 coin
	int processCount10(); // Process 10 coin
};

