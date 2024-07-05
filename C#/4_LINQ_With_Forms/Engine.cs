using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace lab9
{
    public class Engine : IComparable
    {
        public double displacement { get; set; }
        public double horsePower { get; set; }
        public string model { get; set; }

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

        public int CompareTo(object? obj)
        {
            Engine? engine = obj as Engine;
            if (engine != null)
            {
                double hpDiff = this.horsePower - engine.horsePower;
                if (hpDiff != 0) { return (int)(hpDiff / Math.Abs(hpDiff)); }

                int modelDiff = this.model.CompareTo(engine.model);
                if (modelDiff != 0) { return modelDiff; }

                return horsePower.CompareTo(engine.horsePower);
            }
            throw new ArgumentException("Not an engine");
        }
    }
}
