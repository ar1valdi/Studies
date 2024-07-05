using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace lab9
{
    public class Car : INotifyPropertyChanged 
    {
        private string _model;
        public string model
        {
            get { return _model; }
            set
            {
                if (_model != value)
                {
                    _model = value;
                    PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("model"));
                }
            }
        }

        private int _year;
        public int year
        {
            get { return _year; }
            set
            {
                if (_year != value)
                {
                    _year = value;
                    PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("year"));
                }
            }
        }

        private Engine _motor;
        public Engine motor
        {
            get { return _motor; }
            set
            {
                if (_motor != value)
                {
                    _motor = value;
                    PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("motor"));
                }
            }
        }

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

        public event PropertyChangedEventHandler? PropertyChanged;

        override public string ToString()
        {
            return $"{{Model: {model}, Motor: {motor}, Year: {year}}}";
        }
    }
}
