using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("test");
        Console.WriteLine();
        Console.Write("ČČŠŠŘŽÝÁÝŽŘČŠĚ");
        Console.WriteLine("další text");

        Console.WriteLine();
        Console.WriteLine();
        Console.WriteLine();
        Console.WriteLine("===============================");
        int age = 18;
        string name = "Petr";
        int poradi = 1;

        Console.WriteLine("{2}. osoba: Jmeno: {0}, vek: {1}", name, age, poradi);
        poradi++;
        Console.WriteLine($"{poradi}. osoba: Jmeno: {name}, vek: {age}");

        Console.BackgroundColor = ConsoleColor.Red;
        Console.WriteLine("Pro ukonceni programu stisknete libovolnou klavesu...");
        Console.ReadKey();
    }
}