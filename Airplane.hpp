#ifndef AIRPLANE_HPP
#define AIRPLANE_HPP

class Airplane {
private:
	int airplaneCapacity;
    Airplane& operator=(const Airplane &other);
    Airplane(const Airplane &other);
public:
    Airplane(int capacity);
    int getCapacity() const;
};

#endif
