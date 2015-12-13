#include "BaseNIntegerList.h"
#include "BaseNIntegerListOfList.h"
#include "io.h"
#include <stdio.h>

typedef struct{
	unsigned char size;
	BaseNIntegerList* lists;
}ArrayOfList;

int main(void);
void listsMenu(ArrayOfList list_array);
void conversionsMenu(void);
void listOfListsMenu(/*ArrayOfList list_array*/void);
void extraMenu(/*ArrayOfList list_array*/void);
ArrayOfList IAIEAFI(ArrayOfList list_array);
ArrayOfList addList(ArrayOfList list_array);
unsigned char listSelector(unsigned char arraySize);

int main()
{
	unsigned char user_choice = 0;
	ArrayOfList list_array;

	list_array.size = 0;
	list_array.lists = NULL;

	do {
		Clear();
		SetTextAttributes("+bold");
		user_choice = Menu("- Input a list\0- Lists related functions\0- Conversion functions\0- List of lists related functions\0- Extra functions\0Exit\0", 6, "white", "blue", user_choice);
		SetTextAttributes("reset");

		switch (user_choice) {
		case 0:
			list_array = addList(list_array);
			break;
		case 1:
			listsMenu(list_array);
			break;
		case 2:
			conversionsMenu();
			break;
		case 3:
			listOfListsMenu(/*list_array*/);
			break;
		case 4:
			extraMenu(/*list_array*/);
			break;
		default:
			break;
		}
	}while (user_choice != 5);

	Clear();
	return EXIT_SUCCESS;
}

void listsMenu(ArrayOfList list_array)
{
	unsigned char user_choice = 0;
	do {
		Clear();
		SetTextAttributes("+bold");
		user_choice = Menu("- IsEmpty()\0- InsertHead()\0- InsertTail()\0- RemoveHead()\0- RemoveTail()\0- DeleteIntegerList()\0- SumIntegerList()\0- PrintList()\0Back\0", 9, "white", "blue", user_choice);
		SetTextAttributes("reset");
		Clear();
		if (user_choice != 8)
			list_array = IAIEAFI(list_array);

		switch (user_choice) {
		case 0:
			if (list_array.size != 0) {
				unsigned char selected_list;
				selected_list = listSelector(list_array.size);

				if (IsEmpty(list_array.lists[selected_list])) {
					printf("List%u is empty.\n", selected_list);
				}
				else {
					printf("List%u isn't empty.\n", selected_list);
				}
				(void)InstantGetChar();
			}
			break;

		case 1:
		case 2:
			if (list_array.size != 0) {
				char* val;
				unsigned char selected_list;
				selected_list = listSelector(list_array.size);

				printf("Enter the value you want to add below : (base %d)\n", list_array.lists[selected_list].base);
				val = GetNumber(list_array.lists[selected_list].base, FALSE);
				if (val != NULL) {
					if (user_choice == 1)
						list_array.lists[selected_list] = InsertHead(list_array.lists[selected_list], val);
					else
						list_array.lists[selected_list] = InsertTail(list_array.lists[selected_list], val);
					printf("Value added to list%u\n", list_array.size - 1);
				}
				else {
					printf("Nothing to be done...\n");
				}
				(void)InstantGetChar();
			}
			break;
		case 3:
		case 4:
			if (list_array.size != 0){
				unsigned char selected_list;
				selected_list = listSelector(list_array.size);
				if (user_choice == 3)
					list_array.lists[selected_list] = RemoveHead(list_array.lists[selected_list]);
				else
					list_array.lists[selected_list] = RemoveTail(list_array.lists[selected_list]);
				printf("Done\n");
				(void)InstantGetChar();
			}
			break;
		case 5:
			if (list_array.size != 0) {
				unsigned char selected_list;
				selected_list = listSelector(list_array.size);
				DeleteIntegerList(list_array.lists[selected_list]);
				printf("Done.\nList%u will remain as an empty list.\n", selected_list);
				(void)InstantGetChar();
			}
			break;
		case 6:
			if (list_array.size != 0) {
				unsigned char selected_list;
				char* s;
				selected_list = listSelector(list_array.size);
				s = SumIntegerList(list_array.lists[selected_list]);
				Reverse(s, (unsigned int)strlen(s));
				printf("All what's in list%u makes %s (result given in base %u)", selected_list, s, list_array.lists[selected_list].base);
				free (s);
				(void)InstantGetChar();
			}
			break;
		case 7:
			if (list_array.size != 0) {
				unsigned char selected_list;
				selected_list = listSelector(list_array.size);
				(void)InstantGetChar();
				PrintList(list_array.lists[selected_list]);
				(void)InstantGetChar();
			}
			break;
		default:
			break;
		}
	}while (user_choice != 8);
}

void conversionsMenu()
{
	unsigned char user_choice = 0;
	do {
		Clear();
		SetTextAttributes("+bold");
		user_choice = Menu("- ConvertBaseToBinary()\0- ConvertBinaryToBase()\0Back\0", 3, "white", "blue", user_choice);
		SetTextAttributes("reset");

		switch (user_choice) {
		case 0:
			/* TODO Convertbasetobinary */
			break;
		case 1:
			/* TODO Convertbinarytobase */
			break;
		default:
			break;
		}
	}while (user_choice != 2);
}

void listOfListsMenu(/*ArrayOfList list_array*/)
{
	unsigned char user_choice = 0;
	do {
		Clear();
		SetTextAttributes("+bold");
		user_choice = Menu("- CreateBucketList()\0- BuildBucketList()\0- BuildIntegerList()\0- AddIntegerToBucket()\0- DeleteBucketList()\0- RadixSort()\0PrintList()\0Back", 8, "white", "blue", user_choice);
		SetTextAttributes("reset");

		switch (user_choice) {
		case 0:
			/* TODO Createbucketlist */
			break;
		case 1:
			/* TODO Buildbucketlist */
			break;
		case 2:
			/* TODO Buildintegerlist */
			break;
		case 3:
			/* TODO Addintegerlisttobucket */
			break;
		case 4:
			/* TODO Deletebucketlist */
			break;
		case 5:
			/* TODO RadixSort */
			break;
		case 6:
			/* TODO PrintList */
			break;
		default:
			break;
		}
	}while (user_choice != 7);
}

void extraMenu(/*ArrayOfList list_array*/)
{
	unsigned char user_choice = 0;
	do {
		Clear();
		SetTextAttributes("+bold");
		user_choice = Menu("- ConvertBaseToBase()\0- ConvertListBase()\0- Sumbase()\0Back\0", 4, "white", "blue", user_choice);
		SetTextAttributes("reset");

		switch (user_choice) {
		case 0:
			/* TODO ConvertBaseToBase */
			break;
		case 1:
			/* TODO ConvertListBase */
			break;
		case 2:
			/* TODO SumBase */
			break;
		default:
			break;
		}
	}while (user_choice != 3);
}

ArrayOfList addList(ArrayOfList list_array)
{
	++list_array.size;
	list_array.lists = (BaseNIntegerList*) realloc(list_array.lists, list_array.size*sizeof(BaseNIntegerList));
	list_array.lists[list_array.size - 1] = GetList();
	printf("List saved as list %d\n", list_array.size - 1);
	return list_array;
}

ArrayOfList IAIEAFI(ArrayOfList list_array)
{
	if (list_array.size == 0) {
		char ui;
		printf("You don't have any list !\nDo you want to input one ? [Y/n]");
		ui = InstantGetChar();
		if (ui != 'n' && ui != 'N') {
			list_array = addList(list_array);
			InstantGetChar();
		}
	}	
	return list_array;
}

unsigned char listSelector(unsigned char arraySize)
{
	char* user_in;
	unsigned char selected_list;
	if (arraySize == 1) {
		printf("Using list0 [this is the only one you have]\n\n");
		selected_list = 0;
	}
	else {
		printf("Which list do you want to use ? [list0 to list%u]\n", arraySize - 1);
		do {
			user_in = GetNumber(10, FALSE);
			if (isWithinRange(user_in, 0, (unsigned char)(arraySize - 1), 10)) {
				selected_list = (unsigned char)strtol(user_in, NULL, 10);
			}
			else {
				printf("\r                                          \r");
				user_in = NULL;
			}
		}while (user_in == NULL);
		printf("\n");
	}
	return selected_list;
}