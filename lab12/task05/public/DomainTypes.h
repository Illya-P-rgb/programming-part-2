#ifndef DOMAINTYPES_H
#define DOMAINTYPES_H

class Sample {
private:
    int amplitude_;
    double timestamp_;

public:
    Sample();
    Sample(int amplitude, double timestamp);

    int getAmplitude() const;
    double getTimestamp() const;
};

#endif