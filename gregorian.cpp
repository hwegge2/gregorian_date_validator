#include <iostream>
#include <string>
using namespace std;

int main()      //this function validates a date given by the user.
{
int month, day, year;   //these variables will be used to store data input by user
bool validDate = true;  //this boolean variable will serve to confirm the day.
bool validYear = true;  //this boolean variable will serve to confirm the year.
bool leapYear;  //this boolean variable will serve to validate loop years.
string monthstr;        //this string will be used to convert the month integer into words.

cout<<"Enter numeric value for month: ";
cin>>month;
cout<<"Enter numeric value for day: ";
cin>>day;
cout<<"Enter numeric value for year: ";
cin>>year;


switch ( month )        //this series of case statements converts the numerical month values to words.
  {
  case 1: monthstr = "January";
    break;
  case 2: monthstr = "February";
          break;
  case 3: monthstr = "March";
          break;
  case 4: monthstr = "April";
          break;
  case 5: monthstr = "May";
          break;
  case 6: monthstr = "June";
          break;
  case 7: monthstr = "July";
          break;
  case 8: monthstr = "August";
          break;
  case 9: monthstr = "September";
          break;
  case 10: monthstr = "October";
          break;
  case 11: monthstr = "Novemeber";
          break;
  case 12: monthstr = "Decemeber";
          break;
 }

if ( year <= 1582)      //validates the year to use the Gregorian calendar.
{
  validYear = false;

}

//validating leap year  //validates leap years
if ( year % 4 == 0 )
  leapYear = true;
else
  leapYear = false;

if ( month <= 7) {      //checks months 1,3,5, and 7 for valid range of days.
  if ((month % 2) == 0) {
  //every second month from February to July contains 31 days.
    if (month == 2)  {
    //this statement deals with the case of leap years in February.
    if (day <= 29 && leapYear)  //if a leap year occurs February has 29 days.
      validDate = true;
    else if ( day <= 28 && !leapYear )  //if it is not a leap year, Februaru has 28 days.
        validDate= true;
else

      validDate = false;
    }
  else if (day > 30)
  validDate = false;
  }
  else {         //this deals with every month second from January to July containing 31 days
  if (day > 31)
  validDate = false;    //checks for errors in date
}
}

else {          //this deals with months after July
if ((month % 2) == 0) {         //every second month from August to December containes 31 days.
if (day > 31)                   //The order in which months have 31 days flip after August.
  validDate = false;    //check for errors in date
}
else {  //every second month from September to November contains 30 days.
if (day > 30)
  validDate = false;
}

}       // logic table creates every possible output using boolean.

if ( validDate && leapYear && validYear ){
  cout<< monthstr.c_str() <<" "<<day<<", "<<year<<" is a date in a leap year." << endl;
}
if ( validDate && !leapYear && validYear ){
   cout<< monthstr.c_str() <<" "<<day<<", "<<year<<" is a date in a non-leap year." << endl;
}
if (!validDate && leapYear && validYear ){
  cout<<month<<"/"<<day<<"/"<<year<<" is not a valid date." << endl;
}
if (!validDate && !leapYear && validYear ){
  cout<<month<<"/"<<day<<"/"<<year<<" is not a valid date." << endl;
}
if ( validDate && leapYear && !validYear ){
  cout<<month<<"/"<<day<<"/"<<year<<" is not a valid date." << endl;
}
if ( validDate && !leapYear && !validYear ){
  cout<<month<<"/"<<day<<"/"<<year<<" is not a valid date." << endl;
}
if ( !validDate && leapYear && !validYear ){
  cout<<month<<"/"<<day<<"/"<<year<<" is not a valid date." << endl;
}
if ( !validDate && !leapYear && !validYear ){
  cout<<month<<"/"<<day<<"/"<<year<<" is not a valid date." << endl;
}

return 0;
}


