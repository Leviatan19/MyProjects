///Powyższy kod został napisany w wyniku procesu nauczania na uczelni Polsko-Japońskiej Akademii Technik Komputerowych
///klasa, która dziedziczy po klasie CalculatingMachine
public
class Calculator extends CalculatingMachine {
    public Calculator(String nazwa) {
        super(nazwa);	///konstruktor, który odwołuje się do konstruktora domyślnego klasy CalculatingMachine
    }

    public String calculate(double x, double y) {	///metoda, która odwołuje się do metody super.calculate, oraz wykonuje dodatkowo odejmowanie i zwraca odejmowanie wraz z wynikiem
        String wynik = super.calculate(x, y);
        return wynik + "; " + x + " - " + y + " = " + (x - y);

    }
}
