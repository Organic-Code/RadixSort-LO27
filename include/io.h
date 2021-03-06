/*****************************************************************************************
 * C Library implementing io functions, in particular for the BaseNIntegerList data type *
 * Written by Lucas LAZARE, lucas.lazare@utbm.fr, December 2015                          *
 *****************************************************************************************/

#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED
#define IO_SPECIAL_CHAR 0x001B

#include <BaseNIntegerList.h>
#include <bool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

/* pure output */

/* Clears the screen */
void Clear(void);

/*
 * Adds/Removes an attribute to the output text
 * @param attribute Attribute to set to the text. Blink may not be available on all terminals
 */
void SetTextAttributes(const char* attribute);

/*
 * Sets a background color for the output text
 * @param color Color choosen as a background color, without any capital letter.
 */
void SetBgColor(const char* color);

/*
 * Sets a font color for the output text
 * @param color Color choosen as a font color, without any capital letter.
 */
void SetTextColor(const char* color);

/*
 * Prints a text at the center of the screen, given its height. Will output nothing if the screen's width is smaller than the text to print
 * @param text  Text to print at the screen
 * @param y_pos Height of the text to print
 */
void CPrint(char* text, unsigned short y_pos);

/*
 * Prints a BaseNIntegerList in a nice way
 * @param l List to be printed
 */
void PrintList(BaseNIntegerList l);

/* input & output */

/*
 * Prints a nice menu where you can navigate using arrow keys, and select with Enter. Some args could be easily added, such as :
 *       border_color(const char*)[one function call to modify]
 *       alignement(enum)[uncommenting + adding if]
 * @param choices    char pointer to a list of the selectable choices. Each choice should end with the '\0' character
 * @param nb_choices number of choices to display. Should not be more than the number of '\0' in 'choices'
 * @param text_color font color of the unselected text
 * @param bg_color   background color of the unselected text
 * @param choice     the default selected choice
 * @return           the index of the choice selected, starting with index 0. 255 if the display was no possible.
 */
unsigned char Menu(const char* choices, unsigned char nb_choices, char* text_color, char* bg_color, unsigned char choice);

/* pure input */

/*
 * Retrieves a user answer to a yes/no question
 * @param question The quetion adressed to the user
 * @param default  1 for Yes as default, -1 for No as default, any other for no default.
 * @return True if user inputed yes, False otherwise
 */
BOOL yes(char* question, char default_ans);

/*
 * Retrieves a number inputed in base i_base
 * @param i_base       input base
 * @return             the inputed number
 */
char* GetNumber(unsigned char i_base, BOOL with_brackets);

/*
 * Retrieve a BaseNIntegerArray using user inputs
 * @param list_array Structure containing an array where to store the inputed list
 */
BaseNIntegerList GetList(void);

/* Gets a char without waiting for the user to input '\n' */
char InstantGetChar(void);

/*
 * Gets a number within a given range
 * @param min minimum value to return
 * @param max maximum value to return
 * @return    value inputed by the user
 */
unsigned long int GetNumberWithinRange(unsigned long int min, unsigned long int max);
/* inner functions */

/*
 * Retrieve the height of the terminal
 * @return height of the terminal
 */
unsigned short ConsoleHeight(void);

/*
 * Retrieve the width of the terminal
 * @return width of the terminal
 */
unsigned short ConsoleWidth(void);

/*
 * Sets the cursor position
 * @param x The x coordinate of the cursor
 * @param y The y coordinate of the cursor
 */
void SetCursorPos(unsigned short x, unsigned short y);

/*
 * Moves the cursor horizontaly
 * @param x number of characters to move. Negative values to go right, positive values to go left
 */
void CursorHorizontalMove(int x);

/*
 * Moves the cursor vertically
 * @param y number of characters to move. Negative values to go top, positive values to go down
 */
void CursorVerticalMove(int y);

/*
 * Sets the output echo of user inputs
 * @param on True to display, false to hide
 */
void SetEcho(BOOL on);

/*
 * Computes number elevated to the power 'power'
 * @param number number that will be elevated
 * @param power  power of the number
 * @return       number ^ power
 */
int power(int number, unsigned int power);

/*
 * Checks if a number stored as a char* is between two given values
 * @param val  Value to check
 * @param min  Lower bound (included)
 * @param max  Upper bound (included)
 * @param base Base in which val is stored
 * @return     TRUE if val is between min and max, FALSE otherwise
 */
BOOL isWithinRange(char* val,unsigned long int min, unsigned long int max, unsigned char base);

/*
 * reverses an array
 * @param array Pointer to the array to reverse
 * @param size  Number of chars to reverse.
 */
void Reverse(char array[], unsigned int size);
#endif /* IO_H_INCLUDED */

