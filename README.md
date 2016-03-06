# Zavast-Library

This is a library of C++ functions dedicated to exploiting vulnerabilites within the game 'ROBLOX', it is very poorly coded, please forgive me for that part. But mostly functional none the less.

#Current Functionality

The current working functions as of 3/6/2016 are
  1. Get Functions (for getting values of certain variables)
  * getRobloxLocked(int self)
  * getGlobalShadows(int self)
  * getAnchored(int self)
  2. Humanoid Functions (for editing properties of the humanoid)
  * setWalkspeed(int sel, float Walkspeed)
  * setNameDisplayDistance(int sel, float Distance)
  * setNameOcclusion(int sel, int Occlusion)
  3. Generic instance modifiers (setters)
  * setAnchored(int sel, bool isAnchored)
  * setTransparency(int sel, float transparency)
  * setShadowColor(int sel, int color, int color2, int color3)
  * setWaterColor(int sel, int color, int color2, int color3)
  * setTeamColor(int sel, int color)
  * setGlobalShadows(int sel, bool isGS)
        	+ MORE TO COME!

#Example Usage

```
bool GlobalShadows = Zavast::Properties::setGlobalShadows(lighting, true); // setting the value of GlobalShadows to true
	if (GlobalShadows) {
		bool worked = Zavast::getProps::getGlobalShadows(lighting);
		if (worked == true) {
			cout << "Changed GlobalShadows to 'true'!" << endl;
		}
	}
```

#Goal

I plan to sometime make this a standalone library in which you would not need to help of any other external lib to execute the functions that this will soon enough have.

#Future Plans

- [ ] Built-in scanning system
- [ ] More Automation
- [ ] Misc Functions

#Q&A

* __How long are you going to update this?__
* 
  I will attempt to update it whenever i have the time, it is currently hard for me due to ACTs coming up.

* __I still don't get it, can you help me out?__
* 
  If I find the time, yes, message me on V3rmillion. @Cydrav

* __Can I Donate?__
* 
  Yeah! If you feel the need to donate, again, private message me on v3rm and I will give you a paypal email to send it to.


