#ifndef OGRE_H_INCLUDED
#define OGRE_H_INCLUDED

#include <vector>
#include <iostream>


class Ogre{
public:
    enum Class{
        WARRIOR,
        ALPHA,
        BETA
    };

    enum Exception{
        UNHANDLED_CLASS_TYPE_TO_OUTPUT,
        UNKNOWN_CLASS_TYPE_TO_READ
    };

private:
    float weight;
    float smellyFactor;

    Class cl;

    std::vector<float> skinThickness;
public:
    friend std::ostream& operator<<(std::ostream& lh,
                         const Ogre& rh);
    friend std::istream& operator>>(std::istream& lh,
                         Ogre& rh);
};

std::ostream& operator<<(std::ostream& lh,
                         const Ogre& rh);
std::istream& operator>>(std::istream& lh,
                         Ogre& rh);

#endif // OGRE_H_INCLUDED
