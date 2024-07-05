using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace lab9
{
    public class Engine
    {
        public double displacement;
        public double horsePower;
        [XmlAttribute("model")]
        public string model;

        public Engine(double displacement, double horsePower, string model)
        {
            this.displacement = displacement;
            this.horsePower = horsePower;
            this.model = model;
        }
        public Engine()
        {
            displacement = 0;
            horsePower = 0;
            model = "";
        }
        override public string ToString()
        {
            return $"{{Model: {model}, HorsePower: {horsePower}, Displacement: {displacement}}}";
        }
    }
}
