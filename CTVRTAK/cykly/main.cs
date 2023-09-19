using System;

class Program
{
    static void Main()
    {
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                Console.Write(i * j + " ");
            }
            Console.WriteLine();
        }
        //--------------------------------------------------------------
        int cislo = 0;
        while (cislo < 10)
        {
            Console.WriteLine(cislo);
            cislo++;
        }
        Console.WriteLine();
        //--------------------------------------------------------------
        for(int i = 0; i < 10; i++)
        {
            if (i == 5)
            {
                //break;
                continue;
            }
            Console.WriteLine(i + " ");
        }
        //--------------------------------------------------------------
        Console.Write("Zadej hodnotu 1-5: ");
        int hodnota = int.Parse(Console.ReadLine());

        while(hodnota < 1 || hodnota > 5)
        {
            Console.Write("Zadej hodnotu 1-5: ");
            hodnota = int.Parse(Console.ReadLine());
        }
        Console.WriteLine("Znamka je: {0}", hodnota);

        //--------------------------------------------------------------
        int hodnota2;
        do
        {
            Console.Clear();
            Console.Write("Zadej hodnotu 1-5: ");
            hodnota2 = int.Parse(Console.ReadLine());
        } while (hodnota2 < 1 || hodnota2 > 5);
        Console.WriteLine("Znamka je: {0}", hodnota2);

        Console.ReadKey();
    }
}