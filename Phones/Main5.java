///Powyższy kod został napisany w wyniku procesu nauczania na uczelni Polsko-Japońskiej Akademii Technik Komputerowych

import java.io.FileNotFoundException; ///importowanie potrzebnych bibliotek
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main5 {
    public static void main(String[] args) {
        try {												/// obsługa błędu braku pliku
            FileReader fr = new FileReader("telFormat.txt");/// zmienna plikowa dla pliku zawierającego numery telefonów
            StringBuilder sb = new StringBuilder();			/// zmienna tekstowa, w której będą zawarte numery telefonów
            try {											/// obsługa błedu wejścia-wyjścia
                int tmp = fr.read();						/// wczytanie pierwszego znaku do zmiennej
                while(tmp != -1){							/// wczytywanie, do momentu osiągnięcia końca pliku
                    sb.append((char) tmp);					/// dodawanie do zmiennej sb kolejnych znaków
                    tmp = fr.read();						/// wczywanie następnego znaku
                }
                Pattern p = Pattern.compile("(\\+\\d{1,2})?(\\(\\.\\)|\\(\\d{1,2}\\))?\\d{1,4}[-_ ]?\\d{1,3}[-_ ]?\\d{1,3}");
															/// wyrażenie regularne, które wypisuje wszystkie możliwe konfiguracje numerów telefonów
															/// zawierające z przodu +48, kropkę w nawiasach lub numer kierunkowy w nawiasach
															/// kombinacje cyfr, pomiędzy którymi jest spacja, _ lub -
                
				Matcher m = p.matcher(sb);					/// znalezienie pasującego wyrażenia 
                while(m.find()){
                    System.out.println(m.group());			/// wypisanie pasujących wyrażeń na ekran

                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }
}

