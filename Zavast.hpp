/*
	        ,. –  - .,  °                       ,.,   '          ,.-.                                  ,.,   '                   ,. -,             ,  . .,  °    
        ';_,.., _     '`. '                 ;´   '· .,        /   ';\ '                             ;´   '· .,            ,.·'´,    ,'\      ;'´    ,   ., _';\'  
         \:::::::::::';   ,'\              .´  .-,    ';\     ';    ;:'\      ,·'´';                .´  .-,    ';\      ,·'´ .·´'´-·'´::::\'    \:´¨¯:;'   `;::'\:'\ 
          '\_;::;:,·´  .·´::\‘           /   /:\:';   ;:'\'    ';   ;::;     ,'  ,''\              /   /:\:';   ;:'\'   ;    ';:::\::\::;:'       \::::;   ,'::_'\;' 
              , '´ .·´:::::;'           ,'  ,'::::'\';  ;::';    ';   ';::;   ,'  ,':::'\'          ,'  ,'::::'\';  ;::';   \·.    `·;:'-·'´              ,'  ,'::;'  ‘   
            .´  .'::::::;·´'        ,.-·'  '·~^*'´¨,  ';::;     ';   ;:;  ,'  ,':::::;'      ,.-·'  '·~^*'´¨,  ';::;    \:`·.   '`·,  '              ;  ;:::;  °   
        .·´ ,·´:::::;·´            ':,  ,·:²*´¨¯'`;  ;::';      ;   ;:;'´ ,'::::::;'  '     ':,  ,·:²*´¨¯'`;  ;::';      `·:'`·,   \'               ;  ;::;'  ‘    
     ,·´  .´;::–·~^*'´';\‚        ,'  / \::::::::';  ;::';      ';   '´ ,·':::::;'          ,'  / \::::::::';  ;::';       ,.'-:;'  ,·\              ;  ;::;'‚      
     '.,_ ,. -·~:*'´¨¯:\:\ °    ,' ,'::::\·²*'´¨¯':,'\:;        ,'   ,.'\::;·´           ,' ,'::::\·²*'´¨¯':,'\:;   ,·'´     ,.·´:::'\             ',.'\::;'‚      
      \:::::::::::::::::::\;      \`¨\:::/          \::\'        \`*´\:::\;     ‘        \`¨\:::/          \::\'    \`*'´\::::::::;·'‘             \::\:;'‚      
       \:;_;::-·~^*'´¨¯'         '\::\;'            '\;'  '       '\:::\;'                 '\::\;'            '\;'  '   \::::\:;:·´                   \;:'      ‘  
                                     `¨'                            `*´‘                    `¨'                        '`*'´‘                         °   
																			Copyright @Cydrav of V3rmillion.
												If you do decide to use this, feel free to give credit, even though I know most of you won't.
																				THIS IS IN EARLY BETA!																					*/








#include <Windows.h>

#pragma once

#define DestroyAddress			0x4F1230
#define CAAddress				0x4ECDE0
#define RBLAddress				0x4F2520;
#define ContextAddress			0xDEADBEEF //might sell a method to raise global context to 7
#define SetPropertyAddress		0x4F0A10

#define ANCHORED_PROP			0x16319C4
#define TRANSPARENCY_PROP		0x163EAA0
#define SHADOWCOLOR_PROP		0x162F66C
#define WATERCOLOR_PROP			0x1636B84
#define TEAMCOLOR_PROP			0x1630D24
#define GLOBALSHADOWS_PROP		0x162F90C
#define WALKSPEED_PROP			0x162E040
#define NAMEDISPLAY_PROP		0x162EEB0
#define NAMEOCCULSION_PROP		0x162EE38
// i was to lazy to compile any of this



namespace Zavast
{

	namespace Calls // will be removed in the next version, planning on doing some thing else with this...
	{
		typedef void(__stdcall *Destroy)(int self); //might not work, not sure if they implemented checks or not
		Destroy destroy = (Destroy)DestroyAddress;
		typedef void(__stdcall *ClearAllChild)(int self);
		ClearAllChild ClearAllChildren = (ClearAllChild)CAAddress;
		typedef void(__stdcall *RobloxLock)(int self, bool isRobloxLocked);
		RobloxLock RobloxLocked = (RobloxLock)RBLAddress;
		typedef void(__stdcall *setP)(int self, DWORD prop);
		setP SetProperty = (setP)SetPropertyAddress;
	};
	namespace functions
	{
			bool Destroy(int self)
			{
				return ((self + 32)); // thanks hex-rays // and also im just testing this, not sure if it will work
			}

			bool DestroyCall(int self)
			{
				Zavast::Calls::destroy(self);
				return true;
			}
	};
	namespace Properties
	{
			bool setAnchored(int sel, bool s)
				{
					s = (sel + 196);
					Zavast::Calls::SetProperty(sel, ANCHORED_PROP);
					return true;
				}
				bool setTransparency(int sel, float transparency)
				{
					transparency = (sel + 128);
					Zavast::Calls::SetProperty(sel, TRANSPARENCY_PROP);
					return true;
				}
				bool setShadowColor(int sel, int color, int color2, int color3)
				{
					color = (sel + 364);
					color2 = (sel + 368);
					color3 = (sel + 372);
					Zavast::Calls::SetProperty(sel, SHADOWCOLOR_PROP);
					return true;
				}
				bool setWaterColor(int sel, int color, int color2, int color3)
				{
					color = (sel + 280);
					color2 = (sel + 284);
					color3 = (sel + 288);
					Zavast::Calls::SetProperty(sel, WATERCOLOR_PROP);
					return true;
				}
				bool setTeamColor(int sel, int color)
				{
					color = (sel + 76);
					Zavast::Calls::SetProperty(sel, TEAMCOLOR_PROP);
					return true;
				}
				bool setGlobalShadows(int sel, bool isGS)
				{
					isGS = (sel + 460);
					Zavast::Calls::SetProperty(sel, SHADOWCOLOR_PROP);
					return true;
				}
	};
	namespace Humanoid 
	{
	
			bool setWalkspeed(int sel, float Walkspeed)
			{
				Walkspeed = (sel + 412);
				Walkspeed = (int)Walkspeed ^ (int)Walkspeed;
				Zavast::Calls::SetProperty(sel, WALKSPEED_PROP);
				return true;
			}
			bool setNameDisplayDistance(int sel, float Distance)
			{
				Distance = (sel + 496);
				Zavast::Calls::SetProperty(sel, NAMEDISPLAY_PROP);
				return true;
			}
			bool setNameOcclusion(int sel, int Occlusion)
			{
				Occlusion = (sel + 488);
				Zavast::Calls::SetProperty(sel, NAMEOCCULSION_PROP);
				return true;
			}
	};
	namespace getProps {
	
			bool getRobloxLocked(int self)
				{
					bool isRobloxLocked = ((self + 35));
					if (isRobloxLocked == true) {
						return true;
					}
					else {
						return false;
					}
		
				}
			bool getGlobalShadows(int sel)
				{
					bool GlobalShadows = (sel + 460);
					return GlobalShadows;
				}
			bool getAnchored(int sel)
			{
				bool Anchored = (sel + 196);
				return Anchored;
			}

	};

};




