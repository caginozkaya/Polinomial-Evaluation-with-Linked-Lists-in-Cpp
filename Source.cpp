#include <iostream>
#include <string>
using namespace std;

template <typename T>
class PolList {

public:
	T nodeValue1;
	T nodeValue2;
	T nodeValue3;
	PolList<T> *next;
	//PolList():next(NULL) {}

	PolList(T item1="0", T item2="X", T item3="0", PolList<T> *nextnode = NULL) :nodeValue1(item1), nodeValue2(item2), nodeValue3(item3), next(nextnode) {}
	
};

template <typename T>
void writeList(PolList<T> *front) {

	PolList<T> *current;
	current = front;
	while (current != NULL) {

		cout << current->nodeValue1 << " " << current->nodeValue2 << " " << current->nodeValue3 << " ";
		if(current->next != NULL)
		cout << "------->";
		current = current->next;
	}
	
}

int main() {

	int choice,count=1,size,i=0,j=0,t;
	string pol;
	string element;
	string powOf;
	string k;
	char plus[] = "+", minus[] = "-", x[]="X",p[]="^";
	PolList<string> *front = NULL; 
	PolList<string> *newNode; 
	PolList<string> *current;
	double val,result=0;
	
	cout << "Enter the polynomial expression:";
	cin >> pol;
	size = pol.size();

	if (pol[0] == minus[0])
		count--;

	for (i = 0; i < pol.size(); i++) {
		if (pol[i] == plus[0] || pol[i] == minus[0])
			count++;					
	}

	for (i = 0; i < count; i++)
	{
		newNode = new PolList<string>("0", "X", "0", front);
		front = newNode;
	}
	
	i = 0;
	current = front;

	if (pol[0] == minus[0])
			i++;

	while (i < size) {		
		if (i != 0)
			if (pol[i - 1] == minus[0]) {
				element.push_back(minus[0]);
						}
			
		while (pol[i] != plus[0] && pol[i] != minus[0] && i < size) {			
			element.push_back(pol[i]);
			i++;		
		}
		i++;
	
		if (element[0] == minus[0]) {//0. eleman - ise			
			if (element[1] == x[0]) {//1. eleman X ise
				current->nodeValue1 = "-1";
				if (element[2] == p[0]) {//2. eleman ^ ise
					for (j = 3; j < element.size(); j++)
						powOf.push_back(element[j]);
					current->nodeValue3 = powOf;
				}//^ degilse
				else
					current->nodeValue3 = "1";

				current = current->next;

			}
			else {//1. eleman sayi ise
				j = 1;
				k.push_back(minus[0]);
				while (element[j] != x[0] && j<element.size()) {
					k.push_back(element[j]);
					j++;
				
				}
				current->nodeValue1 = k;
				if (element[j] == x[0]) {
					if (element[j + 1] == p[0]) {
						for (t = j + 2; t < element.size(); t++) {
							powOf.push_back(element[t]);
						}
							current->nodeValue3 = powOf;
					}
					else {
						current->nodeValue3 = "1";
					}					
				}
				current = current->next;
			}
		}
		else{//0. eleman - degil ise			
			if (element[0] == x[0]) {//0. eleman X ise
				if (element[1] == p[0]) {//1. eleman ^ ise
					for (j = 2; j < element.size(); j++)
						powOf.push_back(element[j]);

					current->nodeValue3 = powOf;
				}//^ degilse
				else
					current->nodeValue3 = "1";

				current = current->next;
			}
			else {//0. eleman sayi ise
				j = 0;				
				while (element[j] != x[0] && j<element.size()) {
					k.push_back(element[j]);
					j++;
				}
				current->nodeValue1 = k;
				if (element[j] == x[0]) {
					if (element[j + 1] == p[0]) {
						for (t = j + 2; t < element.size(); t++) {
							powOf.push_back(element[t]);
						}
						current->nodeValue3 = powOf;
					}
					else {
						current->nodeValue3 = "1";
					}
				}				
				current = current->next;				
			}
		}		
		powOf.clear();
		element.clear();
		k.clear();
		}

	cout << "List representation of the polynomial expression :" << endl;
	writeList(front);	
	cout << endl;	

	while (true) {	
		cout << "Choose an operation:" << endl;
		cout << "1) Polynomial Evaluation" << endl;
		cout << "2) Polynomial Integration" << endl;
		cout << "3) Exit" << endl;
		cin >> choice;
		
		if (choice == 1) {
			cout << "Enter X value:";
			cin >> val;
			current = front;
			while (current != NULL) {
				result += (stod(current->nodeValue1)) * (pow(val, stod(current->nodeValue3)));
				current = current->next;
			}
			cout << "f(" << val << ") = " << result << endl;
			result = 0;
		}
		if (choice == 2) {		
			cout << "List representation of the integrated expression:" << endl;
			current = front;
			while (current != NULL) {			
				current->nodeValue3 = to_string(stod(current->nodeValue3) + 1);
				current->nodeValue1 = to_string(stod(current->nodeValue1) / stod(current->nodeValue3));
				current = current->next;						
			}		
			writeList(front);	
			cout << "-------> 1 C 0" << endl;			
		}
		if (choice == 3)
			break;				
		}	
	//system("pause");
		return 0;
}