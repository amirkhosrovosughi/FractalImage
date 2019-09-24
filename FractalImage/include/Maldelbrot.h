#ifndef MALDELBROT_H
#define MALDELBROT_H


class Maldelbrot
{
public:
    static const int Max_Iter = 1000;

    public:
        Maldelbrot();

        static int getIterations(double x,double y);

        virtual ~Maldelbrot();

    protected:

    private:
};

#endif // MALDELBROT_H
