// Helper functions for music

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include "helpers.h"
#include <string.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if(fraction[0] == '1')
    {
        if(fraction[2] == '8')
        {
            return 1;
        }
        else if(fraction[2] == '4')
        {
            return 2;
        }
        else if(fraction[2] == '2')
        {
            return 4;
        }
        else if(fraction[2] == '1')
        {
            return 8;
        }
    }
    else if(fraction[0] == '3' && fraction[2] == '8')
    {
        return 3;
    }
    else
    {
        return 0;
    }
    return 0;
}

int frequency(string note) {
    char nota = note[0];

    char modificador = ' ';
    char octava;

    if(note[1] == '#' || note[1] == 'b') {
        modificador = note[1];
        octava = note[2];
    } else {
        octava = note[1];
    }

    int baseFrequency = 440;
    double noteFrequency = 0;

    // si la nota es "A4"
    if(nota == 'A' && octava == '4' && modificador == ' ') {
        return baseFrequency;
    } else {
        // --------------
        // Calculo la distancia de octavas
        // --------------

        int iOctave;
        int fullOctave = 12;
        iOctave = atoi(&octava);
        int octaveMovementsFrom4 = iOctave - 4;
        int totalOctaveSemitones = fullOctave * abs(octaveMovementsFrom4);
        //printf("octaveMovementsFrom4:::: %d\n", octaveMovementsFrom4);

        // --------------
        // Declaro la variable totalSemitones que voy a usar más abajo
        // --------------

        int totalSemitones = 0;

        // --------------
        // Calculo la diferencia de semitonos entre la nota y A
        // --------------

        int semitoneDistanceFromA = 0;

        switch(nota) {
            case 'A' :
                // Es un semitono de A
                semitoneDistanceFromA = 0;
                // Si la octava es mayor a 4
                break;
            case 'B' :
                // Es un semitono de B
                semitoneDistanceFromA = 2;
                break;
            case 'C' :
                // Es un semitono de C
                semitoneDistanceFromA = 9;

                break;
            case 'D' :
                // Es un semitono de D
                semitoneDistanceFromA = 7;
                break;
            case 'E' :
                // Es un semitono de E
                semitoneDistanceFromA = 5;

                break;
            case 'F' :
                // Es un semitono de F
                semitoneDistanceFromA = 4 ;

                break;
            case 'G' :
                // Es un semitono de G
                semitoneDistanceFromA = 2 ;

                break;
            default :
                semitoneDistanceFromA = 0;
        }

        //printf("semitoneDistanceFromA:::: %d\n", semitoneDistanceFromA);

        // --------------
        // Calculo los semitonos con Modificadores
        // --------------


            if(modificador == '#') {
                if(nota == 'A') {
                   semitoneDistanceFromA = semitoneDistanceFromA + 1;
                } else {
                   semitoneDistanceFromA = semitoneDistanceFromA - 1;
                }
            } else if(modificador == 'b') {
                if(nota == 'B') {
                   semitoneDistanceFromA = semitoneDistanceFromA - 1;
                } else {
                   semitoneDistanceFromA = semitoneDistanceFromA + 1;
                }
                //printf("semitoneDistanceFromA:::: %d\n", semitoneDistanceFromA);
            }

        //printf("semitoneDistanceFromA >>> %d\n", semitoneDistanceFromA);

        // --------------
        // Calculo el TOTAL de semitonos por nota + semitonos por octava
        // --------------

        if(iOctave > 4) {
            // Si los semitonos son a la izquierda de A
            if(nota != 'B' && nota != 'A') {
                totalSemitones = totalOctaveSemitones - semitoneDistanceFromA;
            } else if(nota == 'A' && modificador == '#') {
                totalSemitones = totalOctaveSemitones + semitoneDistanceFromA;
            } else if(nota == 'A' && modificador == 'b') {
                totalSemitones = totalOctaveSemitones - semitoneDistanceFromA;
            }
            // Si los semitonos son a la derecha de A
            else {
                totalSemitones = totalOctaveSemitones + semitoneDistanceFromA;
            }
        } else if(iOctave < 4) {
            if(nota != 'B' && nota != 'A') {
                totalSemitones = totalOctaveSemitones + semitoneDistanceFromA;
            }  else if(nota == 'A' && modificador == '#') {
                totalSemitones = totalOctaveSemitones - semitoneDistanceFromA;
            } else if(nota == 'A' && modificador == 'b') {
                totalSemitones = totalOctaveSemitones + semitoneDistanceFromA;
            }
            // Si los semitonos son a la derecha de A
            else {
                totalSemitones = totalOctaveSemitones - semitoneDistanceFromA;
            }
        } else {
            totalSemitones = semitoneDistanceFromA;
        }

        //printf("Total de semitonos: %d\n", totalSemitones);



        // --------------
        // Calculo el resultado de la potencia de acuerdo a los semitonos
        // --------------

        double exponent = (double)totalSemitones / (double)12;
        double powerResult = pow(2, exponent);

        // si la octava es mayor a 4, la nota es B4 o la nota es A#4
        if(octava > '4' || (nota == 'B' && octava == '4') || (nota == 'A' && modificador == '#' && octava == '4')) {
            //for(int i = 0; i < totalSemitones; i++) {
                noteFrequency = baseFrequency * powerResult;
                //printf("Para octavas mayores a 4: %f\n", noteFrequency);
            //}
            // noteFrequency = powerResult * baseFrequency;
        } else if(octava < '4' || nota != 'B') {
            //for(int i = 0; i < totalSemitones; i++) {
                noteFrequency = baseFrequency / powerResult;
                //printf("Para octavas menores a 4: %f\n", noteFrequency);
            //}
        }

    }

    // --------------
    // Redondeo el resultado en función a los decimales
    // --------------

    double integral;
    double fractional = modf(noteFrequency, &integral);


    if(fractional > 0.5) {
        return ceil(noteFrequency);
    } else {
        return floor(noteFrequency);
    }

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strncmp(s, "", 1)) {
        return false;
    }
    else{
        return true;
    }
}