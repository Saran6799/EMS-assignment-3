Codes for assignment 3


#include <Ticker.h>  
#define pulsePin1 10 
#define pulsePin2 1 
#define led219 
#define ANALOGPIN 4 
#define FILTER_LENGTH 4 
#define MAX_RANGE 3.3 
#define led3 18 
int led1 = 4; // set '4' as signal A 
#define INPUT_PIN 1 // frequency 1 is connected to pin 1
#define INPUT_PIN 5 // frequency 2 is connected to pin 1
#include <B31DGMonitor.h>  
B31DGCyclicExecutiveMonitor monitor; 
#define FRAME_DURATION_MS 4  
float frequencycheck1;
float frequencycheck2;
float analog_samples[FILTER_LENGTH] = {0};  
int sample_index = 0;       

Ticker frameTicker;  
unsigned long frameTime = 0; 
unsigned long frameCounter = 0; 


//-----------------------------------------------------------------------------------------------------
void setup()
{
   Serial.begin(9600);
  pinMode(led1, OUTPUT);  //  led2 pin(sigA) = OUTPUT
  pinMode(pulsePin1, INPUT); 
  pinMode(pulsePin2, INPUT);
  pinMode(led2, OUTPUT); 
  pinMode(led3, OUTPUT); 
  Serial.begin(9600);        
  Serial.println("Ready");  
  monitor.startMonitoring();   
  frameTicker.attach_ms(FRAME_DURATION_MS, frame);  

  
}
//-------------------------------------------------------------------------------

void frame() {
   
   unsigned int slot = frameCounter % 20;  

   switch (slot) {
     case 0:  task_1();            task_3();                            break;
     case 1:  task_1();                      task_4();                  break;
     case 2:  task_1();            task_3();                            break;
     case 3:  task_1(); task_2();                                       break;
     case 4:  task_1();            task_3();                            break;
     case 5:  task_1();                      task_4();                  break;
     case 6:  task_1();            task_3();                            break;
     case 7:  task_1(); task_2();                                       break;
     case 8:  task_1();            task_3();                            break;
     case 9:  task_1();                                                 break;
     case 10: task_1();            task_3();                            break;
     case 11: task_1();                      task_4();                  break;
     case 12: task_1();            task_3();                            break;
     case 13: task_1(); task_2();                                       break;
     case 14: task_1();            task_3();                            break;
     case 15: task_1();                      task_4();                  break;
     case 16: task_1();            task_3();                            break;
     case 17: task_1();  task_2();                                      break;
     case 18: task_1();            task_3();                            break;
     case 19: task_1();                                  task_5();           
     case 20: task1();            task3();                              break;
     case 21: task1();  task2();                                        break;
     case 22: task1();            task3();                              break;
     case 23: task1();                      task4();  task5();          break;
     case 24: task1();            task3();                              break;
     case 25: task1();  task2();                                        break;
     case 26: task1();            task3();                              break;
     case 27: task1();                                                  break;
     case 28: task1();            task3();                              break;
     case 29: task1();                      task4();                    break;
     case 30: task1();            task3();                              break;                        
  }
     frameCounter++;
  
}
//task1 

void task1()
{
      digitalWrite(led1,HIGH);
      delayMicroseconds(200);
      digitalWrite(led1,LOW);
      delayMicroseconds(50);
      digitalWrite(led1,HIGH);
      delayMicroseconds(30);
      digitalWrite(led1,LOW);
}


//task 2
void task2()

{
  
  uint32_t pulse_width = pulseIn(INPUT_PIN, HIGH);// Measure the pulse width

  
  float period = 2 * pulse_width / 1000.0;// Compute the frequency of the pulse
  float frequency = 1000.0 / period;

  
  if (frequency < 333)// Scale the frequency
   {
    frequency = 0;
  }

  
  Serial.print("FREQUENCY: ");// Print the frequency
  Serial.println(frequency);
  
}

//task 3
void task3()

{
 
  uint32_t pulse_width = pulseIn(INPUT_PIN, HIGH); // Measure the pulse width
  float period = 2 * pulse_width / 1000.0;// Compute the frequency of the pulse
  float frequency = 1000.0 / period;

  
  if (frequency < 500) // Scale the frequency
  {
    frequency = 0;
  }

  Serial.print("FREQUENCY: "); // Print the frequency
  Serial.println(frequency);
  delay(8);// delay for 8ms for next reading
}


//task 4
  monitor.startMonitoring(4);// Read the analog input
  
  float analogin = analogRead(ANALOGPIN) * (MAX_RANGE / 1023.0);
  

  analog_samples[sampleindex] = analog_in;  
  sample_index = (sampleindex + 1) % FILTER_LENGTH;
  
  float sum = 0;                          
  
  for (int i = 0; i < FILTER_LENGTH; i++)
   { 
    sum += analog_samples[i];// FILTER_LENGTH =4 it calculate 4 times 
  }
 
  float average_analog_in = sum / FILTER_LENGTH;  //calculating the average 
  

  if (average_analog_in > MAX_RANGE / 2.0) //check the analog input is greater than maximum range
  {
    digitalWrite(led3, HIGH); //led will on
  }
  else 
  {
    digitalWrite(led3, LOW); // led will off
  }
  
  
  Serial.print("Filtered Analog Input: ");// Print the filtered analog signal to the  monitor
  Serial.println(average_analog_in);
  monitor.jobEnded(4);
  
}


//task 5
void task_5()
{
monitor.led2(5);
//For Frequency 1 
{
if (frequencycheck1 <=333 )

{ 
  Serial.println((String)"Reading the Frequency signal by Task 2:(0,0)"); // using frequencycheck1 to get value from frequency in task2 
  }
else if (frequencycheck1>=1000 )
{
    Serial.println((String)"Reading the Frequency signal by Task2:(99,99)");
  }
else {
  float frq1 = (frequencycheck1 / 10); 
  Serial.println((String)"Reading the Frequency signal by Task2:("+frq1+" HZ,"+frq1+ ")"); // setting frequency to 2 digits between 0 to 99  
}

//For Frequency 3
if (frequencycheck2 <=500 )
{
  Serial.println((String)"Reading the Frequency signal by Task3:(0,0)");; // using frequencycheck2 to get value from frequency in task3
  }
else if (frequencycheck2>=1000 ){
    Serial.println((String)"Reading the Frequency signal by Task3:(99,99)");
  }
else {
  float frq2 = (frequencycheck2 / 10);
  Serial.println((String)"Reading the Frequency signal by Task3:("+frq2+" HZ,"+frq2+ ")");   // setting frequency to 2 digits between 0 to 99 
}
monitor.EndMonitoring(5);
 }}
//-----------------------------------------------------------------------------------------------

void loop() {
// remains empty as ticker is used in the setup to call frame function  
}
   