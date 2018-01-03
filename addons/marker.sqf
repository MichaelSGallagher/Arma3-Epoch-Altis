if(hasInterface)then{
[] spawn {
		waitUntil{uiSleep 0.2;!isNil "EPOCH_playerEnergyMax"};  //wait for player to load
		_playerPos = createMarkerLocal ["PlayerPOS", position player];  //create marker
		"PlayerPOS" setMarkerTextLocal "You";  // Player marker text eg: You
		"PlayerPOS" setMarkerTypeLocal "mil_dot";  // Player Marker icon
		"PlayerPOS" setMarkerColorLocal "ColorGreen";  
		while{true}do{
			waitUntil {uiSleep 0.2;visibleMap};  //update marker only while map is open
			"PlayerPOS" setMarkerPosLocal position player;
		};
	};
};