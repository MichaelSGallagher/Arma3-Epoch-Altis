waitUntil {alive vehicle player};
waitUntil {typeOF player != "VirtualMan_EPOCH"};
waitUntil {!(isNull (findDisplay 46))};

//Status Bar Config and Startup Options

//Choose Options
//--------------------------------------------------------------------------------------------------------------------------------------
_WSC = true;  //Option whether to use and display world space coords in the admin status bar (true or false)


_sb_admin_list = ["76561197987495141"];
//--------------------------------------------------------------------------------------------------------------------------------------

//Start the Status Bar

if ((getPlayerUID player) in _sb_admin_list) then  //admins id here
{
	if (_WSC) then
	{
		[] execVM "addons\status_bar\adminbar_ws.sqf";
	}
	else
	{
		[] execVM "addons\status_bar\adminbar.sqf";
	};
}
else
{
	[] execVM "addons\status_bar\PlayerBar.sqf";
};