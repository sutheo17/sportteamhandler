#ifndef VEKTOR_HPP
#define VEKTOR_HPP
#include <iostream>

template<typename T>
class Vektor
{
    T* tomb;
    size_t meret;
    size_t kapacitas;
public:
    Vektor() : tomb(NULL), meret(0), kapacitas(0) {}



    Vektor& operator=(Vektor const& v)
    {
        if(this != &v)
        {
            delete[] tomb;
            meret = v.meret;
            kapacitas = v.kapacitas;
            tomb = new T[kapacitas];

            for(size_t i = 0; i<meret; i++)
            {
                tomb[i] = v.tomb[i];
            }
        }
        return *this;
    }

    void berak(T const& adat)
    {
        if(meret >= kapacitas)
        {
            T* temp = new T[kapacitas+=5];
            for(size_t i = 0; i < meret; i++)
            {
                temp[i] = tomb[i];
            }
            delete [] tomb;
            tomb = temp;
        }
        tomb[meret] = adat;
        meret++;
    }

    size_t getkapacitas() const
    {
        return kapacitas;
    }
    size_t getmeret() const
    {
        return meret;
    }

    T* getseq() const
    {
        return tomb;
    }


    T& operator[](size_t idx)
    {
        if(idx >= meret)
        {
            throw "Tulindexeles!";
        }
        return tomb[idx];
    }

    T const& operator[](size_t idx) const
    {
        if(idx >= meret)
        {
            throw "Tulindexeles!";
        }
        return tomb[idx];
    }

    void torol(size_t index)
    {
        if(index+1 == meret)
        {
            T* temp = new T[kapacitas];
            size_t idx = 0;
            for(size_t i = 0; i < meret-1; i++)
            {
                temp[idx] = tomb[i];
                idx++;
            }
            delete[] tomb;
            meret--;
            tomb = temp;
        }
        else if(index == 0)
        {
            T* temp = new T[kapacitas];
            size_t idx = 0;
            for(size_t i = 1; i < meret; i++)
            {
                temp[idx] = tomb[i];
                idx++;
            }
            delete [] tomb;
            meret--;
            tomb = temp;
        }
        else
        {
            T* temp = new T[kapacitas];
            size_t idx = 0;
            for(size_t i = 0; i < meret; i++)
            {
                temp[idx] = tomb[i];
                idx++;
            }
            for(size_t i = index+1; i < meret; i++)
            {
                temp[idx] = tomb[i];
                idx++;
            }
            delete [] tomb;
            meret--;
            tomb = temp;
        }

    }

    ~Vektor()
    {

    }
};

#endif // VEKTOR_HPP
