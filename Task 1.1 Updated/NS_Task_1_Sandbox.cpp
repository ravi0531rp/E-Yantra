
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
			printf("\n %d     %d     %d  c= %d", ls, cs, rs,c);
			forward();


			if (ls > 230 && cs > 230 && rs > 230) {
				c += 1;
				//_delay_ms(100);  // comment this out if not necessary
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
	soft_left();
	_delay_ms(200);
	//stop();
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
	/*
	unsigned char ls, cs, rs;



	//int c = 0;

	while (!(!ADC_Conversion(1) && ADC_Conversion(2) && !ADC_Conversion(3))) {
		ls = ADC_Conversion(1);
		cs = ADC_Conversion(2);
		rs = ADC_Conversion(3);
		printf("\n %d     %d     %d  ", ls, cs, rs);
		soft_right();



		
	}
	*/
	forward();
	_delay_ms(100);
	right();
	_delay_ms(420);
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
	_delay_ms(1);
	int count_node = 0;

	forward_wls(2);  // path 1 covered
	count_node += 1;

	right_turn_wls(); // turn right
	forward_wls(2);  // path 2 covered
	count_node += 1;
	_delay_ms(300);
	stop();

	
	left_turn_wls(); // turn left
	nn();  // path 3 covered

	left();  // turn left
	_delay_ms(200);
	forward();
	_delay_ms(200);
	nn();// path 4 covered
	forward();
	_delay_ms(200);

	left(); // turn left
	_delay_ms(250);
	//forward();
	//_delay_ms(200);
	nn(); // path 5 covered

	forward();
	_delay_ms(200);
	right(); // turn right sharp
	_delay_ms(400);
	//forward();
	_delay_ms(200);
	nn(); // path 6 covered

	forward(); //
	_delay_ms(200);
	nn(); // path 7 covered

	forward(); //
	_delay_ms(200);
	nn(); // path 8 covered

	forward();
	_delay_ms(250);
	right();
	_delay_ms(700);
	nn(); // path 9 covered 

	forward();
	_delay_ms(200);

	left(); // turn left
	_delay_ms(450);
	//forward();
	//_delay_ms(200);
	nn(); // path 10 covered

	forward();
	_delay_ms(200);
	left();
	_delay_ms(200);
	nn(); // path 11 covered
	forward();
	_delay_ms(300);

	left();
	_delay_ms(200);

	velocity(150, 150);
	forward();

	_delay_ms(200);

	nn(); // path 12 covered

	forward();
	_delay_ms(300);
	right();
	_delay_ms(500);
	nn(); // path 13 covered 
	forward();
	_delay_ms(265);
	stop();
	// comment this out
	_delay_ms(10000);
	
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

		if (ls>= 230 && cs >= 230 && rs< 200)
		{
			soft_left();

			//_delay_ms(1000);
		}

		if (ls<200 && cs< 200 && rs < 200)
		{
			back();

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



	}
	


}

void nn(void) {
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