#include <iostream>
#include <ctime>
using namespace std;

int leapYearFeb(int year, int mon) {
        int flag = 0;
        if (year % 100 == 0) {
                if (year % 400 == 0) {
                        if (mon == 2) {
                                flag = 1;
                        }
                }
        } else if (year % 4 == 0) {
                if (mon == 2) {
                        flag = 1;
                }
        }
        return (flag);
  }

void cal_year(int a,int b,int c)
{
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1;
    int year = aTime->tm_year + 1900;

    int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    //check whether leap year or not.. that are leap year february date must be 29
    if(leapYearFeb(b,c))
    {
         a=a+1;
    }
    //calculate part
    int days,months,years;

    days=a+day;
    months=(12-b)+month;
    years=year-c;

    //check years are in leap year

    if(leapYearFeb(years,months)){
            if(days>=day){
             days=days-mon[month-1]+1;
             months=months+1;
            }
    }
    else if(days>=mon[month]){
        days=days-mon[month-1];
        months=months+1;
    }

    if(months>=12){
        //years=years+1;
        months=months-12;
    }


    cout<<"\t your age is: "<<years<<" years, "<<months<<" months, and "<<days<<" days.\n";

}

int main()
{
    int bday,bmonth,byear;
    cout<<"[+]__DEVELOPDE BY:- RANJULA_BANDARA__[+]\n";
    cout << "\n\t enter your birth day following format :- (DD MM YYYY) :";
    cin>>bday>>bmonth>>byear;
    cal_year(bday,bmonth,byear);

    return 0;
}

