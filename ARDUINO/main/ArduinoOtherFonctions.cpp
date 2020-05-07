#include "ArduinoOtherFonctions.h"
#include "Arduino.h"



char ** ArduinoOtherFonctions::splitString(char * str, char * delimiters, int * nbResult)
{
    char ** result = NULL;
    int i, j, k;
    int isDelimiter;
    int nbPart = 0;
    
    // Est-ce qu'il y a quelque chose à découper ?
    if(strlen(str) > 0)
    {
        nbPart = 1;
    }
    
    // Compter le nombre de partie dans la chaine à découper :
    for(i = 0; i < strlen(str); i++)
    {
        for(j = 0; j < strlen(delimiters); j++)
        {
            if(str[i] == delimiters[j])
            {
                // Vérification du prochain caractere (ça ne doit pas être un séparateur !)
                isDelimiter = 0;
                if(strlen(str) > i + 1)
                {
                    for(k = 0; k < strlen(delimiters); k++)
                    {
                        if(str[i+1] == delimiters[k])
                        {
                            isDelimiter = 1;
                            break;
                        }
                    }
                }
                else
                {
                    isDelimiter = 1;
                }
                
                if(isDelimiter == 0)
                {
                    nbPart++;
                }
            }
        }
    }
    
    // Si il y a un contenu à découper :
    if(nbPart > 0)
    {
        // Allocation d'un tableau suffisamment grand pour contenir tous les résultats.
        result = malloc(nbPart * sizeof(char*));
        
        // Découpage de la chaine :
        char * token = strtok(str, ",");
        i = 0;
        result[i++] = token;
        while(token != NULL)
        {
            token = strtok(NULL, ",");
            result[i++] = token;
        }
    }
    
    // Retour info nombre de résultat à l'appelant :
    if(nbResult != NULL)
        *nbResult = nbPart;
    
    return result;
}
