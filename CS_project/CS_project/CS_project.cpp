#include <iostream>
#include<string>
#include<fstream>
using namespace std;

int length_room = 0, width_room = 0;
int length_room_2 = 0, width_room_2 = 0;
int length_room_6 = 0,  width_room_6 = 0;
fstream file;


int comm_lab(int dir) {
	string in, first, rest;
	size_t split = 0;
	cout << "> ";


	getline(cin, in);


	split = in.find(" ");
	if (split < 0 or split>50)
	{
		split = 0;
		first = in;
	}
	else 
	{
	rest = in.substr(split, sizeof(in));
	first = in.substr(0, split);
	}
	if (first == "look")
	{
		if (rest == " up")
		{
			cout << "You see countless wires snaking their way across the roof of this lab.\n";
		}
		else if (rest == " down")
		{
			cout << "The floor consists of white metal panels, your shirt is crumpled from lying on the floor.\n";
		}
		else if (rest == " left")
		{
			cout << "There are monitors crowding the workspace table,";
			cout << "a notice board behind the table has a small happy birthday note for your crewmate\n";
		}
		else if (rest == " right")
		{
			cout << "There are tall humming computer units at that end of the room,";
			cout << "these house the ships mainframe\n";
		}
		else
			cout << "I only understood you as far as looking.\n";

	}
	else if (first == "walk")
	{
		if (rest == " forward" and dir==0)
		{
			if (length_room < 1)
			{
				cout << "You stand closer to the door to the rec room, there is a small clock next to the door.";
				cout << "You cannot read the time\n";
			}

			length_room += 1;
		}
		else if (rest == " forward" and dir==1)
		{
			if (length_room<1)
			{
				cout << "You stand in the center of the room, it has never felt more unfamiliar.\n";
			}
			length_room-- ;

		}
		else if (rest == " back")
		{
			if (length_room == 1)
			{
				cout << "You stand closer to the door to the samples testing lab\n";
			}

			length_room -= 1;
		}
		else if (rest == " right")
		{
			width_room += 1;
			if (width_room == 1)
			{
				cout << "You stand before the computer housing units,";
				cout << "There are sparks flying from one of them.\n";
			}


			if (width_room > 1)
			{
				cout << "You are at the edge of the room.\n";
				width_room--;
			}
		}
		else if (rest == " left")
		{
			width_room--;
			if (width_room == -1)
			{
				cout << "You see your reflection in the blank dark screens of the computer.\n";
				cout << "The note on the wall stares questioningly at you. Care to wish your friend a happy birthday ?\n";
			}

			if (width_room < -1)
			{
				cout << "You are at the edge of the room.\n";
				width_room++;
			}

		}
		else
			cout << "Walk where?\n";

	}
	else
		cout << "Not a recognised verb.\n";

	if (length_room>1)
	{
		return 11;
	}
	else if (length_room<0)
	{
		return 10;
	}
	else return 0;


}


int tests_lab(int dir) {
	string in, first, rest;
	size_t split = 0;
	string str;
	bool test_lab = true;

	file.open("six.txt", ios::in);
	file.seekg(ios::beg);


	while (getline(file, str))
	{
		
		cout << str << endl;

	}

	cout << endl << endl;
	cout << "> ";

	getline(cin, in);


	split = in.find(" ");
	if (split < 0 or split>50)
	{
		split = 0;
	}
	rest = in.substr(split, sizeof(in));
	first = in.substr(0, split);

	if (first == "look")
	{
		if (rest == " up")
		{
			cout << "The white ceiling stares back at you.\n";
		}
		else if (rest == " down")
		{
			cout << "Nothing too exciting down there.\n";
		}
		else if (rest == " left")
		{
			cout << "You see a bunch of scientific equipment lying around.\n";
		
		}
		else if (rest == " right")
		{
			cout << "You see various pieces of equipment, such as pipettes, test tubes, and beakers, scattered throughout the room.\n";
		}

	}


	if (first == "walk")
	{
		if (rest == " forward" and dir == 11)
		{
			if (length_room_6 >-1 )
			{
				cout << "You move further into the room, your footsteps echoing off the cold metal floor. You can see a workbench in the center of the room. ";
				cout << "Above the workbench, a row of fluorescent lights provides a pale and ghostly illumination, casting long shadows across the room.\n";
			}

			length_room_6--;
			
		}
		else if (rest == " forward" and dir==10)
		{
			if (length_room_6<1)
			{
				cout << "You move further into the room, your footsteps echoing off the cold metal floor. You can see a workbench in the center of the room. ";
				cout << "Above the workbench, a row of fluorescent lights provides a pale and ghostly illumination, casting long shadows across the room.\n";
				
			}
			length_room_6++;
		}
		else if (rest == " back" and dir ==10)
		{
			if (length_room_6 == 0)
			{
				cout << "You feel a sense of foreboding as you approach the entrance, as if something is waiting for you on the other side. You hesitate for a moment, considering whether to stay in the safety of the lab or go back to where you came from, making no progress at all.\n";
			}
	
			length_room_6--;
		}
		else if (rest == " back" and dir == 11)
		{
			cout << "You move further into the room, your footsteps echoing off the cold metal floor. You can see a workbench in the center of the room. ";
			cout << "Above the workbench, a row of fluorescent lights provides a pale and ghostly illumination, casting long shadows across the room.\n";
			length_room_6++;
		}
		else if (rest == " right")
		{
			width_room_6 += 1;
			if (width_room_6==0)
			{
				cout << "You stand in the center of the room.\n";
			}
	
			
			if (width_room_6 == 1)
			{
				cout << "You see various other pieces of equipment, such as pipettes, test tubes, and beakers, scattered throughout the room.";
				cout << " There is also a sink and fume hood for safely handling and disposing of hazardous materials.\n";
			}


			if (width_room_6 > 1)
			{
				cout << "You are at the edge of the room.\n";
				width_room_6--;
			}
		}
		else if (rest == " left")
		{
			width_room_6--;
			if (width_room_6==1)
			{
				width_room_6--;
			}
			if (width_room_6==0)
			{
				cout << "You are in the center of the room.\n";
				
			}
			

			if (width_room_6<0)
			{
				cout << "As you walk to the left from the center of the testing lab, you are surrounded by a variety of scientific instruments and equipment.\n";
				cout << "You spot a printer and scanner in the corner of the room, along with a small fridge for storing samples and reagents.\n";
			}

			if (width_room_6 < -1)
			{
				cout << "You are at the edge of the room.\n";
				width_room_6++;
			}
		}

	}

	if (length_room_6 > 1)
	{
		return 21;
	}
	else if (length_room_6 <0)
	{
		return 0;
	}
	else return 10;


}

int recreational_room(int dir) {
	string in, first, rest;
	size_t split = 0;
	cout << "> ";


	getline(cin, in);


	split = in.find(" ");
	if (split < 0 or split>50)
	{
		split = 0;
	}
	rest = in.substr(split, sizeof(in));
	first = in.substr(0, split);

	if (first == "look")
	{
		if (rest == " up")
		{
			cout << "You look up at the plain white ceiling devoid of anything.\n";


		}
		else if (rest == " down")
		{
			cout << "As you look at the plain floor, your shaky feet into view.\n";

		}
		else if (rest == " left")
		{
			cout << "You look to your left and find a desk with a gaming console. Beside it is a table with some items on it.\n";
		}
		else if (rest == " right")
		{
			cout << "You look to your right and find the entire wall lined with book shelves.\n";
		}
	}

	if (first == "walk")
	{
		if (rest == " forward")
		{
			cout << "You stand in the middle of the room unsure about where to go next.\n";
			length_room_2 += 1;
			cout << length_room_2;
		}
		else if (rest == " back")
		{
			cout << "You are back at the entrance of the room. Your reflection in the shiny door knob glares back at you.\n";
			length_room_2--;
		}
		else if (rest == " right")
		{
			cout << "You come to a stop before an enormous fully stacked bookshelf towering over you.";
			cout << "A shiver travels up your spine and you cower beneath it.\n";
			width_room_2 += 1;
			if (width_room > 1)
			{
				cout << "You are at the edge of the room.\n";
				width_room_2--;
			}
		}
		else if (rest == " left")
		{
			cout << "You halt before a desk. Resting atop it is a sleek glossy gaming console. An ivory white table accompanies the desk.";
			cout << " Upon looking closely you find a board game lying on it.\n";
			width_room_2--;
			if (width_room_2 < -1)
			{
				cout << "You are at the edge of the room.\n";
				width_room_2++;
			}
		}

	}

	if (length_room_2 > 1)
	{
		return 31;
	}
	else if (length_room_2 < 0)
	{
		return 30;
	}
	else return 0;



}

int main()
{	
	string str;
	int dir = 0, room = 0;
	file.open("one.txt", ios::in);
	file.seekg(ios::beg);

	while (getline(file, str))
	{
		if (str == "0")
		{
			break;
		}
		cout<<str<<endl;
		
	}
	
	cout << endl << endl;
	
	while (1)
	{
		
		if (dir==0)
		{
			while (dir == 0)
			{
				dir = comm_lab(0);
			
			}
		}
		if (dir==10)
		{
			while (dir==10)
			{
				dir = tests_lab(10);
	
			}
			
		}
		if (dir==11)
		{
			dir = recreational_room(11);
		}
	
		

		
	}
}







































































