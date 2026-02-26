# Notes

## Winner & Losers
- the a's and b's elements number

## The Ford-Johnson algorithm
- All the process happen in a main recursion function `R1`:
	- That recursion is done when no more pairs can be formed.
- Create the main chaine, and pend chaine:
	- Intersted of pairing and making a's and b's elements (winners & losers), by soting (swaping) them.
- Insert elements from the pend to main:
	- We have pairs in both main and pend chaines, we move pairs not single numbers
	- Jacobsthal sequence help us to controle searchig range and numbers of insterted elements
	- Binary search is used to get the position to insert
	- Using Jacobsthal sequence and Binary search == Binary insertion sort


## Jacobsthal sequence used to:
- determine the range of searching (but how ?)
- numbers of inserted elements (Reason ?)
