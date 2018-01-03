/*
	a3 epoch trader
	settings.sqf
	by Halv & Suppe

	Copyright (C) 2015  Halvhjearne & Suppe > README.md
*/
//this is to blacklist items you do not want in the blackmarket
_blacklist = [""];

//this is how vehicles spawn, 0 = player gets menu to decide, 1 = only allow saved vehicles, 2 = only allow rentals
_vehiclespawnmode = 0;

//restrict vehicle weaponry here
_restrictedvehicles = [""];
/*
	["vehicleclassname",["weaponclassname1","weaponclassname2","weaponclassname3"]],
*/


//this is to remove all ammo on any vehicle purchase
_clearammo = false;

//this is ammo excluded from above removal
_dontremove =
[
	"Laserbatteries","SmokeLauncherMag_boat","SmokeLauncherMag","300Rnd_CMFlare_Chaff_Magazine","168Rnd_CMFlare_Chaff_Magazine","192Rnd_CMFlare_Chaff_Magazine",
	"240Rnd_CMFlare_Chaff_Magazine","120Rnd_CMFlare_Chaff_Magazine","60Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlareMagazine","120Rnd_CMFlareMagazine",
	"60Rnd_CMFlareMagazine"
];

