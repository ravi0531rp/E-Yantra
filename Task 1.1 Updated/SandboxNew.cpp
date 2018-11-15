
#include "NS_Task_1_Sandbox.h"

/*
*
* Function Name: forward_wls
* Input: node
* Output: void
* Logic: Uses white line sensors to go forward by the number of nodes specified
* Example Call: forward_wls(2); //Goes forward by two nodes
*
*/
void forward_wls(unsigned char node)
{
	unsigned char ls, cs, rs;
	int c = 0;
	while (c <= int(node)) {
		ls = ADC_Conversion(1);
		cs = ADC_Conversion(2);
		rs = ADC_Conversion(3);
		printf("\n %d     %d     %d  c= %d", ls, cs, rs, c);
		forward();


		if (ls > 230 && cs > 230 && rs > 230) {
			c += 1;
			_delay_ms(98);  // comment this out if not necessary
		}
	}
}
	

/*
*
* Function Name: left_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn left until black line is encountered
* Example Call: left_turn_wls(); //Turns right until black line is encountered
*
*/
void left_turn_wls(void)
{
	left();
	_delay_ms(200);
	while (ADC_Conversion(2) < 200);
	stop();
}

/*
*
* Function Name: right_turn_wls
* Input: void
* Output: void
* Logic: Uses white line sensors to turn right until black line is encountered
* Example Call: right_turn_wls(); //Turns right until black line is encountered
*/
void right_turn_wls(void)
{
	
	right();
	_delay_ms(250);
	while (ADC_Conversion(2) < 200);
	stop();

		
	
}
/*
*
* Function Name: Square
* Input: void
* Output: void
* Logic: Use this function to make the robot trace a square path on the arena
* Example Call: Square();
*/
int t = 440;
int t2 = 2000;
void Square(void)
{
	forward();
	_delay_ms(t2);
	left();
	_delay_ms(t);
	forward();
	_delay_ms(t2);
	left();
	_delay_ms(t);
	forward();
	_delay_ms(t2);
	left();
	_delay_ms(t);
	forward();
	_delay_ms(t2);
	stop();
	left();
	_delay_ms(t);



}
void line_follow(void)
{
	unsigned char ls, cs, rs;

	while (1) {

		ls = ADC_Conversion(1);
		cs = ADC_Conversion(2);
		rs = ADC_Conversion(3);
		printf("\n %d     %d     %d", ls, cs, rs);
		if (ls < 200 && cs >= 230 && rs < 200)
		{
			forward();
			//_delay_ms(1000);
		}

		if (ls < 200 && cs < 200 && rs >= 230)
		{
			soft_right();
			//_delay_ms(1000);
		}

		if (ls >= 230 && cs >= 230 && rs < 200)
		{
			soft_left();

			//_delay_ms(1000);
		}

		if (ls < 200 && cs < 200 && rs < 200)
		{
			forward();

			//_delay_ms(1000);
		}

		if (ls < 200 && cs < 200 && rs >= 230)
		{
			soft_right();

			//_delay_ms(1000);
		}
		if (ls < 200 && cs >= 230 && rs >= 230)
		{
			soft_right();

			//_delay_ms(1000);
		}

		if (ls >= 230 && cs < 200 && rs < 200)
		{
			soft_left();

			//_delay_ms(1000);
		}

		if (ls >= 230 && cs >= 230 && rs >= 230)
		{
			break;

			//_delay_ms(1000);
		}



	}



}

/*
*
* Function Name: Task_1_1
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.1 logic
* Example Call: Task_1_1();
*/
void Task_1_1(void)
{
	_delay_ms(100);
	

	forward_wls(1);  // path 1 covered
	right_turn_wls(); // take right

	forward_wls(1); // path 2 covered
	left_turn_wls(); // take right

	line_follow(); // use line follow algorithm as the path turns continuously, path 3 covered
	forward_wls(1); // skip the node
	left_turn_wls(); // take left

	line_follow(); // similar to path 3, path 4 is covered with accuracy using line_follow
	forward_wls(1); // skip the node
	left_turn_wls(); // take left

	line_follow();
	forward_wls(1);
    right_turn_wls(); // take right

	line_follow(); // cover the curved path using line follow, path 6 covered
	forward_wls(1); // skip the node

	line_follow(); // cover the curved path using line follow, path 7 covered
	forward_wls(1); // skip the node

	line_follow(); // cover the curved path using line follow, path 8 covered
	forward_wls(1); // skip the node

	right_turn_wls(); // take right
	line_follow();  // as the turn is sharp, there might be some errors, hence using line_follow to cover path 9
	forward_wls(1); // skip the node

	left_turn_wls(); // take next left
	line_follow(); // follow the curved path 10
	//forward_wls(1); // skip the node
	
	left_turn_wls(); // take next left
	line_follow(); // follow the curved path 11
	forward_wls(1); // skip the node

	//velocity(200, 200); // decrease the velocity for close calls
	left_turn_wls(); // take slow left
	line_follow(); // follow the line , path 12 covered

	
	

	forward();
	_delay_ms(300);
	line_follow();

	right();
	_delay_ms(500);
	line_follow(); // path 13 covered 
	forward_wls(1);
	stop();
}
/*
*
* Function Name: Task_1_2
* Input: void
* Output: void
* Logic: Use this function to encapsulate your Task 1.2 logic
* Example Call: Task_1_2();
*/
void Task_1_2(void)
{

}




