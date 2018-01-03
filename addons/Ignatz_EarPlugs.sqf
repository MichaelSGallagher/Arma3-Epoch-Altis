// File created by [Ignatz] - He-Man
// Last Update: 2017-04-06

// Start Config //
Ignatz_KB_Earplug			= 0x3E;		// F4
Ignatz_AutoEarplugs			= true;		// Auto insert / remove Earplugs by entering leaving Vehicles
Ignatz_EnableEarpluginVeh	= true;		// Set it to false to disable manual Earplugs in Vehicles
Ignatz_AutoEarplugsHints	= false;	// Enable / Disable hint message on Auto-Earplugs
Ignatz_EarplugsSystemchat	= true;		// Enable / Disable systemchat messages for Earplugs
// End Config //

Ignatz_Earplugsin = false;
Ignatz_Client_Earplugger = compilefinal "
	if (Ignatz_Earplugsin) then {
		Ignatz_Earplugsin = false;
		1 fadeSound 1;
	}
	else {
		Ignatz_Earplugsin = true;
		1 fadeSound 0.15;
	};
";
