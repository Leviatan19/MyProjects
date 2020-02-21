///Powyższy kod został napisany w wyniku procesu nauczania na uczelni Polsko-Japońskiej Akademii Technik Komputerowych

public class Computers {
    public static void main(String[] args) {
        CalculatingMachine[] arr = { ///tablica, która przechowuje elementy CalculatingMachine lub dziedziczące po CalculatingMachine
                new Computer("Quantum_Computer"),
                new CalculatingMachine("First_Machine"),
                new Calculator("Small_Machine")
        };
        CalculatingMachine.printRes(arr, 21, 7);
    }
}
/* wynik programu:
Quantum_Computer: 21.0 + 7.0 = 28.0; 21.0 - 7.0 = 14.0; 21.0 * 7.0 = 147.0; 21.0 / 7.0 = 3.0
First_Machine: 21.0 + 7.0 = 28.0
Small_Machine: 21.0 + 7.0 = 28.0; 21.0 - 7.0 = 14.0
 */
///aby skompilować i uruchomić kod, należy użyć Java 8