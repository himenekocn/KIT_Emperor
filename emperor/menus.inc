/*
 * SourceMod Entity Projects
 * by: Entity
 *
 * Copyright (C) 2020 Kőrösfalvi "Entity" Martin
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) 
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#if defined _emperor_menus_included
	#endinput
#endif
#define _emperor_menus_included

stock void EMP_Menu_SetTitle(Menu menu, const char[] myString, any ...)
{
	int len = strlen(myString) + 255;
	char[] myFormattedString = new char[len];
	VFormat(myFormattedString, len, myString, 3);
	
	menu.SetTitle(myFormattedString);
}

stock void EMP_Panel_SetTitle(Panel TargetPanel, const char[] myString, any ...)
{
	int len = strlen(myString) + 255;
	char[] myFormattedString = new char[len];
	VFormat(myFormattedString, len, myString, 3);
	
	TargetPanel.SetTitle(myFormattedString);
}

stock void EMP_Panel_AddItem(Panel TargetPanel, int ItemDraw = ITEMDRAW_DEFAULT, const char[] myString, any ...)
{
	int len = strlen(myString) + 255;
	char[] myFormattedString = new char[len];
	VFormat(myFormattedString, len, myString, 4);
	
	TargetPanel.DrawItem(myFormattedString, ItemDraw);
}

stock void EMP_Menu_AddItem(Menu menu, int ItemDraw = ITEMDRAW_DEFAULT, char[] id ,const char[] myString, any ...)
{
	int len = strlen(myString) + 255;
	char[] myFormattedString = new char[len];
	VFormat(myFormattedString, len, myString, 5);
	
	menu.AddItem(id, myFormattedString, ItemDraw);
}

stock void EMP_Panel_AddText(Panel TargetPanel, const char[] myString, any ...)
{
	int len = strlen(myString) + 255;
	char[] myFormattedString = new char[len];
	VFormat(myFormattedString, len, myString, 3);
	
	TargetPanel.DrawText(myFormattedString);
}

stock char EMP_Menu_GetSelect(Menu menu, int param)
{
	char cBuffer[32];
	GetMenuItem(menu, param, EMP_STRING(cBuffer));
	return cBuffer;
}

stock void EMP_Panel_Send(Panel TargetPanel, MenuHandler handler, int client, int time = 30)
{
	TargetPanel.Send(client, handler, time);
	delete TargetPanel;
}

stock void EMP_Menu_Send(Menu menu, int client, bool ExitBack = false, bool Exit = true, int time = 30)
{
	menu.ExitBackButton = ExitBack;
	menu.ExitButton 	= Exit;
	menu.Display(client, time);
}

stock void EMP_HandlePanelJunk(Menu menu, MenuAction action)
{
	if (action == MenuAction_End || action == MenuAction_Cancel)
	{
		delete menu;
	}
}

stock void EMP_HandleMenuJunk(Menu menu, MenuAction action)
{
	if (action == MenuAction_End)
	{
		delete menu;
	}
}