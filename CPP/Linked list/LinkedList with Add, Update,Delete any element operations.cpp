#include<iostream>
#include <windows.h>
using namespace std;
struct Node {
	int Data;
	Node* Next;
	Node() //Constructor to initilize the data member and pointer to zero and null
	{
		this->Data = 0;
		this->Next = NULL;
	}
	Node(int data)  //Parameterized Constructor to initlize the Node data value
	{
		this->Data = data;
		this->Next = NULL;
	}
};
class Singlylinklist {
private:
	Node* Head;
	Node* Check;
public:
	Singlylinklist() //Constructor to initlize the Head pointer to NULL
	{
		this->Head = NULL;
		this->Check = NULL;
	}
	Singlylinklist(Node* n) //Constructor to initlize the Head pointer to the node n
	{
		this->Head = n;
		this->Check = NULL;
	}
	Node* Search(int key)  //This Member Functions is used to search in the Singlylink list and return the Address of that node if it exists
	{
		Node* temp = Head;
		Node* search = NULL;
		while (temp != NULL)
		{
			if (temp->Data == key)
			{
				search = temp;
				return search;
			}
			temp = temp->Next;
		}
		return search;
	}
	void Add_node(int data)  //This Member function add the node as Head and at last after the head node is declared
	{
		if (this->Search(data) != NULL)
		{
			cout << "Node Already exist with this DATA VALUE " << endl;
		}
		else
		{
			Node* n = new Node();
			n->Data = data;
			if (this->Head == NULL)
			{
				this->Head = n;
				cout << "Singly LinkList of CLUE GAME was Empty" << endl;
				cout << "Node is added as the HEAD node in Singly Linklink of Clue Game" << endl;
			}
			else
			{
				Node* temp = Head;
				while (temp->Next != NULL)
				{
					temp = temp->Next;
				}
				temp->Next = n;
				cout << "Node is added at the End of Singly Linklist of Clue Game" << endl;
			}
		}
	}
	void Update(int data) //This member Function is used to update the value of a specfied node if it exists
	{
		int Data;
		Node* temp = this->Search(data);
		if (temp == NULL)
		{
			cout << "No Node Exist with this Data value to update it" << endl;
		}
		else
		{
			cout << "Enter the value to update = ";
			cin >> Data;
			temp->Data = Data;
			cout << "Node's Data Value is Updated to " << temp->Data << endl;
		}
	}
	void Delete_Node(int key) //This Member function is used to delete a node by its Data value if it exists in Singly Linklist
	{
		Node* temp = this->Search(key);
		if (temp == NULL)
		{
			cout << "No Node Exist with this Data value to Delete it" << endl;
		}
		else
		{
			Node* search = Head;
			while (search->Next != temp)
			{
				search = search->Next;
			}
			search->Next = temp->Next;
			cout << "Node with Address (" << temp << ") and Data value " << temp->Data << " is Sucessfully Deleted from Singlylink list" << endl;
		}
	}
	void Insert_Node(int find) //This Member function is used to insert node in place of ead,tai or between two nodes
	{
		Node* temp = this->Search(find);
		if (temp == NULL)
		{
			cout << "Node with this Data Value Does Exit to Update it " << endl;
		}

		else
		{
			Node* n = new Node();
			int data;
			cout << "Enter value to new Node to insert = ";
			cin >> data;
			if (this->Search(data) != NULL)
			{
				cout << "Node with this Data Value Already Exsits" << endl;
			}
			else
			{
				n->Data = data;
				if (temp == Head)
				{
					n->Next = Head;
					Head = n;
					cout << "Node is Inserted as the HEAD NODE in Singly Link List of Clue Game" << endl;
				}
				else {
					if (temp->Next == NULL)
					{
						temp->Next = n;
						cout << "Node is Inserted at the END OF SINGLY LINKLIST" << endl;
					}
					else
					{
						n->Next = temp->Next;
						temp->Next = n;
						cout << "Node is Sucessfully INSERTED " << endl;
					}
				}
			}

		}
	}
	void Display() //This Function is used to display all the Singly linklist of Clue game
	{
		Node* temp = Head;
		while (temp != NULL)
		{
			cout << "(" << temp->Data << "," << temp->Next << ")->";
			temp = temp->Next;
		}
		cout << endl;
	}
	
	
	// Now All These Functions are related to the CLUE Game in which we will search Display and check the Right Wrong Clues 
	
	void Display_Clue() //This Member Function will display the first Clue and will move the pointer to next pointer
	{
		Check = Head;
		cout << Head->Data;
		Check = Check->Next;
	}
	void Clue_MoveNext() //This Member Function is used to move to the next pointer to check the next clue of the game
	{
		Check = Check->Next;
	}
	bool Check_Clue(int key) //This Member Functions checks weather the clue of End User is Right or Wrong and Display's the specfied Message on Console
	{
		if (key == Check->Data && Check->Next!=NULL)
		{
			Beep(1000, 100);
			cout << "Congratulations !!! Your Clue is Right " << endl;
			Clue_MoveNext();
			return 1;
		}
		else if (key == Check->Data && Check->Next == NULL)
		{
		Beep(2000, 100);
			cout << "CONGRATULATION's !!! You have Solved all the Clue's" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!! GAME END !!!!!!!!!!!!!!!!!!!!!!" << endl;
			return 0;
			
		}
		else
		{
			cout << "Your Clue is Wrong" << endl;
			return 1;
		}
	}
};
int main()
{
	int optionForADMINORGAME=1;
	int optionForADMIN;
	int optionForGAME;
	int data;
	int clue;
	Singlylinklist s;
		if (optionForADMINORGAME == 1)
		{
			cout << "Enter 1 to Add Node" << endl;
			cout << "Enter 2 to Insert Node after a Node" << endl;
			cout << "Enter 3 to Update Node " << endl;
			cout << "Enter 4 to Delete Node" << endl;
			cout << "Enter 5 to Display All Node" << endl;
			cout << "Enter 0 to exit Admin Mode" << endl;
			cout << endl << "Enter Option = ";
			cin >> optionForADMIN;
			cout << endl;
			while (optionForADMIN != 0)
			{
				if (optionForADMIN == 1)
				{
					cout << "Enter New Node Data Value = ";
					cin >> data;
					s.Add_node(data);
				}
				else if (optionForADMIN == 2)
				{
					cout << "Enter Node value After which you want to INSERT New Node = ";
					cin >> data;
					s.Insert_Node(data);
				}
				else if (optionForADMIN == 3)
				{
					cout << "Enter the Node's Data Value whom you want to UPDATE = ";
					cin >> data;
					s.Update(data);
				}
				else if (optionForADMIN == 4)
				{
					cout << "Enter the Node's value whom you want to DELETE = ";
					cin >> data;
					s.Delete_Node(data);
				}
				else if (optionForADMIN == 5)
				{
					s.Display();
				}
				else
				{
					cout << "Invalid Input Option !!!" << endl;
				}
				cout << endl << "Enter Option = ";
				cin >> optionForADMIN;
			}
		}

	return 0;
}
