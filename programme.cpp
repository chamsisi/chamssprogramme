#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>

constexpr int MAX_Etudiants = 200;
enum class Mention {
    ajourne,
    passable,
    assezbien,
    bien,
    tresbien
};
 int main ()
 {
    std::string ue;
    int nombreEtudiants;

   //  1.saisie du nom de l'UE
     
    std::cout <<"entrez le nom de l'UE :";
    std::getline(std::cin, ue);

   //  2.saisie du nombres d'etudiants 
    
    std::cout << "entrez le nombre d'etudiants (1 a 200) :";
    std::cin >> nombreEtudiants;

    while (std::cin.fail() || nombreEtudiants < 1 || nombreEtudiants > MAX_Etudiants){
    
    std::cin.clear();

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "nombre invalide. reesayez:";
    std::cin >> nombreEtudiants;
    }
  // 3. tableau des notes

    double notes [MAX_Etudiants]{};
    // 4.saisie des notes 

    for(int i = 0;i < nombreEtudiants; i++){
    std::cout <<"notes de l'etudiants " << i+1 <<" : ";
    std::cin >> notes[i];
while (std::cin.fail() || notes[i] > 20 ){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout <<"notes invalide. reesayez : ";
    std::cin >> notes[i];
    }
 }
    //5. minimum et maximum 

    double minimum = notes[0];
    double maximum = notes[0];

    for(int i=1 ; i < nombreEtudiants; i++){

    if (notes[i] < minimum){
    minimum =  notes[i];
    } 
   if (notes[i]> maximum){
    maximum = notes[i];
    } 
  }
   // 6.calcul de la moyenne 

    double somme = 0.0;
for(int i = 0;i  < nombreEtudiants; i++)
{
somme+=notes[i];
}
double moyenne = somme / nombreEtudiants;

//7. calcul de l'ecarttype
double sommecarres =0.0;
for(int i=0 ; i < nombreEtudiants; i++){
    double difference  = notes[i] - moyenne;
    sommecarres += difference * difference;
}
double variance = sommecarres / nombreEtudiants;
double ecarttype = std::sqrt(variance);

 //8.calculs des admis 

int nombreadmis = 0;
for(int i=0; i< nombreEtudiants; i++){
    if(notes[i]>=10){
        nombreadmis++;
    }
}
double pourcentageadmis = (static_cast<double>(nombreadmis) / nombreEtudiants)* 100;
 // 9. classement des mentions 
  int mentions[5]{};

  for (int i =0; i< nombreEtudiants; i++){
    Mention mention;
    if(notes[i]<10){
        mention = Mention::ajourne;
        mentions[0]++;
    }
    else if (notes[i] < 12)
 {
        mention = Mention::passable;
        mentions[1]++;
}
   
    else if (notes[i] < 14){
        mention=Mention::assezbien;
        mentions[2]++;
    }
    else if (notes[i]< 16){
        mention=Mention::bien;
        mentions[3]++;
    }
    else {
        mention=Mention::tresbien;
        mentions[4]++;
    }

  }
  //10. affichage des resultats 
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "\n===== resultats ====\n";
  std::cout <<"UE:" << ue <<'\n';
  std::cout << "nombre d'etudiants:" << nombreEtudiants <<'\n';
  std::cout << "Note minimale :" <<  minimum <<'\n';
  std::cout << " Note maximale :" << maximum <<'\n';
  std::cout << " moyenne :" << moyenne << '\n';
std::cout << " ecarttype:" << ecarttype << '\n';
std::cout << "nombre d'admis :" << nombreadmis << '\n';
std::cout  << "pourcentage d'admis :" << pourcentageadmis <<'\n';

 //11. histogramme

std::string nomsmentions[5] = {
    "ajourne",
    "passable",
    "assezbien",
    "bien",
    "tresbien"
};
std::cout << "\n ==== histogramme ====\n";
for(int i = 0; i< 5;i++){
    std::cout <<nomsmentions[i] << ":";
    for (int j=0; j< mentions[i]; j++){
        std::cout <<"*";
    }
    std::cout << "("<<mentions[i] <<")\n";
}
return 0;
 }

