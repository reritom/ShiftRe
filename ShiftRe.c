#define R 5    //The number of shift registers

int dataPin = 11;
int latchPin = 10;
int clockPin = 12;
int t = 100;

int bitArray[8] = { 1, 2, 4, 8, 16, 32, 64, 128 }; //for comparing

void setup ()
{
pinMode(dataPin, OUTPUT);
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT); //Set the arduino ports as outputs
}

void loop ()
{
//The main programme using the shift register function is here.
}

void turn_on(int n, int dataArray[R])
{
int i;

if ( n > 0)   //for given number is positive, to turn on
    {
    if ((n <= (R*8)) && (n > 0))
    {
     for (i = 0; i < R; ++i)
          {
           if ((n > (8*i)) && (n<= (8*(i+1))))
                {
                int bit = n - 8*i -1;
                dataArray[i] = dataArray[i] | bitArray[bit];
                }
          }
     }
       digitalWrite(latchPin, 0);
          for (i=R; i>0; --i)
       {
           int s = i - 1;

               shiftOut(dataPin, clockPin, dataArray[s]);

            delay(t);
       }
              digitalWrite(latchPin, 1);
    }

if (n < 0) //for if the  given number is negative, to turn off
    {
    n = -n;
    if ((n <= (R*8)) || (n > 0))
    {
     for (i = 0; i < R; ++i)
          {
           if ((n > (8*i)) && (n<= (8*(i+1))))
                {
                int bit = n - 8*i -1;
                dataArray[i] = (dataArray[i] & (~(dataArray[i] & bitArray[bit])));
                }
          }
     }
              digitalWrite(latchPin, 0);
          for (i=R; i>0; --i)
       {
int s = i - 1;
               shiftOut(dataPin, clockPin, dataArray[s]);

            delay(t);
       }
              digitalWrite(latchPin, 1);
    }
return;
}

void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {

 int i=0;
 int pinState;

 digitalWrite(myDataPin, 0);
 digitalWrite(myClockPin, 0);

 for (i=7; i>=0; i--)  {
    digitalWrite(myClockPin, 0);

    if ( myDataOut & (1<<i) ) {
     pinState= 1;
    }
    else {
     pinState= 0;
    }
    digitalWrite(myDataPin, pinState);
    digitalWrite(myClockPin, 1);
    digitalWrite(myDataPin, 0);
 }
 digitalWrite(myClockPin, 0);
}
