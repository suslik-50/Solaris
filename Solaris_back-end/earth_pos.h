#ifndef EARTH_POS_H
#define EARTH_POS_H


class Earth_pos
{
public:Earth_pos();
private: double Earth_X0 (double time) ;
private: double Earth_Y0 (double time) ;
private: double Earth_Z0 (double time) ;
public: double getEarth_X(double time){
        return Earth_X0 (time) ;
    }
public: double getEarth_Y(double time){
        return Earth_Y0 (time) ;
    }
public: double getEarth_Z(double time){
        return Earth_X0 (time) ;
    }

};

#endif // EARTH_POS_H
