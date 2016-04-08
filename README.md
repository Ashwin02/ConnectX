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
