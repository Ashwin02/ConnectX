# Ashwin Patil

## List of Bugs:

1. Bug in inbound(int w, int h)

### Summary:

	* In inbound() function negative width value and valid height value produces
		incorrect result.

### Overview/Description:

	* When inbound() function is passed negative width value but a valid height
	  value it returns true.Whereas the function should return false.
	* Under above conditions:
		* When the control reaches inside the first if loop the variable 'inside'
		  is set to false.
		* Next when the control reaches the second if loop for height the 'inside'
		  variable is modified and set to true.
		* When the control reaches the last return statement it returns the most
		  recently modified value of 'inside' that is true.

### Steps to Reproduce:

	* When calling the at() function pass negative 'w' value say -4 and pass it a
	  valid 'h' value say 3.

### Test Result:

	* inbound() returns true ie 1.Whereas it should actually return false ie 0.

2. Bug in placePiece(int column).

### Summary:

	* This is a dependent bug. Since there is a bug in 'inbound' function it will
		also affect the 'placePiece' function.

### Overview/Description:

	* The placePiece function has a call to inbound function.
	* Since inbound function has a bug it will affect the placePiece function as
		well.
	* When we pass a negative column to to the placePiece function.It should fail.
	* But it is impossible to check for that condition since the only way to test
		the function is to check if the player has been toggled when toggleTurn is
		called.
	* And toggelTurn gets called every time irrespective of whether the control
		enters the if loop or not.But that piece can be placed at location which is
		out of bound.
	* It is not possible to write a test case to check that if loop or cover that
		branch in the placePiece function. But since there is a bug in inbound
		function it will most definately fail the placePiece function as well.

### Steps to Reproduce:

	* Pass the negative 'column' value say -10 to placePiece function.

### Test Result:

	* The placePiece function toggels the player correctly.
