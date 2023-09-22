using System;

class Program
{
    static void Main()
    {
        #region Pole
        Console.Write("Zadej pocet cisel: ");
        int pocet = int.Parse(Console.ReadLine());

        int[] numbers = new int[pocet];

        for (int i = 0; i < numbers.Length; i++)
        {
            numbers[i] = i;
        }

        for (int i = 0; i < numbers.Length; i++)
        {
            Console.Write(numbers[i] + " ");
        }
        Console.WriteLine();
        //==================================================================
        //---------------------------- for each ----------------------------
        //==================================================================
        foreach (int number in numbers)
        {
            Console.Write(number + " ");
        }
        Console.WriteLine();
        //==================================================================
        #endregion

        Random random = new Random();

        for (int i = 0; i < numbers.Length; i++)
        {
            numbers[i] = random.Next(1, 11);
        }

        Console.WriteLine();
        //==================================================================
        //---------------------------- for each ----------------------------
        //==================================================================
        Console.WriteLine("Nahodne cisla:");
        foreach (int number in numbers)
        {
            Console.Write(number + " ");
        }

        //==================================================================
        //---------------------------- Test --------------------------------
        //==================================================================
        Console.WriteLine("Zadej pocet prikladu: ");
        int pocetPrikladu = int.Parse(Console.ReadLine());

        int[] numbers1 = new int[pocetPrikladu];
        int[] numbers2 = new int[pocetPrikladu];

        for (int i = 0; i < numbers1.Length; i++)
        {
            numbers1[i] = random.Next(1, 11);
            numbers2[i] = random.Next(1, 11);
        }

        int score = 0;

        for (int i = 0; i < numbers1.Length; i++)
        {

            Console.WriteLine(numbers1[i] + " + " + numbers2[i]);
            int vysledek = int.Parse(Console.ReadLine());
            if(vysledek == (numbers1[i] + numbers2[i]))
            {
                Console.WriteLine("Spravne");
                score++;
            }
            else
            {
                Console.WriteLine("Spatne");
                Console.WriteLine("Spravne je: " + (numbers1[i] + numbers2[i]));
            }
        }

        Console.WriteLine("Tvoje skore je: " + score + "/" + numbers1.Length);

        Console.ReadKey();
    }
}