//
// Created by Guillermo on 05/11/24.
//

#ifndef TODO_LIST_DATETIME_H
#define TODO_LIST_DATETIME_H

#include <iostream>
#include <stdexcept>

class DateTime {
private:
    short unsigned int year;
    short unsigned int month;
    short unsigned int day;
    short unsigned int hour;
    short unsigned int minutes;

    bool isLeapYear(short unsigned int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // Metodo per verificare se il giorno è valido per il mese specifico
    void validateDate(short unsigned int y, short unsigned int mo, short unsigned int d) {
        if (mo < 1 || mo > 12) {
            throw std::invalid_argument("Month must be between 1 and 12.");
        }

        if (d < 1 || d > 31) {
            throw std::invalid_argument("Day must be between 1 and 31.");
        }

        // Verifica il numero di giorni nel mese
        if (mo == 2) { // Febbraio
            if (isLeapYear(y)) {
                if (d > 29) {
                    throw std::invalid_argument("February has 29 days in a leap year.");
                }
            } else {
                if (d > 28) {
                    throw std::invalid_argument("February has 28 days in a non-leap year.");
                }
            }
        } else if (mo == 4 || mo == 6 || mo == 9 || mo == 11) { // Mesi con 30 giorni
            if (d > 30) {
                throw std::invalid_argument("This month has only 30 days.");
            }
        }
    }

public:
    DateTime(short unsigned int y, short unsigned int mo, short unsigned int d,
             short unsigned int h, short unsigned int mi) : year(y), month(mo), day(d),
                                                            hour(h), minutes(mi) {

        if (h < 0 || h > 23) {
            throw std::invalid_argument("Hour must be between 0 and 23.");
        }

        if (mi < 0 || mi > 59) {
            throw std::invalid_argument("Minutes must be between 0 and 59.");
        }

        validateDate(year, month, day);
    }


    unsigned short getYear() const {
        return year;
    }

    unsigned short getMonth() const {
        return month;
    }

    unsigned short getDay() const {
        return day;
    }

    unsigned short getHour() const {
        return hour;
    }

    unsigned short getMinutes() const {
        return minutes;
    }

};



#endif //TODO_LIST_DATETIME_H
