using System;

class Program {

	static void Main()
    {

        bool success = false;

        do
        {

            Console.Clear();

            Console.WriteLine("10 příkladů na sčítání malých čísel od 1 do 5 včetně");
            Console.WriteLine("==============================================================");
            Console.WriteLine("");

            Random random = new Random();

            int[] numbers1 = new int[10];
            int[] numbers2 = new int[10];
            int[] vysledek = new int[10];

            for (int i = 0; i < numbers1.Length; i++)
            {
                numbers1[i] = random.Next(1, 6);
                numbers2[i] = random.Next(1, 6);
            }

            for (int i = 0; i < numbers1.Length; i++)
            {
                Console.Write(i + 1 + ". příklad: " + numbers1[i] + " + " + numbers2[i] + " = ");
                int odpoved = int.Parse(Console.ReadLine());
                vysledek[i] = odpoved;
            }

            Console.WriteLine("				Shrnutí testu");
            Console.WriteLine("=============================================================");

            int chyby = 0;

            for (int i = 0; i < numbers1.Length; i++)
            {
                Console.Write(numbers1[i] + " + " + numbers2[i] + " = " + vysledek[i] + " ");
                if (numbers1[i] + numbers2[i] != vysledek[i])
                {
                    chyby++;
                    Console.Write(" => Chyba výpočtu: počet chyb: " + chyby);
                }
                Console.WriteLine();
            }

            Console.WriteLine("=============================================================");

            if (chyby >= 5)
            {
                Console.WriteLine("Dosáhl jsi většího počtu chyb než 5, program se bude opakovat...");
            }
            else
            {
                Console.WriteLine("Uspěl si v testu sčítání, počet chyb: " + chyby + "/" + "5");
                success = true;
            }

            Console.ReadKey();

        } while (success == false);
    }

}