using System;

class Program
{
    static void Main()
    {

        Console.Write("Zadej svůj věk: ");
        int vek = int.Parse(Console.ReadLine());

        if(vek >= 18)
        {
            Console.WriteLine("Jsi plnoletý");
        }
        else if (vek >= 1)
        {
            Console.WriteLine("Nejsi plnoletý");
        }
        else
        {
            Console.WriteLine("Chyba v metrixu");
        }
        //----------------------------------

        if(!(vek < 15 || vek > 19))
        {
            Console.WriteLine("Jsi žákem střední školy");
        }

        //----------------------------------

        Console.Write("Zadej hodnotu 1-3: ");
        int hodnota = int.Parse(Console.ReadLine());

        switch (hodnota)
        {
            case 1:
                Console.WriteLine("jedna");
                break;
            case 2:
                Console.WriteLine("dva");
                break;
            case 3:
                Console.WriteLine("tři");
                break;
        }

        //----------------------------------
        Console.Write("Zadej hodnotu ano/ne: ");
        string odpoved = Console.ReadLine();

        switch (odpoved)
        {
            case "ano":
            case "Ano":
            case "ANO":
                Console.WriteLine("Ano");
                break;
            case "ne":
            case "Ne":
            case "NE":
                Console.WriteLine("Ne");
                break;
            default:
                Console.WriteLine("Neznámá hodnota");
                break;
        }

        Console.ReadKey();
    }
}