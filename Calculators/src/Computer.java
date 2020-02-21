///Powyższy kod został napisany w wyniku procesu nauczania na uczelni Polsko-Japońskiej Akademii Technik Komputerowych
///klasa, która dziedziczy po klasie Calculator
public class Computer extends Calculator {
    public Computer(String nazwa) {
        super(nazwa); ///konstruktor, który odwołuje się do konstruktora domyślnego klasy Calculator
    }

    public String calculate(double x, double y) { ///metoda, która odwołuje się do metody super.calculate, oraz wykonuje dodatkowo mnozenie i dzielenie i zwraca mnozenie i dzielenie wraz z wynikiem
        String wynik = super.calculate(x, y);
        return wynik + "; " + x + " * " + y + " = " + (x * y) + "; " + x + " / " + y + " = " + (x / y);

    }
}
