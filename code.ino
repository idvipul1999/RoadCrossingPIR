
int Green1=4, Red1=2, Yellow1=3;
int  pirpin = 7;
int pirstatus = 0;
int piezo = 13;


void setup()
{
  
  pinMode(Red1, OUTPUT);
  pinMode(Yellow1, OUTPUT);
  pinMode(Green1, OUTPUT);
  pinMode(pirpin, INPUT);  //connected to 7
  pinMode(piezo,OUTPUT);//12
  Serial.begin(9600);
  
}

void loop()
{ 
  greenhigh();
  yellowhigh();
  redhigh(); 
} 

void greenhigh()
{	//high for 12 seconds
	digitalWrite(Green1,HIGH);
  	pirstatus = digitalRead(pirpin);
	
  for(int i=0; i<1200 ; i++)
  {
      pirstatus = digitalRead(pirpin);
      if(pirstatus == HIGH)
      {
        tone(piezo,500,500);
      }
      delay(10);
  }//key element
  
  	digitalWrite(Green1,LOW);
}

void yellowhigh()
{	//high for 7 sec
	digitalWrite(Yellow1,HIGH);
  
   for(int i=0; i<700 ; i++)
   {
    pirstatus = digitalRead(pirpin);
  	if(pirstatus == HIGH)
    {
      tone(piezo,500,100);
    }
    delay(10);
  }//key element
  	
  	digitalWrite(Yellow1,LOW);
}
void redhigh()
{	// high for 5sec
	digitalWrite(Red1,HIGH);
  	
  	delay(2000);
  	digitalWrite(Red1,LOW);
}

  
