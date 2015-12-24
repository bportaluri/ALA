#include "AlaLed.h"

#include "ExtTlc5940.h"


AlaLed::AlaLed()
{
	maxOut = 255;
	speed = 1000;
	animSeqLen = 0;
	lastRefreshTime = 0;
	refreshMillis = 1000/50;
}



void AlaLed::initPWM(byte pin)
{
	byte *pins_ = (byte *)malloc(1);
    pins_[0] = pin;
    
    initPWM(1, pins_);
}


void AlaLed::initPWM(int numLeds, byte *pins)
{
	this->driver = ALA_PWM;
	this->numLeds = numLeds;
	this->pins = pins;

	for (int x=0; x<numLeds ; x++)
	{
		pinMode(pins[x], OUTPUT);
	}

	// allocate and clear leds array
	leds = (byte *)malloc(numLeds);
	memset(leds, 0, numLeds);
}

void AlaLed::initTLC5940(int numLeds, byte *pins)
{
	this->driver = ALA_TLC5940;
	this->numLeds = numLeds;
	this->pins = pins;

	// allocate and clear leds array
	leds = (byte *)malloc(numLeds);
	memset(leds, 0, numLeds);

	// call Tlc.init only once
	static bool isTlcInit = false;
	if(!isTlcInit)
	{
		Tlc.init(0);
		isTlcInit=true;
	}
}
	


void AlaLed::setBrightness(byte maxOut)
{
	this->maxOut = maxOut;
}

void AlaLed::setRefreshRate(int refreshRate)
{
	this->refreshMillis = 1000/refreshRate;
}


void AlaLed::setAnimation(int animation, long speed)
{
	if (this->animation == animation && this->speed == speed)
		return;
	
	this->animation = animation;
	this->speed = speed;

	setAnimationFunc(animation);
	animStartTime = millis();
}


void AlaLed::setAnimation(AlaSeq animSeq[])
{
	this->animSeq = animSeq;

	// initialize animSeqDuration and animSeqLen variables
    animSeqDuration = 0;
    for(animSeqLen=0; animSeq[animSeqLen].animation!=ALA_ENDSEQ; animSeqLen++)
    {
		animSeqDuration = animSeqDuration + animSeq[animSeqLen].duration;
    }

}

void AlaLed::nextAnimation()
{
	currAnim = (currAnim+1)%animSeqLen;
}

void AlaLed::runAnimation()
{
    // skip the refresh if now enough time has passed since last update
	if (millis() < lastRefreshTime + refreshMillis)
		return;
	lastRefreshTime = millis();
	
	if (animSeqLen != 0)
    {
        // calculate the current animation function
        // NOTE: this can be optimized

        long c = 0;
        for(int i=0; i<animSeqLen; i++)
        {
            long t = millis()%animSeqDuration;   // this loops
			
            if (t>=c && t<(c+animSeq[i].duration))
            {
				setAnimation(animSeq[i].animation, animSeq[i].speed);
				break;
            }
            c = c + animSeq[i].duration;
        }
    }

	// can the animation function and refresh if necessary
    if (animFunc != NULL)
    {
		(this->*animFunc)();

		if(driver==ALA_PWM)
		{
			for(int i=0; i<numLeds; i++)
				analogWrite(pins[i], leds[i]);
		}
		else if(driver==ALA_TLC5940)
		{
			for(int i=0; i<numLeds; i++)
				Tlc.set(pins[i], leds[i]*16);
			
            Tlc.update();
		}
	}
	
}



///////////////////////////////////////////////////////////////////////////////


void AlaLed::setAnimationFunc(int animation)
{
	switch(animation) 
	{
		case ALA_ON:                    animFunc = &AlaLed::on;                    break;
		case ALA_OFF:                   animFunc = &AlaLed::off;                   break;
		case ALA_BLINK:                 animFunc = &AlaLed::blink;                 break;
		case ALA_BLINKALT:              animFunc = &AlaLed::blinkAlt;              break;
		case ALA_SPARKLE:               animFunc = &AlaLed::sparkle;               break;
		case ALA_SPARKLE2:              animFunc = &AlaLed::sparkle2;              break;
		case ALA_STROBO:                animFunc = &AlaLed::strobo;                break;
		
		case ALA_PIXELSHIFTRIGHT:       animFunc = &AlaLed::pixelShiftRight;       break;
		case ALA_PIXELSHIFTLEFT:        animFunc = &AlaLed::pixelShiftLeft;        break;
		case ALA_PIXELBOUNCE:           animFunc = &AlaLed::pixelBounce;           break;
		case ALA_PIXELSMOOTHSHIFTRIGHT: animFunc = &AlaLed::pixelSmoothShiftRight; break;
		case ALA_PIXELSMOOTHSHIFTLEFT:  animFunc = &AlaLed::pixelSmoothShiftLeft;  break;
		case ALA_PIXELSMOOTHBOUNCE:     animFunc = &AlaLed::pixelSmoothBounce;     break;
		case ALA_COMET:                 animFunc = &AlaLed::comet;                 break;
		case ALA_BARSHIFTRIGHT:         animFunc = &AlaLed::barShiftRight;         break;
		case ALA_BARSHIFTLEFT:          animFunc = &AlaLed::barShiftLeft;          break;
		case ALA_LARSONSCANNER:         animFunc = &AlaLed::larsonScanner;         break;
		case ALA_LARSONSCANNER2:        animFunc = &AlaLed::larsonScanner2;        break;
		
		case ALA_FADEIN:                animFunc = &AlaLed::fadeIn;                break;
		case ALA_FADEOUT:               animFunc = &AlaLed::fadeOut;               break;
		case ALA_FADEINOUT:             animFunc = &AlaLed::fadeInOut;             break;
		case ALA_GLOW:                  animFunc = &AlaLed::glow;                  break;
		case ALA_FLAME:                 animFunc = &AlaLed::flame;                 break;
		
		default:                        animFunc = &AlaLed::off;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////
// Switching effects
////////////////////////////////////////////////////////////////////////////////////////////

void AlaLed::on()
{
	for(int i=0; i<numLeds; i++)
	{
		leds[i] = maxOut;
	}
}

void AlaLed::off()
{
	for(int i=0; i<numLeds; i++)
	{
		leds[i] = 0;
	}
}


void AlaLed::blink()
{
	int t = getStep(animStartTime, speed, 2);

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = ((t+1)%2)*maxOut;
	}
}


void AlaLed::blinkAlt()
{
	int t = getStep(animStartTime, speed, 2);

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = ((t+x)%2)*maxOut;
	}
}


void AlaLed::sparkle()
{
    int p = speed/100;
	for(int x=0; x<numLeds; x++)
    {
		leds[x] = (random(p)==0)*maxOut;
    }
}

void AlaLed::sparkle2()
{
    int p = speed/10;
	for(int x=0; x<numLeds; x++)
    {
		if(random(p)==0)
			leds[x] = maxOut;
		else
			leds[x] = leds[x] * 0.88;
    }
}



void AlaLed::strobo()
{
	int t = getStep(animStartTime, speed, ALA_STROBODC);
	
	for(int x=0; x<numLeds; x++)
    {
		leds[x] = (t==0)*maxOut;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////
// Shifting effects
////////////////////////////////////////////////////////////////////////////////////////////

void AlaLed::pixelShiftRight()
{
	int t = getStep(animStartTime, speed, numLeds);

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = (x==t ? 1:0)*maxOut;
	}
}


void AlaLed::pixelShiftLeft()
{
	int t = getStep(animStartTime, speed, numLeds);

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = (x==(numLeds-1-t) ? 1:0)*maxOut;
	}
}


void AlaLed::pixelBounce()
{
	int t = getStep(animStartTime, speed, 2*numLeds-2);

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = (x==(-abs(t-numLeds+1)+numLeds-1) ? 1:0)*maxOut;
	}
}



void AlaLed::pixelSmoothShiftRight()
{
	float t = getStepFloat(animStartTime, speed, numLeds+1);

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = max(0, (int)((-abs(t-1-x)+1)*maxOut));
	}
}


void AlaLed::pixelSmoothShiftLeft()
{
	float t = getStepFloat(animStartTime, speed, numLeds+1);

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = max(0, (int)((-abs(numLeds-t-x)+1)*maxOut));
	}
}


void AlaLed::comet()
{
	float l = numLeds/2;  // length of the tail

	float t = getStepFloat(animStartTime, speed, 2*numLeds-l);

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = (int)constrain( (((x-t)/l+1.2f))*(((x-t)<0)? 1:0)*maxOut, 0, maxOut);
	}
}


void AlaLed::barShiftRight()
{
	int l = numLeds/2+1;  // length of the bar

	int s = getStep(animStartTime, speed, numLeds+l);

	for(int x=0; x<numLeds; x++)
	{
		if(x<s && x>s-l)
			leds[x] = maxOut;
		else
			leds[x] = 0;
	}
}

void AlaLed::barShiftLeft()
{
	int l = numLeds/2+1;  // length of the bar

	int s = map(getStep(animStartTime, speed, 1000), 0, 1000, 0, numLeds+l);

	for(int x=0; x<numLeds; x++)
	{
		if(x<s && x>s-l)
			leds[numLeds-x-1] = maxOut;
		else
			leds[numLeds-x-1] = 0;
	}
}

void AlaLed::pixelSmoothBounce()
{
	// see larsonScanner
	float t = getStepFloat(animStartTime, speed, 2*numLeds-2);

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = constrain((int)((-abs(abs(t-numLeds+1)-x)+1)*maxOut), 0, maxOut);
	}
}


void AlaLed::larsonScanner()
{
	float l = numLeds/4;
	float t = getStepFloat(animStartTime, speed, 2*numLeds-2);

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = constrain((int)((-abs(abs(t-numLeds+1)-x)+l)*maxOut), 0, maxOut);
	}
}

void AlaLed::larsonScanner2()
{
	float l = numLeds/4;  // 2>7, 3-11, 4-14
	float t = getStepFloat(animStartTime, speed, 2*numLeds+(l*4-1));

	for(int x=0; x<numLeds; x++)
	{

		leds[x] = constrain((int)((-abs(abs(t-numLeds-2*l)-x-l)+l)*maxOut), 0, maxOut);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
// Fading effects
////////////////////////////////////////////////////////////////////////////////////////////

void AlaLed::fadeIn()
{
	int s = getStep(animStartTime, speed, maxOut);
	for(int x=0; x<numLeds; x++)
	{
		leds[x] = s;
	}
}


void AlaLed::fadeOut()
{
	int s = getStep(animStartTime, speed, maxOut);
	for(int x=0; x<numLeds; x++)
	{
		leds[x] = abs(maxOut-s);
	}
}


void AlaLed::fadeInOut()
{
	int s = getStep(animStartTime, speed, 2*maxOut) - maxOut;

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = abs(maxOut-abs(s));
	}
}


void AlaLed::glow()
{
	float s = getStepFloat(animStartTime, speed, TWO_PI);

	for(int x=0; x<numLeds; x++)
	{
		leds[x] = (-cos(s)+1)*maxOut/2;
	}
}

void AlaLed::flame()
{
	for(int x=0; x<numLeds; x++)
	{
		if (random(4) == 0)
			leds[x] = map(random(30)+70, 0, 100, 0, maxOut);
	}
}
