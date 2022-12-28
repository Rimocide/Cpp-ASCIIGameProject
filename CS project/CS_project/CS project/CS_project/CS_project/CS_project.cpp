#include <iostream>
#include<string>
#include<fstream>
using namespace std;

int length_room = 0, width_room = 0;
fstream file;


int comm_lab() {
	string in, first, rest;
	size_t split = 0;
	cout<<"> ";


	getline(cin, in);


	split  = in.find(" ");
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
			cout << "You countless wires snaking their way across the roof of this lab.\n";
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
	
	}


	if (first == "walk")
	{
		if (rest == " forward")
		{
			if (length_room<1)
			{
				cout << "You stand closer to the door to the rec room, there is a small clock next to the door.";
				cout << "You cannot read the time\n";
			}
			
			length_room+=1;
		}
		else if (rest == " back")
		{
			if (length_room==1)
			{
				cout << "You stand closer to the door to the samples testing lab\n";
			}
			cout<<0;
			length_room--;
		}
		else if (rest == " right")
		{
			if (length_room==0)
			{
				cout << "You stand before the computer housing units,";
				cout << "There are sparks flying from one of them.\n";
			}
			
			width_room+=1;
			if (width_room>1)
			{
				cout << "You are at the edge of the room.\n";
				width_room--;
			}
		}
		else if (rest == " left")
		{
			cout;
			width_room--;
			if (width_room<-1)
			{
				cout << "You are at the edge of the room.\n";
				width_room++;
			}
		}

	}

	if (length_room>1 or length_room<0)
	{
		return false;
	}
	else return true;


}






int main()
{	
	string str;
	bool comms_lab = true;
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



	cout << endl<<endl;

	

	while (1)
	{
		cout;
		while(comms_lab==true){
			comms_lab = comm_lab();
		}
	
		

		
	}
}







































































