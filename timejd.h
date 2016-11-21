#ifndef TIME_H
#define TIME_H


class timejd
{
public: timejd();
public: double get_convert_date(double time_utc);
public: double get_convert_date(double time_utc,int toch);
private: double convert_date(double t);
private: double convert_date(double t,int toch);
private: double roundTo(double inpValue, int inpCount);
private:double DateToJD(int year,int month, int day,int hour, int min,int sec);
private:double DateToJD(int year,int month, int day,int hour, int min,int sec,double toch);
};

#endif // TIME_H
