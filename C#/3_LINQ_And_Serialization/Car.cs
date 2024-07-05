using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace lab9
{
    [XmlType("car")]
    public class Car
    {
        public string model;
        public int year;
        [XmlElement("engine")]
        public Engine motor;
        
        public Car(string model, Engine engine, int year)
        {
            this.model = model;
            this.year = year;
            this.motor = engine;
        }

        public Car()
        {
            this.model = "";
            this.year = 0;
            this.motor = new Engine();
        }

        override public string ToString()
        {
            return $"{{Model: {model}, Motor: {motor}, Year: {year}}}";
        }
    }
}
