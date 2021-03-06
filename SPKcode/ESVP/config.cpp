/*
	Title:				SPK_ESVP
	Author:				Sp4rkY [https://github.com/SPKcoding]
	Description:		Extended Safezones with Vehicle Protection for Arma 3 Epoch
	Version:			0.916
	Required:			Arma3 1.66+ / Epoch 0.4+
	File:				config.cpp (clientside config)
____________________________________________________________________________________________________________________________________________________________________________________________________________________*/


class CfgESVP {
	class safezones {															/* Define your safezones here. Can be as many as you want. (no comma after the last entry)											*/
		_defineSafezones[] = {													/* "ID": name of safezone (used for systemChat & accessGUI) | [x,y,z]: coordinates of safezone | rad: radius in meters (Number) 	*/
							{"WEST",	{6190.38,16842.4,0}, 100},				/* {"ID", {x,y,z}, rad},																											*/
							{"CENTER",	{13335.2,14508.6,0}, 100},				/* {"ID", {x,y,z}, rad},																											*/
							{"EAST",	{18461.1,14269.3,0}, 100}				/* {"ID", {x,y,z}, rad}																												*/
		};
	};
	class options {
		_useMarkers			= true;												/* Enable|Disable markers for the safezones at the map 																				*/
		_showNotes 			= true;												/* Show notifications (CfgNotifications) for entering/leaving the safezones															*/
		_showChatMsg 		= true;												/* Show systemChat messages for entering/leaving the safezones																		*/
		_useInfoMsg 		= true;												/* Show info messages while entering a safezone (true/false) 																		*/
		_useVehProt 		= true;												/* Use vehicle protection (if true, only owners can access their vehicles and it´s inventory in safezones)							*/
		_restrictDrv		= true;												/* Restrict driver seat to vehicle owner only [only if _useVehProt=true]															*/
		_useRestDrvMsg		= true;												/* Show systemChat message if joined driver seat [only if _restrictDrv=true]														*/
		_useVehLifted		= true;												/* Use check for lifted vehicles (similar to '_useVehProt' but for lifted/slingloaded vehicles) [only if _useVehProt=true]			*/
		_useSlingMsg		= true;												/* Show info messages while lifting prohibited vehicles in safezone [only if _useVehLifted=true] 									*/
		_useAccessGUI		= true;												/* Use "Access-Menu" for the driver (gain access to others to the vehicle while in safezone) [only if "_useVehProt=true"]			*/
		_usePlayerTP		= false;											/* Teleport players out of safezones at server restart to a random place in given min and max range									*/
		_pPlacePlrTP		= false;											/* Teleport players away from the parking place (if used in serverside settings) at server restart [only if "_usePlayerTP=true"]	*/
		_minRangePlrTP		= 150;												/* Minimum Range in meters the player is teleported to (should be minimum the same as the highest safezone radius) 					*/
		_maxRangePlrTP		= 250;												/* Maximum Range in meters the player is teleported to (have to be higher than "_minRangePlrTP")									*/
		_allowMelee			= false;											/* Enable|Disable melee weapons in safezones (hatchet, sledgehammer, chainsaw) [requires changes in EPOCH_fnc_playerFired.sqf]		*/
	};
	class markers {
		_mainColor			= "ColorGreen";										/* Color of the primary marker (Example: "ColorGreen", "ColorRed", "ColorBlue"...) 													*/
		_brush				= true;												/* Enable|Disable marker brush [if '_useMarkers=true'] 																				*/
		_brushStyle			= "Grid";											/* Set the style of the brush (examples: "Grid", "SolidBorder", "Cross") 															*/
		_useTextMarker		= true;												/* Enable|Disable text marker 																										*/
		_textColor			= "ColorRed";										/* Color of the text marker (Example: "ColorGreen", "ColorRed", "ColorBlue"...) [if '_useTextMarker=true']							*/
		_prefix				= false;											/* Enable|Disable prefix name of the markers 																						*/
		_prefixName			= "Safezone";										/* Define the prefix name here (markertext will be the prefix + ID of _defineSafezones: 'Safezone WEST', 'Safezone CENTER'...) 		*/
		_useUniqueName		= false;											/* If set to true, you will have a unique name for all markers (overrides '_prefix' & 'ID') [if '_useTextMarker=true']				*/
		_uniqueName			= "Safe area";										/* Define the markertext here [if '_useUniqueName=true'] 																			*/
		_textMrkType		= "mil_dot";										/* Type of the icon of the text marker (Example: "_mil_dot", "_mil_warning", "mil_join", "mil_circle"...) 							*/
	};
	class messages {
		class notes {															/* If (_showNotes=true) customise your notification messages below. (between the quotes "")											*/
			_enter[] 		= {"EnterSZ",{"You entered a Safezone!"}};			/* first: template-name (has to be the same as defined in CfgNotifications) | second: text you want to show (for entering the SZ)	*/
			_leave[] 		= {"LeaveSZ",{"You LEFT the Safezone!"}};			/* first: template-name (has to be the same as defined in CfgNotifications) | second: text you want to show (for leaving the SZ)	*/
		};
		class chat {
			_chatMsgEnter 	= "[INFO] YOU ENTERED SAFEZONE:";					/* systemChat message for entering a safezone between the quotes ""	(name of safezone is automatically added)						*/
			_chatMsgLeave 	= "[INFO] YOU LEFT SAFEZONE:";					/* systemChat message for leaving a safezone between the quotes "" (name of safezone is automatically added)						*/
			_restDrvMsg		= "[INFO] DRIVER-SEAT IS RESTRICTED TO THE OWNER";	/* systemChat message while getting ejected from driver seat [only if _restrictDrv=true]											*/
		};
		class info {
			_infoMsg1 		= "safezone: access only to your own vehicle!";		/* Info message while entering a safezone (if _useVehProt=true) [Fires only if _useInfoMsg=true]									*/
			_infoMsg2		= "safezone: take care of your vehicle!";			/* Info message while entering a safezone (if _useVehProt=false) [Fires only if _useInfoMsg=true] 									*/
			_slingMsgOwnr	= "prohibited: you are not the owner!";				/* Info message while rope gets deleted if you are not the owner of the vehicle you want to lift [only if _useVehLifted=true] 		*/
			_slingMsgSteal	= "prohibited: vehicle wasn´t purchased by you!"; 	/* Info message while rope gets deleted if you have not purchased the vehicle you want to lift [only if _useVehLifted=true] 		*/
		};
	};
	class debug {
		_debugLog			= false;											/* Speaks for itself, right? (clientside RPT-log) [recommended: false, use it only if you have to]									*/
	};
};
#include "ctrl\gui.h"
