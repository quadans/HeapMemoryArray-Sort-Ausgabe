/*Write the following program: 
CREATE A STRUCT THAT HOLDS A STUDENT’S FIRST NAME AND GRADE (ON A SCALE OF 0-100).
ASK THE USER HOW MANY STUDENTS THEY WANT TO ENTER. dYNAMICALLY ALLOCATE AN ARRAY TO HOLD ALL OF THE STUDENTS. 

Then prompt the user for each name and grade. Once the user has entered all the names and grade pairs, 
sort the list by grade (highest first). Then print all the names and grades in sorted order.*/

#include <iostream>
#include <string>
#include <algorithm>

struct Daten{
	std::string vorname;
	int Note;
};
void sortNames(Daten *array, int length)
{
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		int largestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (array[currentIndex].Note> array[largestIndex].Note)
				largestIndex = currentIndex;
		}
		std::swap(array[startIndex], array[largestIndex]);
	}
}
int main()
{
	int AnzahlStudenten = 0;
	do {
	std::cout << "Wie viele Studenten :";
	std::cin >>AnzahlStudenten;
	} while (AnzahlStudenten <= 1);
	Daten *array = new Daten[AnzahlStudenten];
	
	for (int i = 0; i < AnzahlStudenten; i++)
	{
	std::cout << "Gebe den "<<i<< ". Namen ein: ";
	std::cin >> array[i].vorname;

	std::cout << "Gebe die Note dieses Schuelers ein: ";
	std::cin >> array[i].Note;
	}

	sortNames(array,AnzahlStudenten);
	
	for (int index = 0; index < AnzahlStudenten; ++index)
	std::cout << array[index].vorname<< " got a grade of " << array[index].Note<< "\n";
	delete[] array;
	
	return 0;
}