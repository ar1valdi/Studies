using lab9;
using System.Linq;
using System.Xml.Linq;
using System.Xml.Serialization;
using System.Xml.XPath;

class Program
{
    public static List<Car>? myCars;
    static void Main(string[] args)
    {
        myCars = new List<Car>(){
         new Car("E250", new Engine(1.8, 204, "CGI"), 2009),
         new Car("E350", new Engine(3.5, 292, "CGI"), 2009),
         new Car("A6", new Engine(2.5, 187, "FSI"), 2012),
         new Car("A6", new Engine(2.8, 220, "FSI"), 2012),
         new Car("A6", new Engine(3.0, 295, "TFSI"), 2012),
         new Car("A6", new Engine(2.0, 175, "TDI"), 2011),
         new Car("A6", new Engine(3.0, 309, "TDI"), 2011),
         new Car("S6", new Engine(4.0, 414, "TFSI"), 2012),
         new Car("S8", new Engine(4.0, 513, "TFSI"), 2012)
        };
        zad_1();
        zad_2();
        zad_3();
        zad_4();
        zad_5();
        zad_6();
    }
    static void zad_6()
    {
        XElement xmlDoc = XElement.Load("cars.xml");
        foreach(XElement e in xmlDoc.Descendants("horsePower"))
        {
            e.Name = "hp";
        }
        foreach (XElement e in xmlDoc.Descendants("car"))
        {
            XElement yearElement = e.Element("year");
            if (yearElement != null)
            {
                string yearValue = yearElement.Value;
                XElement modelElement = e.Element("model");
                modelElement.Add(new XAttribute("year", yearValue));
                yearElement.Remove();
            }
        }
        xmlDoc.Save("cars2.xml");
    }
    static void zad_5()
    {
        XDocument xhtmlTemplate = XDocument.Load("template.html");
        XElement table = new XElement("table",
            new XElement("tr",
                new XElement("th", "Model"),
                new XElement("th", "Year"),
                new XElement("th", "Engine Displacement"),
                new XElement("th", "Horsepower"),
                new XElement("th", "Engine Model")
            ),
            from car in myCars
            select new XElement("tr",
                new XElement("td", car.model),
                new XElement("td", car.year),
                new XElement("td", car.motor.displacement),
                new XElement("td", car.motor.horsePower),
                new XElement("td", car.motor.model)
                )
            );
        xhtmlTemplate.Root.Element("body").Add(table);
        xhtmlTemplate.Save("CarsTable.html");
    }
    static void zad_4()
    {
        createXmlFromLinq();
    }
    static private void createXmlFromLinq()
    {
        IEnumerable<XElement> nodes =   from car in myCars
                                        select new XElement("car",
                                        new XElement("model", car.model),
                                        new XElement("year", car.year),
                                        new XElement("engine",
                                            new XElement("displacement", car.motor.displacement),
                                            new XElement("horsePower", car.motor.horsePower),
                                            new XAttribute("model", car.motor.model)
                                            )
                                        );
        XElement rootNode = new XElement("cars", nodes); // stwórz węzeł zawierający wyniki zapytania
        rootNode.Save("CarsFromLinq.xml");
    }
    static void zad_3()
    {
        XElement rootNode = XElement.Load("cars.xml");
        double avgHP = (double)rootNode.XPathEvaluate("sum(/car/engine[not(@model = 'TDI')]/horsePower) div count(/car/engine[not(@model = 'TDI')]/horsePower)");
        Console.WriteLine(avgHP);

        IEnumerable<XElement> models = rootNode.XPathSelectElements("/car/model[not(. = preceding::model)]");
        foreach (XElement model in models)
        {
            Console.WriteLine(model);
        }
    }
    static void zad_2()
    {
        XmlSerializer serializer = new XmlSerializer(typeof(List<Car>), new XmlRootAttribute("cars"));
        using (TextWriter writer = new StreamWriter("cars.xml"))
        {
            serializer.Serialize(writer, myCars);
        }


        using (TextReader reader = new StreamReader("cars.xml"))
        {
            List<Car> deserialized = (List<Car>)serializer.Deserialize(reader)!;
            foreach (Car c in deserialized)
            {
                Console.WriteLine(c);
            }
        }

    }
    static void zad_1()
    {
        var query = from car in myCars
                    where car.model == "A6"
                    select new
                    {
                        engineType = car.motor.model == "TDI" ? "diesel" : "petrol",
                        hppl = car.motor.horsePower / car.motor.displacement
                    };

        foreach (var result in query)
        {
            Console.WriteLine(result);
        }

        Console.WriteLine("\n");

        var query2 = from v1 in query
                     group v1 by v1.engineType into grouped
                     select new
                     {
                         EngineType = grouped.Key,
                         Hppl = grouped.Average(item => item.hppl)
                     };

        foreach (var result in query2)
        {
            Console.WriteLine(result);
        }
    }
}
