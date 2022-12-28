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

	if (length_room>1 or length_room<-1)
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



	cout <<file.tellg()<< endl<<endl;

	

	while (1)
	{
		cout;
		while(comms_lab==true){
			comms_lab = comm_lab();
		}
	
		

		
	}
}







































































