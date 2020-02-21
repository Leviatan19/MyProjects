///Powyższy kod został napisany w wyniku procesu nauczania na uczelni Polsko-Japońskiej Akademii Technik Komputerowych
///tworzenie pierwszej klasy
public class CalculatingMachine {
    String nazwa;

    public CalculatingMachine(String nazwa) {
        this.nazwa = nazwa; /// konstruktor domyslny, nadający maszynie nazwę
    }

    public String calculate(double x, double y) {	/// metoda, która dodaje do siebie wartości x i y i zwraca tekst, na końcu którego jest wynik działania
        double wynik = x + y;
        return nazwa + ": " + x + " + " + y + " = " + wynik;
    }

    public static void printRes(CalculatingMachine[] a, double x, double y) { /// metoda, która wypisuje rezultat działania dla wszystkich maszyn kalkulacyjnych w tablicy
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i].calculate(x, y));
        }
    }

}
