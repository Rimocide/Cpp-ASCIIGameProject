#include <iostream>
#include<string>
using namespace std;

int comm_lab() {
	string in, first, rest;
	int split, length_room = 0, width_room = 0;
	cout<<"Enter val: ";
	getline(cin, in);
	split  = in.find(" ");
	rest = in.substr(split, sizeof(in));
	first = in.substr(0, split);
	
	if (first=="look")
	{
		if (rest==" up")
		{
			cout<<1;
		}
		else if(rest == " down")
		{
			cout;
		}
		else if (rest==" left")
		{
			cout;
		}
		else if (rest == " right") 
		{
			cout;
		}
	}

	if (first == "walk")
	{
		if (rest == " forward")
		{
			cout;
			length_room+=1;
			cout << length_room;
		}
		else if (rest == " back")
		{
			cout<<0;
			length_room--;
		}
		else if (rest == " right")
		{
			cout<<2;
			width_room++;
			if (width_room>2)
			{
				cout << "You are at the edge of the room.";
				width_room--;
			}
		}
		else if (rest == " left")
		{
			cout;
			width_room--;
		}
	}

	if (length_room>2)
	{
		return false;
	}
	else return true;


}






int main()
{	
	
	bool comms_lab = true;
	while (1)
	{
		cout;
		while(comms_lab){
			comm_lab();
		}
		break;

		
	}
}







































































