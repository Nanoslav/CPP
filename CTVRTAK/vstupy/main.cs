using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Datový proudy na vstupech");
        Console.WriteLine();

        Console.Write("Zdej libovolny text: ");
        string text = Console.ReadLine();

        Console.WriteLine("toto je zadany text: {0}", text);

        Console.Write("zadej 1.cislo: ");
        int cislo1 = int.Parse(Console.ReadLine());
        Console.Write("zadej 2.cislo: ");
        int cislo2 = int.Parse(Console.ReadLine());

        Console.WriteLine($"{cislo1} + {cislo2} = {cislo1 + cislo2}");

        Console.ReadKey();
    }


}