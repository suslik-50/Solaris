#ifndef TIME_H
#define TIME_H


class timejd
{
public: timejd();
public: double convert_date(double t);
private: double roundTo(double inpValue, int inpCount);
private:double DateToJD(int year,int month, int day,int hour, int min,int sec);
};

#endif // TIME_H
