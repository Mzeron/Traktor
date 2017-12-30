/*
There are 5 strips of neopixles in the tractor:
1. 1 strip 42 leds within the motor chassis as -- motorNeopixles
2. 2 rings "big" 5 cm diameter as headlights in front of the tractor, 12 leds each as -- headNeopixles
3. 2 rings "small" 3 cm diameter as rearlights in the back of the tractor, 8 leds each as -- backNeopixles
4. 1 ring "huge" 10 cm diameter as exhaust light on top of the motor cover of the tractor as -- exhaustNeopixles
5. 1 strip ??50  leds in the interior of the cabine tractor for ambient atmoshere - interiorlNeopixle
*/

#define neoMotorNo       42     //number of leds for engine NeoPixel 
#define neoHeadNo        7     //number of leds for head light NeoPixel
#define neoBackNo         8     //number of leds for back light  NeoPixel
#define neoInteriorNo    50     //number of leds for interior NeoPixel
#define neoExhaostNo     16     //number of leds for exhaost NeoPixel ring 
// constructing 5 classs for each neopixle
Adafruit_NeoPixel neoMotor = Adafruit_NeoPixel(neoMotorNo, neoMotorPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neoHead = Adafruit_NeoPixel(neoHeadNo, neoHeadPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neoBack = Adafruit_NeoPixel(neoBackNo, neoBackPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neoInterior = Adafruit_NeoPixel(neoInteriorNo, neoInteriorPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neoExhaost = Adafruit_NeoPixel(neoExhaostNo, neoExhaostPin, NEO_GRB + NEO_KHZ800);
int i = 0;
int diplayColor = 0;     // diplay on wheel 0-red 1=green 3=yellow fault
int c = 0;

// ----------------   neopixle INITIALIZATION routine  -----------------
void neopixleIni()
{

  neoMotor.begin();           // initilaze the 5 classe
  neoHead.begin();
  neoBack.begin();
  neoInterior.begin();
  neoExhaost.begin();
  
}//---END of INITIALIZATION routine



void runNewPixle()
{
	if (motorOn == ON)
	{
		neoMotorSnakeShow();
		neoHeadSnakeShow(1);		// 0=red 1=green 2=yellow
		neoHeadStop();
//		neoMotorStop();
		//		Serial.println("snake started");
	}
	else
	{
		neoHeadSnakeShow(0);
//		neoHeadStop();
		neoMotorStop();
//		stopAll();
	}
}



void neoMotorSnakeShow()
{
	 if(i< neoMotor.numPixels() ){
		neoMotor.setPixelColor(i, 0, 0,250);
		neoMotor.show();
		i++;
	}
		 else
		 {
			 i = 0;
		 }
}

void neoMotorStop()
{
	for (int i = 0; i< neoMotor.numPixels(); i++)
	{
		neoMotor.setPixelColor(i, 0, 0, 0);
	}
	neoMotor.show();
}





//   Head light  Neopixels  ------

void neoHeadSnakeShow(int c)
{
/*
	neoHead.setPixelColor(2, 0, 155, 0);
	//neoHead.show();
	neoHead.setPixelColor(3, 0, 155, 155);
	//neoHead.show();
	neoHead.setPixelColor(0, 155, 0, 0);
	//neoHead.show();
	neoHead.setPixelColor(1, 0, 0, 150);
	neoHead.show();
*/


		if (i< neoHead.numPixels())
		{
		if (c == 0) {neoHead.setPixelColor(i, 100, 0, 0);}
		else if (c==1) {neoHead.setPixelColor(i, 0, 100, 0);}
		neoHead.show();
		i++;
		}
		else
		{
		i = 0;
		}
}

void neoHeadStop()
{
	for (int i = 0; i< neoHead.numPixels(); i++)
	{
		neoHead.setPixelColor(i, 0, 0, 0);
	}
	neoHead.show();
}

void stopAll()
{
	neoHeadStop();
	neoMotorStop();
}


