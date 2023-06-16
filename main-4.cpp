#include <iostream>
#include <string>

using namespace std;
class ServePatient
{
public:
	string *Queue;
	int* id, count = 1, front = -1, rear = -1, check;
	ServePatient(int size)
	{
		Queue = new string[size];
		id = new int[size];
		check = size;
	}
	void RegisterPatient()
	{
		string name;
		if ((front == 0 && rear == check - 1)||(front == rear + 1))
		{
			cout << endl << "PATIENT'S LINE IS FULL" << endl;
			return;
		}
		else if (front == -1||(front == check - 1 && front > rear))
		{
			front = 0;
		}
		else if (rear == check - 1)
		{
			rear = 0;
			cout << "ENTER PATEIENT'S NAME: ";
			cin >> name;
			Queue[rear] = name;
			id[rear] = count;
			count++;
			return;
		}
		cout << "ENTER PATEIENT'S NAME: ";
		cin >> name;
		rear++;
		Queue[rear] = name;
		id[rear] = count;
		count++;
		return;
	}

	void Servepatient()
	{
		string Name;
		if (front == -1)
		{
			cout << endl << "PATIENT'S LINE IS EMPTY" << endl;
		}
		else
		{
			Name = Queue[front];
			cout << endl << "PATIENT ID NO.: " << id[front];
			cout << endl << "PATIENT'S NAME: " << Name;
			cout << endl << "\nSERVED" << endl;
			Queue[front] = "";
			if (front == rear)
			{
				front = -1;
				rear = -1;
			}
			else
			{
				if (front == check - 1)
				{
					front = 0;
				}
				else
				{
					front++;
				}
			}
		}
	}

	void CancelAll()
	{
		front = -1;
		rear = -1;
		cout << endl << "ALL APPOINTMENTS ARE CANCELLED" << endl;
	}

	bool CanDoctorGoHome()
	{
		if (front == -1) {
			cout << endl << "DOCTOR CAN GO HOME";
			return true;
		}
		else
		{
			cout << endl << "DOCTOR CANNOT GO HOME";
			return false;
		}
	}
	void Sorter(string input[],int id[])
	{
			cout << endl << "(WAITING PATIENTS AFTER SORTING IN ALPHABETIC ORDER)" << endl;
			string temp;
			int temp1;
			for (int i = front; i < rear; i++)
			{
				for (int j = front; j < rear; j++)
				{
					if (input[j] > input[j + 1])
					{
						temp = input[j];
						input[j] = input[j + 1];
						input[j + 1] = temp;

						temp1 = id[j];
						id[j] = id[j + 1];
						id[j + 1] = temp1;
					}
				}
			}
			cout << endl << "NAMES\t\tID" << endl;
			for (int j = front; j <= rear; j++)
			{
				cout << input[j] << "\t\t" << id[j] << endl;
			}
			return;
	}
	void ShowAllPatient()
	{
		string *NameCopy;
		int *idCopy;
		NameCopy = new string[check];
		idCopy = new int[check];
		for (int i = 0;i < check;i++)
		{
			NameCopy[i] = Queue[i];
			idCopy[i] = id[i];
		}
		if (front == -1)
		{
			cout << endl << "PATIENT'S LIST IS EMPTY. NOTHING TO SORT" << endl;
		}
		else
		{
			Sorter(NameCopy, idCopy);
		}
	}
};

int main()
{
	int choice, size;
	cout << "PATIENT SERVING MANAGEMENT SYSTEM";
	cout << endl << "_________________________________" << endl << endl << endl;
	cout << "ENTER THE NUMBER OF PATIENTS: ";
	cin >> size;
	ServePatient obj(size);
	do {
		cout << endl << "1. REGISTER PATIENT";
		cout << endl << "2. SERVE THE PATIENT";
		cout << endl << "3. CANCEL ALL APPOINTMENTS";
		cout << endl << "4. DOCTOR CAN GO HOME";
		cout << endl << "5. SHOW ALL PATIENTS";
		cout << endl << "6. EXIT" << endl;
		cout << endl << "ENTER CHOICE: ";
		cin >> choice;
		if (choice == 1)
		{
			obj.RegisterPatient();
			cout << endl << "PATIENT HAS BEEN REGISTERED";
			cout << endl << "______________________________" << endl;
		}	
		else if (choice == 2)
		{
			obj.Servepatient();
			cout << endl << "______________________________" << endl;
		}	
		else if (choice == 3)
		{
			obj.CancelAll();
			cout << endl << "______________________________" << endl;
		}	
		else if (choice == 4)
		{
			obj.CanDoctorGoHome();
			cout << endl << "______________________________" << endl;
		}	
		else if (choice == 5)
		{
			obj.ShowAllPatient();
			cout << endl << "______________________________" << endl;
		}	
		else if (choice >= 6)
			return 0;

	} while (1);
	
}