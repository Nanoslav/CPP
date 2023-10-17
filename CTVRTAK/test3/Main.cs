using System;
using Metody;

class Program
{
    static void Main()
    {
        Console.WriteLine("Program Bytovy dům");
        Mistnost[] mistnosti = Vlastnosti.NaplnMistnosti();
        Console.WriteLine("Plocha vsech mistnosti je " + Vlastnosti.Plocha(mistnosti));
        Console.ReadLine();
    }
}